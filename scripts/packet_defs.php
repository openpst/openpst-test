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
	'SaharaPacket' => [
		'skip' => true,
		'path' => 'qualcomm/packet'
	],
	'SaharaHelloRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => 'SaharaHelloResponse',
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
		],
		'default_exends' => [
			'command' => 'kSaharaCommandHello'
		]
	],
	'SaharaHelloResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
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
		],
		'default_exends' => [
			'command' => 'kSaharaCommandHelloResponse'
		]
	],
	'SaharaReadDataRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => 'SaharaReadDataResponse',
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
		'extends_namespace' => 'OpenPST::Transport',
		'source'  => 'local',
		'expects_response' => '',
		'fields'  => [
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
				'allowed_setters' => ['file','raw','string'],
				'allowed_getters' => ['vector','string'],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandReadData'
		]
	],
	'SaharaEndImageTransferResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'fields'  => [
			'image_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'status' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'command' => 'kSaharaCommandEndImageTransfer'
		]
	],
	'SaharaDoneRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [],
		'expects_response' => 'SaharaDoneResponse',
		'default_exends' => [
			'command' => 'kSaharaCommandDone'
		]
	],
	'SaharaDoneResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [],
		'expects_response' => '',
		'default_exends' => [
			'command' => 'kSaharaCommandDoneResponse'
		]
	],
	'SaharaResetRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'fields'  => [],
		'expects_response' => 'SaharaResetResponse',
		'default_exends' => [
			'command' => 'kSaharaCommandReset'
		]
	],
	'SaharaResetResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [],
		'expects_response' => '',
		'default_exends' => [
			'command' => 'kSaharaCommandResetResponse'
		]
	],
	'SaharaMemoryDebugRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => 'SaharaMemoryReadRequest',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'command' => 'kSaharaCommandMemoryDebug'
		]
	],
	'SaharaMemoryReadRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'command' => 'kSaharaCommandMemoryRead'
		]
	],
	'SaharaCommandReadyResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'fields'  => [
			'image_tx_status' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandReady'
		]
	],
	'SaharaSwitchModeRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandSwitchMode'
		]
	],
	'SaharaClientCommandRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandExecute'
		]
	],
	'SaharaClientCommandResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandExecuteResponse'
		]
	],
	'SaharaClientCommandExecuteDataRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandExecuteData'
		]
	],
	'SaharaMemoryDebug64Request' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'command' => 'kSaharaCommandMemoryDebug64Request'
		]
	],
	'SaharaMemoryRead64Request' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT64,
				'size' => $fieldSizes[FIELD_TYPE_UINT64],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT64,
				'size' => $fieldSizes[FIELD_TYPE_UINT64],
			]
		],
		'default_exends' => [
			'command' => 'kSaharaCommandMemoryDebug64'
		]
	],
	'SaharaCommandMemoryDebug64Request' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT64,
				'size' => $fieldSizes[FIELD_TYPE_UINT64],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandMemoryRead64'
		]
	],
];

