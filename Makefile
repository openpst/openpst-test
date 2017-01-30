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
		./src/qualcomm/packet/streaming_dload_hello_request.cpp \
		./src/qualcomm/packet/streaming_dload_hello_response.cpp \
		./src/qualcomm/packet/streaming_dload_security_mode_request.cpp \
		./src/qualcomm/packet/streaming_dload_security_mode_response.cpp \
		./src/qualcomm/packet/streaming_dload_open_multi_image_request.cpp \
		./src/qualcomm/packet/streaming_dload_open_multi_image_response.cpp \
		./src/main.cpp -o build/test 
clean:
	rm -rf build/*