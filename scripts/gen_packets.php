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


$twig->addFilter(new \Twig_SimpleFilter('to_camel', 'to_camel'));
$twig->addFilter(new \Twig_SimpleFilter('to_lower_camel', 'to_lower_camel'));
$twig->addFilter(new \Twig_SimpleFilter('to_lower_name', 'to_lower_name'));

$out_dir = dirname(__FILE__).'/out';

if (!is_dir($out_dir)) {
	mkdir($out_dir, 0755, true);
}

$src_dir = sprintf('%s/src', $out_dir);
$inc_dir = sprintf('%s/include', $out_dir);

// genereate

foreach ($packets as $group => $pkts) {
	foreach ($pkts as $name => $packet) {
		$file_src_dir = sprintf('%s/%s', $src_dir, $packet['path']);
		$file_inc_dir = sprintf('%s/%s', $inc_dir, $packet['path']);

		if (!is_dir($file_src_dir)) {
			echo 'Creating ' . $file_src_dir.PHP_EOL;
			mkdir($file_src_dir, 0755, true);
		}

		if (!is_dir($file_inc_dir)) {
			echo 'Creating ' . $file_inc_dir.PHP_EOL;
			mkdir($file_inc_dir, 0755, true);
		}

		$data = [
			'packet' 					=> $packet,
			'extends_path'				=> isset($pkts[$packet['extends']]) ? $pkts[$packet['extends']]['path'] : 'serial',
			'extends_header_filename'	=> sprintf('%s', to_lower_name($name)),
			'extends_class_namespace'	=> $packet['extends_namespace'],
			'extends_class_name'		=> $packet['extends'],
			'namespace'					=> $packet['namespace'],
			'class_name'				=> $name,
			'fields'					=> isset($packet['fields']) ? $packet['fields'] : [],
		];

		foreach ($data['fields'] as $fname => &$field) {
			$field['field_type'] 		= $field['type'];
			$field['field_size'] 		= $field['size'];
			$field['field_name'] 		= $fname;
			$field['field_name_camel']  = to_camel($fname);
			$field['field_name_lower_camel']  = to_lower_camel($fname);
		}

		$header = $twig->render('packet_header.twig', $data);
		$source = $twig->render('packet_source.twig', $data);

		file_put_contents(sprintf('%s/%s.h', $file_inc_dir, to_lower_name($name)), $header);
		file_put_contents(sprintf('%s/%s.cpp', $file_src_dir, to_lower_name($name)), $source);
	}
}

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