/**
* Streaming DLOAD Packet Definitions
*/
$packets['streaming_dload'] = [
	'StreamingDloadPacket' => [
		'skip' => true,
		'path' => 'qualcomm/packet'
	],
	'StreamingDloadHelloRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadHelloResponse',
		'unpack_base' => true,
		'fields'  => [
			'magic' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 32,
				'size_const' => 'STREAMING_DLOAD_MAGIC_SIZE',
				'default_string' => 'QCOM fast download protocol host',
				'allowed_getters' => ['string'],
				'allowed_setters' => ['string'],
			],
			'version' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
				'default' => '0x05',
			],
			'compatible_version' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
				'default' => '0x02',
			],
			'feature_bits' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
				'default' => '0x19',
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadHello'
		]
	],
	// TODO: Response has dynamic size fields..
	// kStreamingDloadHelloResponse
	'StreamingDloadHelloResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'magic' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 32,
				'size_const' => 'STREAMING_DLOAD_MAGIC_SIZE',
				'allowed_getters' => [ 'string' ],
			],
			'version' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'compatible_version' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'preferred_block_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'base_flash_address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'flash_id_length' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'flash_id' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
				'allowed_getters' => [ 'string' ],
			],
			'window_size' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'number_of_sectors' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'sector_sizes' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
			'feature_bits' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadHelloResponse'
		]
	],


	'StreamingDloadReadRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadReadResponse',
		'unpack_base' => true,
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'length' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadRead'
		]
	],	
	'StreamingDloadReadResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
				'allowed_setters' => ['raw'],
				'allowed_getters' => ['vector'],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadReadData'
		]
	],

	'StreamingDloadStreamWriteRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadStreamWriteResponse',
		'unpack_base' => true,
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
				'allowed_setters' => ['file','raw','string'],
				'allowed_getters' => ['vector'],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadStreamWrite'
		]
	],	
	'StreamingDloadStreamWriteResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadBlockWritten'
		]
	],


	'StreamingDloadNopRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadNopResponse',
		'unpack_base' => true,
		'fields'  => [
			'identifier' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadNop'
		]
	],	
	'StreamingDloadNopResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'identifier' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadNopResponse'
		]
	],

	'StreamingDloadResetRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadResetResponse',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadReset'
		]
	],	
	'StreamingDloadResetResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadResetAck'
		]
	],

	'StreamingDloadUnlockRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadUnlockResponse',
		'unpack_base' => true,
		'fields'  => [
			'code' => [ 
				'type' => FIELD_TYPE_UINT64,
				'size' => $fieldSizes[FIELD_TYPE_UINT64],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadUnlock'
		]
	],	
	'StreamingDloadUnlockResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadUnlocked'
		]
	],

	'StreamingDloadOpenRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadOpenResponse',
		'unpack_base' => true,
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadOpen'
		]
	],	
	'StreamingDloadOpenResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadOpened'
		]
	],


	'StreamingDloadCloseRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadCloseResponse',
		'unpack_base' => true,
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadClose'
		]
	],	
	'StreamingDloadCloseResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadClosed'
		]
	],

	'StreamingDloadSecurityModeRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadSecurityModeResponse',
		'unpack_base' => true,
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadSecurityMode'
		]
	],	
	'StreamingDloadSecurityModeResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadSecurityModeReceived'
		]
	],

	'StreamingDloadPartitionTableRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadPartitionTableResponse',
		'unpack_base' => true,
		'fields'  => [
			'override_existing' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'data' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 512,
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadPartitionTable'
		]
	],	
	'StreamingDloadPartitionTableResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'status' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadPartitionTableReceived'
		]
	],

	'StreamingDloadOpenMultiImageRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadOpenMultiImageResponse',
		'unpack_base' => true,
		'fields'  => [
			'type' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadOpenMultiImage'
		]
	],	

	'StreamingDloadOpenMultiImageWithPayloadRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadOpenMultiImageResponse',
		'unpack_base' => true,
		'fields'  => [
			'type' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'payload' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
				'allowed_setters' => ['file','raw','string'],
				'allowed_getters' => ['vector'],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadOpenMultiImage'
		]
	],	

	'StreamingDloadOpenMultiImageResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'status' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadOpenedMultiImage'
		]
	],

	'StreamingDloadEraseFlashRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadEraseFlashResponse',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadEraseFlash'
		]
	],	
	'StreamingDloadEraseFlashResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadFlashErased'
		]
	],

	'StreamingDloadGetEccStateRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadGetEccStateResponse',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadGetEccState'
		]
	],	
	'StreamingDloadGetEccStateResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'status' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadCurrentEccState'
		]
	],

	'StreamingDloadSetEccStateRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadSetEccStateResponse',
		'unpack_base' => true,
		'fields'  => [
			'status' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			]
		],
		'default_exends' => [
			'command' => 'kStreamingDloadSetEcc'
		]
	],	
	'StreamingDloadSetEccStateResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadSetEccResponse'
		]
	],

	'StreamingDloadUnframedStreamWriteRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadUnframedStreamWriteResponse',
		'unpack_base' => true,
		'fields'  => [
			'alignment_padding' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 3,
			],
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'length' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
				'allowed_setters' => ['file','raw','string'],
				'allowed_getters' => ['vector'],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadUnframedStreamWrite'
		]
	],	
	'StreamingDloadUnframedStreamWriteResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadUnframedStreamWriteResponse'
		]
	],

	'StreamingDloadPowerOffRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadPowerOffResponse',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadPowerOff'
		]
	],	
	'StreamingDloadPowerOffResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'address' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kStreamingDloadPoweringDown'
		]
	],
];

