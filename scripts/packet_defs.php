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
	FIELD_TYPE_UARRAY 	=> -1,
];

/**
* Sahara Packet Definitions
*/
$packets['sahara'] = [
	'SaharaHelloRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
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
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
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
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
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
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'Packet',
		'extends_namespace' => 'OpenPST::Serial',
		'source'  => 'local',
		'fields'  => [
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
				'allowed_setters' => ['file','raw','string'],
				'allowed_getters' => ['vector','string'],
			],
		]
	],
	'SaharaEndImageTransferResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
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
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [],
	],
	'SaharaDoneResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [],
	],
	'SaharaResetRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [],
	],
	'SaharaResetResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [],
	],
	'SaharaMemoryDebugRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
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
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
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
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'image_tx_status' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaSwitchModeRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaClientCommandRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
	'SaharaClientCommandResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
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
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],
];

/**
* Streaming DLOAD Packet Definitions
*/
$packets['streaming_dload'] = [
	'StreamingDloadHelloRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'magic' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 32,
				'size_const' => 'STREAMING_DLOAD_MAGIC_SIZE',
			],
			'version' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'compatible_version' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'feature_bits' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
		]
	],

	// TODO: Response has dynamic size fields..


	'StreamingDloadReadRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'length' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
		]
	],	
	'StreamingDloadReadResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],

	'StreamingDloadStreamWriteRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],	
	'StreamingDloadStreamWriteResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],


	'StreamingDloadNopRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'identifier' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],	
	'StreamingDloadNopResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'identifier' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],

	'StreamingDloadResetRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
		]
	],	
	'StreamingDloadResetResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
		]
	],
];

/**
* DM/DIAG/QCDM Packet Definitions
*/
$packets['qcdm'] = [
	'DmPhoneModeRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'padding' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
				'default' => '0x00'
			]
		]
	],
	'DmPhoneModeResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'status' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
		]
	],

	'DmSpcRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'spc' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 6,
				'size_const' => 'DIAG_SPC_LENGTH',
				'allowed_setters' => ['raw','string'],
				'allowed_getters' => ['vector','string'],
			],
		]
	],
	'DmSpcResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'status' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
		]
	],

	'DmPasswordRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'password' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 8,
				'size_const' => 'DIAG_PASSWORD_LENGTH',
				'allowed_setters' => ['raw','string'],
				'allowed_getters' => ['vector','string'],
			],
		]
	],
	
	'DmPasswordResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'status' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
		]
	],

	'DmNvReadRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'nv_item' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'data' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 128,
				'size_const' => 'DIAG_NV_ITEM_SIZE',
			],
		]
	],
	'DmNvReadResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'nv_item' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'data' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 128,
				'size_const' => 'DIAG_NV_ITEM_SIZE',
				'allowed_setters' => ['raw','string'],
				'allowed_getters' => ['vector','string'],
			],
		]
	],

	'DmVersionRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
			'version' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			]
		]
	],
	'DmVersionResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'demod' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'decode' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'interleaver_id' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'esn' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'rm_mode' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'min1' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT32] * 2,
				'allowed_setters' => ['raw','string'],
				'allowed_getters' => ['vector','string'],
			],
			'min2' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT32] * 2,
				'allowed_setters' => ['raw','string'],
				'allowed_getters' => ['vector','string'],
			],
			'min_index' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'cdma_rm_state' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'cdma_good_frames' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'analog_correct_frames' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'analog_bad_frames' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'analog_word_syncs' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'entry_reason' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'current_channel' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'cdma_code_channel' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'pilot_base' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'sid' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'nid' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'location_id' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'rssi_level' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'power' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
		]
	],

	'DmGuidRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [
		]
	],

	'DmGuidResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'guid' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT32] * 4,
				'allowed_setters' => ['raw','string'],
				'allowed_getters' => ['vector','string'],
			],
		]
	],
];

/**
* DLOAD Packet Definitions
*/
$packets['dload'] = [

];

/**
* LG LAF Packet Definitions
*/
$packets['laf'] = [

];