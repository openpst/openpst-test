####
## Makefile for openpst/readmbn
####

all: default

default:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./include \
		-I./../libopenpst/include \
		-I./../libopenpst/lib/serial/include \
		-I./src -std=gnu++11 $(CXX_FLAGS) \
		./../libopenpst/src/qualcomm/hdlc_encoder.cpp \
		./../libopenpst/src/util/hexdump.cpp \
		./src/serial/serial_queue.cpp \
		./src/serial/packet.cpp \
		./src/serial/packet_test.cpp \
		./src/main.cpp -o build/test 
clean:
	rm -rf build/*