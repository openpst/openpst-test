/**
*
* (c) Gassan Idriss <ghassani@gmail.com>
* 
* This file is part of libopenpst.
* 
* libopenpst is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* libopenpst is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with libopenpst. If not, see <http://www.gnu.org/licenses/>.
*
* @file streaming_dload.h
* @package openpst/libopenpst
* @brief Streaming DLOAD definitions and structures
* @see DCN 80-V5348-1 J
*
* @author Gassan Idriss <ghassani@gmail.com>
*/
#pragma once

#include "definitions.h"

#define STREAMING_DLOAD_FEATURE_BIT_UNCOMPRESSED_DOWNLOAD   0x00000001
#define STREAMING_DLOAD_FEATURE_BIT_NAND_BOOTABLE_IMAGE     0x00000002
#define STREAMING_DLOAD_FEATURE_BIT_NAND_BOOT_LOADER        0x00000004
#define STREAMING_DLOAD_FEATURE_BIT_MULTI_IMAGE             0x00000008
#define STREAMING_DLOAD_FEATURE_BIT_SECTOR_ADDRESSES        0x00000010

#define STREAMING_DLOAD_FEATURE_ALL (STREAMING_DLOAD_FEATURE_BIT_UNCOMPRESSED_DOWNLOAD | \
	STREAMING_DLOAD_FEATURE_BIT_NAND_BOOTABLE_IMAGE | \
	STREAMING_DLOAD_FEATURE_BIT_NAND_BOOT_LOADER | \
	STREAMING_DLOAD_FEATURE_BIT_MULTI_IMAGE | \
	STREAMING_DLOAD_FEATURE_BIT_SECTOR_ADDRESSES)

#define STREAMING_DLOAD_MAX_DATA_SIZE 1024

#define STREAMING_DLOAD_MAX_TX_SIZE (STREAMING_DLOAD_MAX_DATA_SIZE * 2)
#define STREAMING_DLOAD_MAX_RX_SIZE (STREAMING_DLOAD_MAX_DATA_SIZE * 2)

#define STREAMING_DLOAD_MAGIC_SIZE 32
#define STREAMING_DLOAD_FLASH_ID_MAX_SIZE    32
#define STREAMING_DLOAD_MESSAGE_SIZE  64
#define STREAMING_DLOAD_MAX_SECTORS 128
#define STREAMING_DLOAD_PARTITION_TABLE_SIZE 512

enum StreamingDloadSecurityMode {
	kStreamingDloadSecurityModeUntrusted = 0x00,
	kStreamingDloadSecurityModeTrusted = 0x01
};

enum StreamingDloadPartitionTableState {
	kStreamingDloadPartitionTableAccepted					= 0x00,
	kStreamingDloadPartitionTableDiffersOverrideAccepted	= 0x01,
	kStreamingDloadPartitionTableDiffersFormatNotRecognized = 0x02,
	kStreamingDloadPartitionTableEraseFailed				= 0x03
};


enum StreamingDloadCommand {
	// 0x00 - Illegal
	kStreamingDloadHello                        = 0x01,
	kStreamingDloadHelloResponse               	= 0x02,
	kStreamingDloadRead                         = 0x03,
	kStreamingDloadReadData                    	= 0x04,
	kStreamingDloadSimpleWrite                 	= 0x05,
	kStreamingDloadWriteOk                     	= 0x06,
	kStreamingDloadStreamWrite                 	= 0x07,
	kStreamingDloadBlockWritten                	= 0x08,
	kStreamingDloadNop                          = 0x09,
	kStreamingDloadNopResponse                 	= 0x0A,
	kStreamingDloadReset                        = 0x0B,
	kStreamingDloadResetAck                    	= 0x0C,
	kStreamingDloadError                        = 0x0D,
	kStreamingDloadLog                          = 0x0E,
	kStreamingDloadUnlock                       = 0x0F,
	kStreamingDloadUnlocked                     = 0x10,
	kStreamingDloadPowerOff                    	= 0x11,
	kStreamingDloadPoweringDown                	= 0x12,
	kStreamingDloadOpen                         = 0x13,
	kStreamingDloadOpened                       = 0x14,
	kStreamingDloadClose                        = 0x15,
	kStreamingDloadClosed                       = 0x16,
	kStreamingDloadSecurityMode                	= 0x17,
	kStreamingDloadSecurityModeReceived       	= 0x18,
	kStreamingDloadPartitionTable              	= 0x19,
	kStreamingDloadPartitionTableReceived     	= 0x1A,
	kStreamingDloadOpenMultiImage             	= 0x1B,
	kStreamingDloadOpenedMultiImage           	= 0x1C,
	kStreamingDloadEraseFlash                  	= 0x1D,
	kStreamingDloadFlashErased                 	= 0x1E,
	kStreamingDloadGetEccState                	= 0x1F,
	kStreamingDloadCurrentEccState            	= 0x20,
	kStreamingDloadSetEcc                      	= 0x21,
	kStreamingDloadSetEccResponse             	= 0x22,
	kStreamingDloadCalculateSha1          		= 0x23, // depreciated - doesnt appear to be used
	kStreamingDloadInfoRequest 					= 0x23,
	kStreamingDloadCalculateSha1Response		= 0x24, // depreciated - doesnt appear to be used
	kStreamingDloadInfoResponse                	= 0x24, 

	//25-2F commands described in [Q2]

	kStreamingDloadUnframedStreamWrite          = 0x29,
	kStreamingDloadUnframedStreamWriteResponse  = 0x31,

	// havent tested on a device that these is supported but is mentioned in a document
	kStreamingDloadWfpromWrite                  = 0x32, 
	kStreamingDloadWfpromWriteResponse          = 0x33, 
	kStreamingDloadQfpromRead                   = 0x34, 
	kStreamingDloadQfpromReadResponse           = 0x35  

