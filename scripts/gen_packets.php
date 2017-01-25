<?php

const FIELD_TYPE_UINT8 	    = 'uint8_t';
const FIELD_TYPE_INT8 	    = 'int8_t';
const FIELD_TYPE_UINT16     = 'uint16_t';
const FIELD_TYPE_INT16 	    = 'int16_t';
const FIELD_TYPE_UINT32     = 'uint32_t';
const FIELD_TYPE_INT32      = 'int32_t';
const FIELD_TYPE_UINT64     = 'uint64_t';
const FIELD_TYPE_INT64      = 'int64_t';
const FIELD_TYPE_UARRAY     = 'uint8_t[]';
const FIELD_TYPE_ARRAY      = 'int8_t[]';
const FIELD_TYPE_VARIABLE   = 'variable';

$fieldSizes = [
	FIELD_TYPE_UINT8 	=> 1,
	FIELD_TYPE_INT8 	=> 1,
	FIELD_TYPE_UINT16   => 2,
	FIELD_TYPE_INT16 	=> 2,
	FIELD_TYPE_UINT32   => 4,
	FIELD_TYPE_INT32 	=> 4,
	FIELD_TYPE_UINT64   => 8,
	FIELD_TYPE_INT64 	=> 8,
	FIELD_TYPE_UARRAY   => -1,
	FIELD_TYPE_ARRAY 	=> -1,
];

$packets['sahara'] = [
	'SaharaHelloRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'remote',
		'fields'  => [
			'version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'min_version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_command_packet_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'status' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'reserved' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT32] * 6,
			],
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaHelloResponse' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'local',
		'fields'  => [
			'version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'min_version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_command_packet_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'status' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'reserved' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT32] * 6,
			],
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaReadDataRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'remote',
		'fields'  => [
			'image_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'offset' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],
	'SaharaReadDataResponse' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'Packet',
		'source'  => 'local',
		'fields'  => [
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],
	'SaharaEndImageTransferResponse' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'remote',
		'fields'  => [
			'image_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'status' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],
	'SaharaDoneRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'local',
		'fields'  => [],
	],
	'SaharaDoneResponse' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'remote',
		'fields'  => [],
	],
	'SaharaResetRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'local',
		'fields'  => [],
	],
	'SaharaResetResponse' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'remote',
		'fields'  => [],
	],
	'SaharaMemoryDebugRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'remote',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],
	'SaharaMemoryReadRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'local',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],
	'SaharaCommandReadyResponse' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'remote',
		'fields'  => [
			'image_tx_status' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaSwitchModeRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'local',
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaClientCommandRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'local',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaClientCommandResponse' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'remote',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaClientCommandExecuteDataRequest' => [
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'source'  => 'local',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
];


$packets['streaming_dload'] = [

];

$packets['qcdm'] = [

];

$packets['laf'] = [

];


foreach ($packets as $group => $pkts) {
	foreach ($pkts as $packet) {
		
	}
}