<?php

require_once('loader.php');

if (!defined('REAL_SRC_DIR')) {
	define('REAL_SRC_DIR', dirname(__FILE__).'/../src');
}
if (!defined('REAL_INC_DIR')) {
	define('REAL_INC_DIR', dirname(__FILE__).'/../include');
}

$out_dir = dirname(__FILE__).'/out';

echo "STARTING...".PHP_EOL;

if (!is_dir($out_dir)) {
	mkdir($out_dir, 0755, true);
}

$src_dir = sprintf('%s/src', $out_dir);
$inc_dir = sprintf('%s/include', $out_dir);

// genereate

$excludeUnpackReplace = explode(PHP_EOL, file_get_contents(dirname(__FILE__).'/.ignore_unpack_replace'));

foreach ($packets as $group => $pkts) {
	foreach ($pkts as $name => $packet) {
		if (isset($packet['skip'])) {
			continue;
		}

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
		
		/*if (isset($pkts[$packet['extends']])) {
			echo $name.' - '. $pkts[$packet['extends']]['path'] . PHP_EOL;
		}continue;*/

		$packet['file_name'] 				= to_lower_name($name);
		$packet['extends_path'] 			= isset($pkts[$packet['extends']]) ? $pkts[$packet['extends']]['path'] : 'transport';
		$packet['extends_header_filename']	= to_lower_name($packet['extends']);
		$packet['extends_class_namespace']	= $packet['extends_namespace'];
		$packet['extends_class_name']		= $packet['extends'];
		$packet['namespace']				= $packet['namespace'];
		$packet['class_name']				= $name;
		$packet['default_exends'] 			= isset($packet['default_exends']) && is_array($packet['default_exends']) ? $packet['default_exends'] : array();
		
		if (isset($packet['expects_response']) && $packet['expects_response']) {
			if (!isset($pkts[$packet['expects_response']])) {

			}
			$packet['response_path'] = $pkts[$packet['expects_response']]['path'];
			$packet['response_header_filename'] = to_lower_name($packet['expects_response']);
			$packet['response_class_namespace'] = $pkts[$packet['expects_response']]['namespace'];
			$packet['response_class_name'] = $packet['expects_response'];
		}

		$packet['all_fields_primitive'] = true;

		foreach ($packet['fields'] as $fname => &$field) {
			$field['name'] 				= $fname;
			$field['name_camel']  	  	= to_camel($fname);
			$field['name_lower_camel']  = to_lower_camel($fname);

			if ($field['type'] == FIELD_TYPE_VARIABLE) {
				$packet['all_fields_primitive'] = false;
			}
		}

		$realSrcFile = sprintf('%s/%s/%s.cpp', REAL_SRC_DIR, $packet['path'], to_lower_name($name));
		
		if (file_exists($realSrcFile) && in_array($name, $excludeUnpackReplace)) {
			$cust = extract_unpack_method($realSrcFile);
			if (trim($cust)) {
				$packet['unpacked_custom'] = $cust;
			}
		}

		$header = $twig->render('packet_header.twig', $packet);
		$source = $twig->render('packet_source.twig', $packet);

		$header = preg_replace('/\n{3,}/', "\n\n", $header);
		$source = preg_replace('/\n{3,}/', "\n\n", $source);

		file_put_contents(sprintf('%s/%s.h', $file_inc_dir, to_lower_name($name)), $header);
		file_put_contents(sprintf('%s/%s.cpp', $file_src_dir, to_lower_name($name)), $source);
	}
}
