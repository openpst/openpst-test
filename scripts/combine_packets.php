<?php

require_once('vendor/autoload.php');
require_once('packet_defs.php');

use Symfony\Component\Finder\Finder;


define('BASE_DIR', dirname(__FILE__).'/../');
define('SRC_DIR', BASE_DIR.'/src');
define('INC_DIR', BASE_DIR.'/include');


$packets['include/qualcomm/sahara_packets.h'] 			= read_files(INC_DIR.'/qualcomm/packet', 'sahara_*', 'sahara_packet.h');
//$packets['src/qualcomm/sahara_packets.cpp']   			= read_files(SRC_DIR.'/qualcomm/packet', 'sahara_*', '');
$packets['include/qualcomm/streaming_dload_packets.h'] 	= read_files(INC_DIR.'/qualcomm/packet', 'streaming_dload_*', 'streaming_dload_packet.h');
//$packets['src/qualcomm/streaming_dload_packets.cpp'] 	= read_files(SRC_DIR.'/qualcomm/packet', 'streaming_dload_*', '');


foreach ($packets as $targetFile => $files) {
	if ($files[0] == 0xFF) {
		throw new \Exception("Could not find a starterFile for " . $targetFile);
	}

	//$combined = implode(PHP_EOL, $files);

	$outFile = sprintf('%s/%s', BASE_DIR, $targetFile);

	echo 'Outputting to ' . $outFile . ' - ' . $targetFile . PHP_EOL;

	//file_put_contents($outFile, $combined);
}

function read_files($dir, $prefix, $starterFile)
{
	$finder = new Finder();
	$files  = $finder->files()->name($prefix)->in($dir);

	if ($starterFile) {
		$ret = [0 => 0xFF];
	} else {
		$ret = [];
	}
	

	foreach ($files as $file) {
		if ($starterFile && $file->getFilename() == $starterFile) {
			$ret[0] = $file->getContents();
		} else {
			$ret[] = $file->getContents();
		}
	}

	return $ret;
}