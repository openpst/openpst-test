####
## Makefile for openpst/readmbn
####

all: default

default:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./include \
		-I./scripts/out/ \
		-I./../libopenpst/include \
		-I./../libopenpst/lib/serial/include \
		-I./src -std=gnu++11 $(CXX_FLAGS) \
		./../libopenpst/src/qualcomm/hdlc_encoder.cpp \
		./../libopenpst/src/serial/generic_serial.cpp \
		./../libopenpst/lib/serial/src/serial.cc \
		./../libopenpst/lib/serial/src/impl/unix.cc \
		./../libopenpst/lib/serial/src/impl/list_ports/list_ports_linux.cc \
		./../libopenpst/src/util/hexdump.cpp \
		-DNO_POD_PACKET_STRUCTURES \
		-DSERIAL_PACKET_WRITER_DEBUG \
		./src/serial/packet.cpp \
		./src/serial/serial_packet_writer.cpp \
		./src/main.cpp -o build/test 
serial:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./include \
		-I./scripts/out/ \
		-I./../libopenpst/include \
		-I./../libopenpst/lib/serial/include \
		-I./src \
		-std=gnu++11 $(CXX_FLAGS) \
		-DNO_POD_PACKET_STRUCTURES \
		-DBOOST_SYSTEM_NO_DEPRECATED \
		-DSERIAL_PACKET_WRITER_DEBUG \
		-DSERIAL_DEBUG \
		./../libopenpst/src/qualcomm/hdlc_encoder.cpp \
		./../libopenpst/src/util/hexdump.cpp \
		./src/transport/packet.cpp \
		./src/transport/serial.cpp \
		./src/transport/serial_packet_writer.cpp \
		./src/qualcomm/packet/streaming_dload_hello_request.cpp \
		./src/qualcomm/packet/streaming_dload_hello_response.cpp \
		./src/main2.cpp -o build/serial -Bstatic -lboost_system

clean:
	rm -rf build/*