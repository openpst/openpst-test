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
* @file sahara.h
* @package openpst/libopenpst
* @brief Sahara protocol definitions
*
* @author Gassan Idriss <ghassani@gmail.com>
*/
#pragma once

#include "definitions.h"

#ifndef SAHARA_MAX_PACKET_SIZE
#define SAHARA_MAX_PACKET_SIZE 0x400
#endif

#ifndef SAHARA_LOG_LENGTH
#define SAHARA_LOG_LENGTH 0x64
#endif

#ifndef SAHARA_MAX_MEMORY_DATA_SIZE
#define SAHARA_MAX_MEMORY_DATA_SIZE 0x1000
#endif

#ifndef SAHARA_RAM_ZI_SIZE
#define SAHARA_RAM_ZI_SIZE 0x20000
#endif

#ifndef SAHARA_MAX_MEMORY_REQUEST_SIZE
#define SAHARA_MAX_MEMORY_REQUEST_SIZE 0x50000
#endif

/**
 * These are all known commands, both rx and tx.
 */
enum SaharaCommand {
	kSaharaCommandHello             = 0x01, // Initialize connection and protocol
	kSaharaCommandHelloResponse     = 0x02, // Acknowledge connection/protocol, mode of operation
	kSaharaCommandReadData          = 0x03, // Read specified number of bytes from host
	kSaharaCommandEndImageTransfer  = 0x04, // image transfer end / target transfer failure
	kSaharaCommandDone              = 0x05, // Acknowledgement: image transfer is complete
	kSaharaCommandDoneResponse      = 0x06, // Target is exiting protocol
	kSaharaCommandReset             = 0x07, // Instruct target to perform a reset
	kSaharaCommandResetResponse     = 0x08, // Indicate to host that target is about to reset
	kSaharaCommandMemoryDebug       = 0x09, // Indicate to host: target debug mode & ready to transfer memory content
	kSaharaCommandMemoryRead        = 0x0A, // Read number of bytes, starting from a specified address
	kSaharaCommandReady             = 0x0B, // Indicate to host: target ready to receive client commands,
	kSaharaCommandSwitchMode        = 0x0C, // Switch to a mode defined in enum SAHARA_MODE
	kSaharaCommandExecute           = 0x0D, // Indicate to host: to execute a given client command
	kSaharaCommandExecuteResponse	= 0x0E, // Indicate to host: target command execution status
	kSaharaCommandExecuteData		= 0x0F, // Indicate to target that host is ready to receive (more) data
	kSaharaCommandMemoryDebug64     = 0x10,
	kSaharaCommandMemoryRead64      = 0x11,
};

/**
 * SAHARA_MODE
 *
 * These are all known modes available
 * The initial hello lets you know which
 * mode the device is currently in.
 */
enum SaharaMode {
	kSaharaModeImageTxPending  = 0x00,
	kSaharaModeImageTxComplete = 0x01,  
	kSaharaModeMemoryDebug     = 0x02,
	kSaharaModeCommand         = 0x03
};

/**
 * SaharaClientCmd
 *
 * When in or switched to command mode, these are
 * all commands that are currently known
 */
enum SaharaClientCmd {
	  kSaharaClientCmdNop                    = 0x00,
	  kSaharaClientCmdSerialNumRead          = 0x01,
	  kSaharaClientCmdMsmHWIDRead            = 0x02,
	  kSaharaClientOemPkHashRead			 = 0x03,
	  kSaharaClientCmdSwitchDMSS			 = 0x04, // haven't found a device/mode this works on
	  kSaharaClientCmdSwitchToStreamingDload = 0x05, // haven't found a device/mode this works on
	  kSaharaClientCmdReadDebugData          = 0x06,
	  kSaharaClientCmdGetSblVersion			 = 0x07,
};

