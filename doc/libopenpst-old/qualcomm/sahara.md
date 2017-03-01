## libopenpst > Qualcomm > Sahara

### Sahara Protocol

About sahara protocol here.

### Library Classes Related to Sahara
`libopenpst` provides a few classes for working with Qualcomm Sahara protocol.

 1. SaharaSerial
 2. SaharaXmlReader

----------

### SaharaSerial
This class exposes all Sahara protocol functionality. It is  a wrapper around `GenericSerial` class which provides the serial data transfer.

#### SaharaSerial Constructor

The constructor for SaharaSerial has the following signature:

    SaharaSerial(std::string port, int baudrate = 115200, int timeout = 1000);

If a port name is specified, the device will try to automatically open it. If no port name is provided, then no device will be opened. You can initialize `SaharaSerial` without a port specified and set it with `setPort()` method later, followed by `open()` to open the device.

#### SaharaSerial Public Methods

    SaharaHelloRequest readHello();

The `readHello` method will read from the serial port and consume the Hello handshake
	into a SaharaHelloRequest packet. This is the start of every Sahara session. If there is no data waiting in the serial port upon connection then the device is either not in sahara mode, requires a power reset, or unlikely has already established the hello handshake. Once read, it is expected to send a hello response back with `sendHello`

    SaharaState sendHello(uint32_t mode, uint32_t version = 0x02, uint32_t minVersion = 0x01, uint32_t status = 0x00);

The `sendHello` method will respond to a hello request from the device and establish/sync the session configuration. This method will return structure `SaharaState` which is also stored internally in your `SaharaSerial` instance. This structure helps keep track of the current state of the session. 

    void switchMode(uint32_t mode);

The `switchMode` method will attempt to switch the mode of operation.

Sahara provides the following modes:

 1. Image Transfer
 2. Memory Debug 
 3. Client Commands

    SaharaState switchModeAndHello(uint32_t mode);

The `switchModeAndHello` method will attempt to switch modes and re-establish the hello handshake. When switching modes after a Hello handshake, the device will re-send the hello to restart the session in that mode.

    std::vector<uint8_t> sendClientCommand(uint32_t command);

The `sendClientCommand` method will execute a client command. This will only work when you switch to Client Command Mode.

    size_t sendImage(std::string filePath, SaharaReadDataRequest initialReadRequest);
	SaharaReadDataRequest sendImage(std::ifstream& file, uint32_t offset, size_t size);
	
The `sendImage` method will send a requested image over serial to the device. This method should be used after receiving a SaharaReadDataRequest from the method readNextImageOffset.

    SaharaReadDataRequest readNextImageOffset();

The `readNextImageOffset` method expects the device to send a packet containing information on what image and offset to send the device.

    size_t readMemory(uint32_t address, size_t size, std::vector<uint8_t>&out);
    size_t readMemory(uint32_t address, size_t size, std::string outFilePath);
    size_t readMemory(uint32_t address, size_t size, std::ofstream& out);

    void sendDone();

The `sendDone` method will end the sahara session and the device will attempt to boot, or in the case of EDL attempt to execute the sent programmer to recover the flash.

    void sendReset();

The `sendReset` method will reset the device.


Below is a code example for initializing SaharaSerial:

    #include "qualcomm/sahara_serial.h"
    #include <vector>
	#include <iostream>
	
	using OpenPST::QC::SaharaSerial;
	using OpenPST::QC::SaharaSerialError;
	
	void main()
	{
		try {
			
			SaharaSerial port("/dev/ttyUSB0");
					
		} catch(SaharaSerialError& e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
		
		return 0;
	}
#### Handling Errors
`SaharaSerial` will always throw an instance of `SaharaSerialError` when something goes wrong.


----------


### SaharaXmlReader
This class parses a sahara.xml file and returns a vector of referenced images inside it.

Using this class is quite simple. Create an instance of SarahraXmlReader and call the parse() method passing a string to a file on your local filesystem.


    #include "qualcomm/sahara_xml_reader.h"
	#include <vector>
	#include <iostream>
	
	using OpenPST::QC::SaharaXmlReader;
	using OpenPST::QC::SaharaXmlEntry;
	using OpenPST::QC::SaharaXmlReaderError;
	
	void main()
	{
		SaharaXmlReader reader;
		try {
			
			std::vector<SaharaXmlEntry> entries = reader.parse("/path/to/some/sahara.xml");
			
			for (auto &entry : entries) {
				std::cout << entry.imageId << " - " << entry.imagePath << std::endl;
			}
					
		} catch(SaharaXmlReaderError& e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
		
		return 0;
	}
	
#### Handling Errors
`SaharaXmlReader` will always throw an instance of `SaharaXmlReaderError` when something goes wrong.







