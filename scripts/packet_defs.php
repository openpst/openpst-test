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
	'RawDataPacket' => [
		'skip' => true,
		'path' => 'transport/packet'
	],
	'SaharaHelloRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => 'SaharaHelloResponse',
		'unpack_base' => true,
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
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'reserved' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => '(sizeof(uint32_t) * 5)',
				'allowed_getters' => ['vector'],
				'allowed_setters' => ['raw'],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandHello'
		]
	],
	'SaharaHelloResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
			'status' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'mode' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],			
			'reserved' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => '(sizeof(uint32_t) * 6)',
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandHelloResponse'
		]
	],
	'SaharaReadDataRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'image_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'offset' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'amount' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		]
	],
	'SaharaReadDataResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'RawDataPacket',
		'extends_namespace' => 'OpenPST::Transport',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
		]
	],
	'SaharaEndImageTransferResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'fields'  => [],
		'expects_response' => 'SaharaDoneResponse',
		'default_exends' => [
			'command' => 'kSaharaCommandDone'
		]
	],
	'SaharaDoneResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'unpack_base' => true,
		'source'  => 'remote',
		'fields'  => [],
		'expects_response' => '',
		'default_exends' => [
			'command' => 'kSaharaCommandDoneResponse'
		]
	],
	'SaharaResetRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'fields'  => [],
		'expects_response' => 'SaharaResetResponse',
		'default_exends' => [
			'command' => 'kSaharaCommandReset'
		]
	],
	'SaharaResetResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'fields'  => [],
		'expects_response' => '',
		'unpack_base' => true,
		'default_exends' => [
			'command' => 'kSaharaCommandResetResponse'
		]
	],
	'SaharaMemoryDebugRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'SaharaClientCommandResponse',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'client_command' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'data_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'command' => 'kSaharaCommandExecuteResponse'
		]
	],
	'SaharaClientCommandExecuteDataRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
	/*'SaharaMemoryDebug64Request' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
			'command' => 'kSaharaCommandMemoryDebug64'
		]
	],
	'SaharaMemoryRead64Request' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
			'command' => 'kSaharaCommandMemoryRead64'
		]
	],
	'SaharaCommandMemoryDebug64Request' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'SaharaPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
	],*/
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'StreamingDloadCloseResponse',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => 'kStreamingDloadClose'
		]
	],	
	'StreamingDloadCloseResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'StreamingDloadPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
* DM/DIAG/QualcommDM Packet Definitions
*/
$packets['qcdm'] = [
	'DmPacket' => [
		'skip' => true,
		'path' => 'qualcomm/packet'
	],

	'DmPhoneModeRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'command' => ''
		]
	],
	'DmPhoneModeResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
			'command' => ''
		]
	],

	'DmSpcRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'command' => 'kDiagSpc'
		]
	],
	'DmSpcResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
			'command' => 'kDiagSpc'
		]
	],

	'DmPasswordRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'command' => 'kDiagPassword'
		]
	],
	
	'DmPasswordResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
			'command' => 'kDiagPassword'
		]
	],

	'DmNvReadRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'command' => 'kDiagNvRead'
		]
	],
	'DmNvReadResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'command' => 'kDiagNvRead'
		]
	],

	'DmVersionRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'version' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			]
		],
		'default_exends' => [
			'command' => 'kDiagDiagVer'
		]
	],
	'DmVersionResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'command' => 'kDiagDiagVer'
		]
	],

	'DmGuidRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'command' => ''
		]
	],

	'DmGuidResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'command' => ''
		]
	],
];