enum SaharaStatusCode {
	kSaharaStatusSuccess                      = 0x00,
	kSaharaStatusInvalidCmd                   = 0x01,
	kSaharaStatusProtocolMismatch             = 0x02,
	kSaharaStatusInvalidTargetProtocol        = 0x03,
	kSaharaStatusInvalidHostProtocol          = 0x04,
	kSaharaStatusInvalidPacketSize            = 0x05,
	kSaharaStatusUnexpectedImageId            = 0x06,
	kSaharaStatusInvalidHeaderSize            = 0x07,
	kSaharaStatusInvalidDataSize              = 0x08,
	kSaharaStatusInvalidImageType             = 0x09,
	kSaharaStatusInvalidTxLength              = 0x0A,
	kSaharaStatusInvalidRxLength              = 0x0B,
	kSaharaStatusTxRxError					  = 0x0C,
	kSaharaStatusReadDataError                = 0x0D,
	kSaharaStatusUnsupportedNumPhdrs          = 0x0E,
	kSaharaStatusInvalidPhdrSize              = 0x0F,
	kSaharaStatusMultipleSharedSeg            = 0x10,
	kSaharaStatusUninitPhdrLoc                = 0x11,
	kSaharaStatusInvalidDestAddress           = 0x12,
	kSaharaStatusInvalidImageHeaderSize       = 0x13,
	kSaharaStatusInvalidElfHeader             = 0x14,
	kSaharaStatusUnknownError				  = 0x15,
	kSaharaStatusTimeoutRx                    = 0x16,
	kSaharaStatusTimeoutTx                    = 0x17,
	kSaharaStatusInvalidMode				  = 0x18,
	kSaharaStatusInvalidMemoryRead            = 0x19,
	kSaharaStatusInvalidDataSizeRequest       = 0x1A,
	kSaharaStatusMemoryDebugNotSupported      = 0x1B,
	kSaharaStatusInvalidModeSwitch            = 0x1C,
	kSaharaStatusExecFailure				  = 0x1D,
	kSaharaStatusExecCmdInvalidParam          = 0x1E,
	kSaharaStatusExecCmdUnsupported           = 0x1F,
	kSaharaStatusExecDataInvalid			  = 0x20,
	kSaharaStatusHashTableAuthFailure         = 0x21,
	kSaharaStatusHashVerificationFailure      = 0x22,
	kSaharaStatusHashTableNotFound            = 0x23,
	kSaharaStatusTargetInitFailure            = 0x24,
	kSaharaStatusImageAuthFailure             = 0x25,
	kSaharaStatusInvalidImgHashTableSize	  = 0x26,
	kSaharaStatusMax
};

/**
* SaharaMsmHwIdResponse
*
* represents a response from client command:
*	kSaharaClientCmdMsmHWIDRead
*/
typedef struct {
	uint16_t unknown1;
	uint16_t unknown2;
	uint16_t msmId;
} SaharaMsmHwId;

/**
* SaharaSerialNumberResponse
*
* represents a response from client command:
*	kSaharaClientCmdSerialNumRead
*/
typedef struct {
	uint32_t serial;
} SaharaSerialNumber;

/**
* SaharaSblVersionResponse
*
* represents a response from client command:
*	kSaharaClientCmdGetSblVersion
*/
typedef struct {
	uint32_t version;
} SaharaSblVersion;

/**
* SaharaSblVersionResponse
*
* represents a response from client command
* kSaharaClientOemPkHashRead
*/
typedef struct {
	uint8_t hash[32];
} SaharaOemPkHash;


/**
* SaharaDebugLogEntry
*
* represents a single log entry from client command
* kSaharaClientCmdReadDebugData response
*/
typedef struct {
	uint8_t message[SAHARA_LOG_LENGTH];
} SaharaDebugLogEntry;

/**
* SaharaMemoryTableEntry
*
* This structure represents the memory table entry
* when reading the memory table from the specified address
* of a kSaharaCommandMemoryDebug response
* 
* The total number of entries would be response.size / sizeof(SaharaMemoryTableEntry)
*/
PACKED(typedef struct {
	uint32_t   unknown1;
	uint32_t   address;
	uint32_t   size;
	uint8_t    name[20];
	uint8_t    filename[20];
}) SaharaMemoryTableEntry;
