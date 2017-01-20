####
## Makefile for openpst/readmbn
####

all: default

default:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./ -I./../libopenpst/include -I./../libopenpst/lib/serial/include -I./src -std=gnu++11 $(CXX_FLAGS) \
		./serial_queue.cpp \
		./test_request_packet.cpp \
		./test_response_packet.cpp \
		./main.cpp -o build/test 
clean:
	rm -rf build/*