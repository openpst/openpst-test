#pragma once

namespace OpenPST {
    namespace Serial {
        class MockSerial
        {
        	
            public:
            	std::vector<uint8_t> resp
                /**
                * Constructor
                */ 
                MockSerial(const std::string& port, int baudrate, int timeout);
                
                /**
                * Destructor
                */
                ~MockSerial();
            private:
                    // no copy
                  MockSerial(const MockSerial&);

            public:
                void setMockResponse(std::vector<uint8_t>& data);

                void write(std::vector<uint8_t>& data);

                void read(std::vector<uint8_t>& data, size_t amount);

                bool isOpen();

                void open();

                size_t available();

        };
    }
}