/**
* DM/DIAG/QCDM Packet Definitions
*/
$packets['qcdm'] = [
	'DmPacket' => [
		'skip' => true,
		'path' => 'qualcomm/packet'
	],
	'DmPhoneModeRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'padding' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8]
			]
		]
	],
	'DmPhoneModeResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
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
		'expects_response' => 'DmSpcResponse',
		'unpack_base' => true,
		'fields'  => [
			'spc' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 6,
				'size_const' => 'DIAG_SPC_LENGTH',
				'allowed_setters' => ['raw'],
				'allowed_getters' => ['vector'],
			],
		]
	],
	'DmSpcResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
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
		'expects_response' => '',
		'unpack_base' => true,
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
		'expects_response' => '',
		'unpack_base' => true,
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
		'expects_response' => '',
		'unpack_base' => true,
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
		'expects_response' => '',
		'unpack_base' => true,
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
		'expects_response' => '',
		'unpack_base' => true,
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
		'expects_response' => '',
		'unpack_base' => true,
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
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		]
	],

	'DmGuidResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
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
* QCDM EFS Packet Definitions
*/
$packets['qcdm_efs'] = [
	'DmEfsPacket' => [
		'skip' => true,
		'path' => 'qualcomm/packet'
	],


	'DmEfsHelloRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'target_packet_window_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'target_packet_window_byte_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'host_packet_window_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'host_packet_window_byte_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'dir_iterator_window_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'dir_iterator_window_byte_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'feature_bits' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsHelloResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'target_packet_window_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'target_packet_window_byte_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'host_packet_window_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'host_packet_window_byte_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'dir_iterator_window_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'dir_iterator_window_byte_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_version' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'feature_bits' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],



	'DmEfsQueryRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		]
	],

	'DmEfsQueryResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'max_file_name_length' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_pathname_length' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_symlink_depth' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_file_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_directories' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_mounts' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsOpenFileRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'flags' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'file_path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],

	'DmEfsOpenFileResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsCloseFileRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsCloseFileReponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsReadFileRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'offset' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsReadFileResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'offset' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'bytes_read' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsWriteFileRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'offset' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],

	'DmEfsWriteFileResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'offset' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'bytes_written' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsCreateLinkRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
			'new_path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],

	'DmEfsCreateLinkResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsReadLinkRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],

	'DmEfsUnlinkRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsUnlinkResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsMkdirRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsMkdirResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsRmdirRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsRmdirResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsOpenDirRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsOpenDirResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'dp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsReadDirRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'dp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'sequence_number' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],


	'DmEfsReadDirResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'dp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'sequence_number' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'entry_type' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'atime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mtime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'ctime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'name' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsCloseDirRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'dp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],


	'DmEfsCloseDirResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsRenameRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
			'new_path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsRenameResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsStatRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsStatResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'link_count' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'atime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mtime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'ctime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsLstatRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsLstatResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'atime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mtime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'ctime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],


	'DmEfsFstatRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],


	'DmEfsFstatResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'link_count' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'atime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mtime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'ctime' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsChmodRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsChmodResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],

	'DmEfsStatfsRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsStatfsResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'filesystem_id' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 8,
			],
			'filesystem_type' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'block_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'total_blocks' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'available_blocks' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'free_blocks' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_file_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'file_count' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_file_count' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		]
	],

	'DmEfsAccessRequest' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'permission_mask' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		]
	],


	'DmEfsAccessResponse' => [
		'namespace' => 'QC',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::QC',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],
];

/**
* DLOAD Packet Definitions
*/
$packets['dload'] = [
	'DloadPacket' => [
		'skip' => true,
		'path' => 'qualcomm/packet'
	],
];

/**
* LG LAF Packet Definitions
*/
$packets['laf'] = [
	/*'LafPacket' => [
		'skip' => true,
		'path' => 'lg/packet'
	],*/
	'LafPacket' => [
		'namespace' => 'LG',
		'path'	  => 'lg/packet',
		'extends' => 'Packet',
		'extends_namespace' => 'OpenPST::Transport',
		'source'  => 'local',
		'expects_response' => 'LafPacket',
		'unpack_base' => false,
		'fields'  => [
			'command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'arg0' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'arg1' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'arg_opt0' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'arg_opt1' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'crc' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'magic' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 2,
			],
		]
	],
];

/**
* ADB Packet Definitions
*/
$packets['dload'] = [
	'AdbPacket' => [
		'skip' => true,
		'path' => 'android/packet'
	],
];

/**
* TCP Serial server packets
*/
$packets['tcp_serial'] = [
	'TcpSerialPacket' => [
		'skip' => true,
		'path' => 'server/packet'
	],
];