	//36-FE Reserved
};

enum StreamingDloadErrorCode {
	kStreamingDloadErrorInvalidDestinationAddress			= 0x02,
	kStreamingDloadErrorInvalidLength                       = 0x03,
	kStreamingDloadErrorUnexpectedPacketEnd					= 0x04,
	kStreamingDloadErrorInvalidCommand                      = 0x05,
	kStreamingDloadErrorWrongFlashIntelligentId             = 0x08,
	kStreamingDloadErrorBadProgrammingVoltage               = 0x09,
	kStreamingDloadErrorWriteVerifyFailed                   = 0x0A,
	kStreamingDloadErrorIncorrectSecurityCode               = 0x0C,
	kStreamingDloadErrorCannotPowerDown                     = 0x0D,
	kStreamingDloadErrorNandProgrammingUnsupported			= 0x0E,
	kStreamingDloadErrorCommandOutOfSequence                = 0x0F,
	kStreamingDloadErrorCloseDidNotSucceed                  = 0x10,
	kStreamingDloadErrorIncompatibleFeatureBits             = 0x11,
	kStreamingDloadErrorOutOfSpace                          = 0x12,
	kStreamingDloadErrorInvalidSecurityMode                 = 0x13,
	kStreamingDloadErrorMultiImageNandUnsupported			= 0x14,
	kStreamingDloadErrorPowerOffCmdUnsupported				= 0x15
	// 0x16 - 0x1A RESERVED FOR ERROR REASONS IN [Q2]
};

enum StreamingDloadOpenMode {
	kStreamingDloadOpenModeBootloader       = 0x01,
	kStreamingDloadOpenModeBootableImage	= 0x02,
	kStreamingDloadOpenModeCefs				= 0x03,
	kStreamingDloadOpenModeFactory          = 0x04
};

enum StreamingDloadOpenMultiMode {
	kStreamingDloadOpenModeMultiNone         = 0x00,  
	kStreamingDloadOpenModeMultiPbl          = 0x01,  // Primary boot loader
	kStreamingDloadOpenModeMultiQcsblhHdCfg  = 0x02,  // Qualcomm secondary boot loader header and config data 
	kStreamingDloadOpenModeMultiQcsbl        = 0x03,  // Qualcomm secondary boot loader
	kStreamingDloadOpenModeMultiOemsbl       = 0x04,  // OEM secondary boot loader (max payload: 512 octets)
	kStreamingDloadOpenModeMultiAmss         = 0x05,  // AMSS modem executable (max payload: 512 octets)
	kStreamingDloadOpenModeMultiApps         = 0x06,  // AMSS applications executable (max payload: 512 octets)
	kStreamingDloadOpenModeMultiObl          = 0x07,  // MSM6250 OTP boot loader 
	kStreamingDloadOpenModeMultiFotaui       = 0x08,  // FOTA UI binary 
	kStreamingDloadOpenModeMultiCefs         = 0x09,  // Compact EFS2 image
	kStreamingDloadOpenModeMultiAppsBL       = 0x0A,  // AMSS applications boot loader (max payload: 512 octets)
	kStreamingDloadOpenModeMultiApps_CEFS    = 0x0B,  // Apps CEFS image
	kStreamingDloadOpenModeMultiFlashBin     = 0x0C,  // Flash.bin for Windows Mobile
	kStreamingDloadOpenModeMultiDsp1         = 0x0D,  // DSP1 runtime image
	kStreamingDloadOpenModeMultiCustom       = 0x0E,  // Image for user-defined partition User (max payload: 512 octets)
	kStreamingDloadOpenModeMultiDbl          = 0x0F,  // DBL image for Secure  Boot 2.0 architecture 
	kStreamingDloadOpenModeMultiOsbl         = 0x10,  // OSBL image for Secure  Boot 2.0 architecture 
	kStreamingDloadOpenModeMultiFsbl         = 0x11,  // FSBL image for Secure  Boot 2.0 architecture 
	kStreamingDloadOpenModeMultiDsp2         = 0x12,  // DSP2 executable 
	kStreamingDloadOpenModeMultiRaw          = 0x13,  // Apps EFS2 raw image 
	kStreamingDloadOpenModeMultiRofs1        = 0x14,  // Symbian
	kStreamingDloadOpenModeMultiRofs2        = 0x15,  // Symbian
	kStreamingDloadOpenModeMultiRofs3        = 0x16,  // Symbian  0x17-0x1F - RESERVED
	kStreamingDloadOpenModeMultiEmmcUser     = 0x21,  // EMMC card USER partition image 
	kStreamingDloadOpenModeMultiEmmcBoot0    = 0x22,  // EMMC card BOOT0 partition image 
	kStreamingDloadOpenModeMultiEmmcBoot1    = 0x23,  // EMMC card BOOT1 partition image 
	kStreamingDloadOpenModeMultiRpmb   		 = 0x24,  // partition1
	kStreamingDloadOpenModeMultiGpp1   		 = 0x25,  // partition1-4
	kStreamingDloadOpenModeMultiGpp2   		 = 0x26,   
	kStreamingDloadOpenModeMultiGpp3   		 = 0x27,   
	kStreamingDloadOpenModeMultiGpp4   		 = 0x28    
};

enum StreamingDloadOpenMultiState {
	kStreamingDloadOpenMultiSuccess				  = 0x00,
	kStreamingDloadOpenMultiPayloadLengthExceeded = 0x01,
	kStreamingDloadOpenMultiNoPayloadExpected	  = 0x02,
	kStreamingDloadOpenMultiPayloadRequiredFail   = 0x03,
	kStreamingDloadOpenMultiBlockWriteProtected   = 0x04
};