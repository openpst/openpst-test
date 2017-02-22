<?php

require_once('vendor/autoload.php');
require_once('packet_defs.php');

// load twig
$twig = new \Twig_Environment(
	new \Twig_Loader_Filesystem(dirname(__FILE__).'/templates'), 
	[
    	'cache' => false,
	]
);

define('REAL_SRC_DIR', dirname(__FILE__).'/../src');
define('REAL_INC_DIR', dirname(__FILE__).'/../include');

$twig->addFilter(new \Twig_SimpleFilter('to_camel', 'to_camel'));
$twig->addFilter(new \Twig_SimpleFilter('to_lower_camel', 'to_lower_camel'));
$twig->addFilter(new \Twig_SimpleFilter('to_lower_name', 'to_lower_name'));


function to_camel($str)
{
	preg_match_all('/(_[a-zA-Z]{1})/', $str, $matches);
	if (isset($matches[0])) {
		foreach ($matches[0] as $match) {
			$str = str_replace($match, str_replace('_', '', strtoupper($match)), $str);
		}
	}
	$str[0] = strtoupper($str[0]);
	return $str;
}

function to_lower_camel($str)
{
	$str = to_camel($str);
	$str[0] = strtolower($str[0]);
	return $str;
}

function to_lower_name($str)
{
	preg_match_all('/([zA-Z]{1})/', $str, $matches);
	if (isset($matches[0])) {
		foreach ($matches[0] as $match) {
			$str = str_replace($match, sprintf('_%s', $match), $str);
		}
	}

	$str = preg_replace('/_{2,}/', '_', $str);

	if ($str[0] == '_') {
		$str = substr($str, 1, strlen($str));
	}

	return strtolower($str);
}

function extract_unpack_method($filePath) {
	$file = file_get_contents($filePath);

	if (!$file) {
		throw \Exception("File has nothing or doesnt exist");
	}

	$lines = explode(PHP_EOL, $file);

	$return = [];

	$hit = false;
	foreach ($lines as $line) {
		if (preg_match(sprintf('/%s/i', preg_quote('::unpack(std::vector<uint8_t>& data)')), $line)) {
			$hit = true;	
		}

		if ($hit) {
			$return[] = $line;
			if (preg_match('/^\}/', $line)) {
				break;
			}
		}
	}

	return implode(PHP_EOL, $return);
}
