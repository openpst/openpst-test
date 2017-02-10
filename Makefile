####
## Makefile for openpst/readmbn
####

all: default

old:
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
		./src/old_serial.cpp -o build/old_serial 
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
		-DWITHOUT_SERIAL_PACKET_WRITER_DEBUG \
		-DWITHOUT_SERIAL_PACKET_WRITER_DEBUG_RX \
		-DWITHOUT_SERIAL_PACKET_WRITER_DEBUG_TX \
		-DSERIAL_DEBUG \
		-DSERIAL_DEBUG_TX \
		-DSERIAL_DEBUG_RX \
		./../libopenpst/src/qualcomm/hdlc_encoder.cpp \
		./../libopenpst/src/util/hexdump.cpp \
		./src/transport/packet.cpp \
		./src/transport/serial.cpp \
		./src/transport/serial_packet_writer.cpp \
		./src/qualcomm/packet/dm_spc_request.cpp \
		./src/qualcomm/packet/dm_spc_response.cpp \
		./src/qualcomm/packet/streaming_dload_hello_request.cpp \
		./src/qualcomm/packet/streaming_dload_hello_response.cpp \
		./src/new_serial.cpp -o build/new_serial -Bstatic -lboost_system
socket:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./include \
		-I./../libopenpst/include \
		-I./src \
		-std=gnu++11 $(CXX_FLAGS) \
		-DNO_POD_PACKET_STRUCTURES \
		-DBOOST_SYSTEM_NO_DEPRECATED \
		-DSERIAL_DEBUG \
		-DSERIAL_DEBUG_TX \
		-DSERIAL_DEBUG_RX \
		./../libopenpst/src/util/hexdump.cpp \
		./src/transport/packet.cpp \
		./src/transport/tcp.cpp \
		./src/transport/tcp_serial_client.cpp \
		./src/socket.cpp -o build/socket -Bstatic -lpthread -lboost_system -lboost_thread

server:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./include \
		-I./../libopenpst/include \
		-I./src \
		-std=gnu++11 $(CXX_FLAGS) \
		-DNO_POD_PACKET_STRUCTURES \
		-DBOOST_SYSTEM_NO_DEPRECATED \
		-DSERIAL_DEBUG \
		-DSERIAL_DEBUG_TX \
		-DSERIAL_DEBUG_RX \
		./../libopenpst/src/util/hexdump.cpp \
		./src/transport/packet.cpp \
		./src/transport/serial.cpp \
		./src/server/tcp_serial_server.cpp \
		./src/server.cpp -o build/server -Bstatic -lpthread -lboost_system -lboost_thread

clean:
	rm -rf build/*