/**
* QualcommDM EFS Packet Definitions
*/
$packets['qcdm_efs'] = [
	'DmEfsPacket' => [
		'skip' => true,
		'path' => 'qualcomm/packet'
	],


	'DmEfsHelloRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsHelloResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsHello'
		]
	],

	'DmEfsHelloResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsHello'
		]
	],



	'DmEfsQueryRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsQueryResponse',
		'unpack_base' => true,
		'fields'  => [
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsQuery'
		]
	],

	'DmEfsQueryResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsQuery'
		]
	],

	'DmEfsOpenFileRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsOpenFileResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsOpen'
		]
	],

	'DmEfsOpenFileResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsOpen'
		]
	],

	'DmEfsCloseFileRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsCloseFileReponse',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsClose'
		]
	],

	'DmEfsCloseFileReponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsClose'
		]
	],

	'DmEfsReadFileRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsReadFileResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsRead'
		]
	],

	'DmEfsReadFileResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsRead'
		]
	],


	'DmEfsWriteFileRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsWriteFileResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsWrite'
		]
	],

	'DmEfsWriteFileResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsWrite'
		]
	],

	'DmEfsCreateLinkRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsCreateLinkResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsSymlink'
		]
	],

	'DmEfsCreateLinkResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsSymlink'
		]
	],

	'DmEfsReadLinkRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsReadLinkResponse',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsReadLink'
		]
	],
	'DmEfsReadLinkResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsReadLink'
		]
	],


	'DmEfsUnlinkRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsUnlinkResponse',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsUnlink'
		]
	],


	'DmEfsUnlinkResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsUnlink'
		]
	],

	'DmEfsMkdirRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsMkdirResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsMkdir'
		]
	],


	'DmEfsMkdirResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsMkdir'
		]
	],

	'DmEfsRmdirRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'expects_response' => 'DmEfsRmdirResponse',
		'source'  => 'local',
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsRmdir'
		]
	],


	'DmEfsRmdirResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsRmdir'
		]
	],

	'DmEfsOpenDirRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsOpenDirResponse',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsOpenDir'
		]
	],


	'DmEfsOpenDirResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsOpenDir'
		]
	],

	'DmEfsReadDirRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsReadDirResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsReadDir'
		]
	],


	'DmEfsReadDirResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsReadDir'
		]
	],


	'DmEfsCloseDirRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsCloseDirResponse',
		'unpack_base' => true,
		'fields'  => [
			'dp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsCloseDir'
		]
	],


	'DmEfsCloseDirResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsCloseDir'
		]
	],

	'DmEfsRenameRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsRename'
		]
	],


	'DmEfsRenameResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsRename'
		]
	],

	'DmEfsStatRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsStat'
		]
	],


	'DmEfsStatResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsStat'
		]
	],

	'DmEfsLstatRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsLstat'
		]
	],


	'DmEfsLstatResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsLstat'
		]
	],


	'DmEfsFstatRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsFstatResponse',
		'unpack_base' => true,
		'fields'  => [
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFstat'
		]
	],


	'DmEfsFstatResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFstat'
		]
	],

	'DmEfsChmodRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsChmodResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsChmod'
		]
	],


	'DmEfsChmodResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsChmod'
		]
	],

	'DmEfsStatfsRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsStatfsResponse',
		'unpack_base' => true,
		'fields'  => [
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsStatFS'
		]
	],


	'DmEfsStatfsResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsStatFS'
		]
	],

	'DmEfsAccessRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsAccessResponse',
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
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsAccess'
		]
	],


	'DmEfsAccessResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsAccess'
		]
	],


	'DmEfsDeviceInfoRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsDeviceInfoResponse',
		'unpack_base' => true,
		'fields'  => [

		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsDevInfo'
		]
	],

	'DmEfsDeviceInfoResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'total_blocks' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'pages_per_block' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'page_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'total_page_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'maker_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'device_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'device_type' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'name' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsDevInfo'
		]
	],



	'DmEfsFactoryImageStartRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsFactoryImageStartResponse',
		'unpack_base' => true,
		'fields'  => [

		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFactoryImageStart'
		]
	],


	'DmEfsFactoryImageStartResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFactoryImageStart'
		]
	],

	'DmEfsFactoryImageReadRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsFactoryImageReadResponse',
		'unpack_base' => true,
		'fields'  => [
			'stream_state' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'info_cluster_sent' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'custer_map_sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'custer_data_sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFactoryImageRead'
		]
	],


	'DmEfsFactoryImageReadResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'stream_state' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'info_cluster_sent' => [ 
				'type' => FIELD_TYPE_UINT8,
				'size' => $fieldSizes[FIELD_TYPE_UINT8],
			],
			'custer_map_sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'custer_data_sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'data' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFactoryImageRead'
		]
	],

	'DmEfsFactoryImageEndRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsFactoryImageEndResponse',
		'unpack_base' => true,
		'fields'  => [

		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFactoryImageEnd'
		]
	],


	'DmEfsFactoryImageEndResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFactoryImageEnd'
		]
	],

	'DmEfsFactoryImagePrepareRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsFactoryImagePrepareResponse',
		'unpack_base' => true,
		'fields'  => [

		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsPrepareFactoryImage'
		]
	],


	'DmEfsFactoryImagePrepareResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsPrepareFactoryImage'
		]
	],

	'DmEfsChownRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsChownResponse',
		'unpack_base' => true,
		'fields'  => [
			'uid' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'gid' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsChown'
		]
	],


	'DmEfsChownResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsChown'
		]
	],

	'DmEfsSetReservationRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsSetReservationResponse',
		'unpack_base' => true,
		'fields'  => [
			'gid' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'amount' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsSetReservation'
		]
	],


	'DmEfsSetReservationResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsSetReservation'
		]
	],

	'DmEfsSetQuotaRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsSetQuotaResponse',
		'unpack_base' => true,
		'fields'  => [
			'gid' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'amount' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsSetQuota'
		]
	],


	'DmEfsSetQuotaResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsSetQuota'
		]
	],

	'DmEfsGetGroupInfoRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsGetGroupInfoResponse',
		'unpack_base' => true,
		'fields'  => [
			'gid' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsGetGroupInfo'
		]
	],


	'DmEfsGetGroupInfoResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'quota_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'reservation_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'space_used' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsGetGroupInfo'
		]
	],

	'DmEfsDeltreeRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsDeltreeResponse',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsDeltree'
		]
	],


	'DmEfsDeltreeResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsDeltree'
		]
	],

	'DmEfsTruncateRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsTruncateResponse',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'length' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsTruncate'
		]
	],


	'DmEfsTruncateResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsTruncate'
		]
	],

	'DmEfsFtruncateRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsFtruncateResponse',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'length' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'fp' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFtruncate'
		]
	],


	'DmEfsFtruncateResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsFtruncate'
		]
	],

	'DmEfsStatfsV2Request' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsStatfsV2Response',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsStatVFS_V2'
		]
	],


	'DmEfsStatfsV2Response' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'fs_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'fs_type' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 8,
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
			'max_files' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_write_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_path_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'case_sensitive' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'case_preserving' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_file_size' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'file_size_units' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'max_open_files' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'name_rule' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'name_encoding' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsStatVFS_V2'
		]
	],

	'DmEfsMd5SumRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsMd5SumResponse',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsMd5Sum'
		]
	],


	'DmEfsMd5SumResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'hash' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 16,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsMd5Sum'
		]
	],

	'DmEfsHotplugFormatRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsHotplugFormatResponse',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsHotplugFormat'
		]
	],


	'DmEfsHotplugFormatResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsHotplugFormat'
		]
	],

	'DmEfsShredRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsHotplugFormatResponse',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsShred'
		]
	],


	'DmEfsShredResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'results' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsShred'
		]
	],

	'DmEfsHotplugDeviceInfoRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => 'DmEfsHotplugDeviceInfoResponse',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsHotplugDeviceInfo'
		]
	],


	'DmEfsHotplugDeviceInfoResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'manufacturer_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'oem_id' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'product_revision' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'product_name' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 16,
			],
			'manufactured_date' => [ 
				'type' => FIELD_TYPE_UARRAY,
				'size' => $fieldSizes[FIELD_TYPE_UINT8] * 16,
			],
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsHotplugDeviceInfo'
		]
	],

	'DmEfsSyncRequest' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'path' => [ 
				'type' => FIELD_TYPE_VARIABLE,
				'size' => 0,
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsSyncNoWait'
		]
	],


	'DmEfsSyncResponse' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'token' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => 'kDiagEfsSyncNoWait'
		]
	],
/*
	'Request' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'local',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
		],
		'default_exends' => [
			'subsys_command' => ''
		]
	],


	'Response' => [
		'namespace' => 'Qualcomm',
		'path'	  => 'qualcomm/packet',
		'extends' => 'DmEfsPacket',
		'extends_namespace' => 'OpenPST::Qualcomm',
		'source'  => 'remote',
		'expects_response' => '',
		'unpack_base' => true,
		'fields'  => [
			'sequence' => [ 
				'type' => FIELD_TYPE_UINT16,
				'size' => $fieldSizes[FIELD_TYPE_UINT16],
			],
			'error' => [ 
				'type' => FIELD_TYPE_UINT32,
				'size' => $fieldSizes[FIELD_TYPE_UINT32],
			]
		],
		'default_exends' => [
			'subsys_command' => ''
		]
	],
*/
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
