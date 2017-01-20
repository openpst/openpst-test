####
## Makefile for openpst/readmbn
####

all: default

default:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./include -I./../libopenpst/include -I./../libopenpst/lib/serial/include -I./src -std=gnu++11 $(CXX_FLAGS) \
		./src/serial/serial_queue.cpp \
		./src/serial/packet.cpp \
		./src/serial/test_request_packet.cpp \
		./src/serial/test_response_packet.cpp \
		./src/main.cpp -o build/test 
clean:
	rm -rf build/*