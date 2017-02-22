<?php

require_once('loader.php');

use Symfony\Component\Finder\Finder;


define('BASE_DIR', dirname(__FILE__).'/../');
define('SRC_DIR', BASE_DIR.'/src');
define('INC_DIR', BASE_DIR.'/include');

$foundPackets['qualcomm/sahara_packets.h'] 		    = read_files(INC_DIR.'/qualcomm/packet', 'sahara_*', 		   'sahara_packet.h'			, 'qualcomm/packet', null);
$foundPackets['qualcomm/streaming_dload_packets.h'] = read_files(INC_DIR.'/qualcomm/packet', 'streaming_dload_*', 'streaming_dload_packet.h'	, 'qualcomm/packet', null);
$foundPackets['qualcomm/dm_packets.h'] 				= read_files(INC_DIR.'/qualcomm/packet', 'dm_*', 'dm_packet.h'	, 'qualcomm/packet', 'dm_efs_*');
$foundPackets['qualcomm/dm_efs_packets.h'] 			= read_files(INC_DIR.'/qualcomm/packet', 'dm_efs_*', 'dm_efs_packet.h'	, 'qualcomm/packet', '');

foreach ($foundPackets as $targetFile => $files) {
	if ($files[0] == 0xFF) {
		throw new \Exception("Could not find a starterFile for " . $targetFile);
	}

	//$combined = implode(PHP_EOL, $files);
	$header = $twig->render('packet_group_loader.twig', array(
		'files' => $files,
		'file_name' => @end(explode('/', $targetFile)),
		'description' => ''
	));

	$outFile = sprintf('%s/include/%s',BASE_DIR, $targetFile);

	file_put_contents($outFile, $header);
}

function read_files($dir, $prefix, $starterFile, $endNamePrefix, $notFiles)
{
	$finder = new Finder();
	$files  = $finder->files()->name($prefix);

	if ($notFiles) {
		$files->notName($notFiles);
	}

	$files = $files->in($dir);

	if ($starterFile) {
		$ret = [0 => 0xFF];
	} else {
		$ret = [];
	}
	
	foreach ($files as $file) {
		if ($starterFile && $file->getFilename() == $starterFile) {
			$ret[0] = sprintf('%s/%s', $endNamePrefix, $file->getFilename());
		} else {
			$ret[] = sprintf('%s/%s', $endNamePrefix, $file->getFilename());
		}
	}

	return $ret;
}