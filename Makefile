####
## Makefile for openpst/readmbn
####

all: default

default:
	if [ ! -d "./build" ]; then mkdir build;  fi
	$(CXX) -I./include \
		-std=gnu++11 $(CXX_FLAGS) \
		-DNO_POD_PACKET_STRUCTURES \
		-DBOOST_SYSTEM_NO_DEPRECATED \
		-DWITHOUT_SERIAL_PACKET_WRITER_DEBUG \
		-DWITHOUT_SERIAL_PACKET_WRITER_DEBUG_RX \
		-DWITHOUT_SERIAL_PACKET_WRITER_DEBUG_TX \
		-DSERIAL_DEBUG \
		-DSERIAL_DEBUG_TX \
		-DSERIAL_DEBUG_RX \
		-DSAHARA_CLIENT_DEBUG \
		-DSTREAMING_DLOAD_CLIENT_DEBUG \
		./src/qualcomm/hdlc_encoder.cpp \
		./src/util/hexdump.cpp \
		./src/transport/packet.cpp \
		./src/transport/serial.cpp \
		./src/transport/async_serial.cpp \
		./src/transport/messaged_serial.cpp \
		./src/transport/messaged_async_serial.cpp \
		./src/transport/packet_transporter.cpp \
		./src/server/tcp_serial_server.cpp \
		./src/qualcomm/packet/sahara_*.cpp \
		./src/qualcomm/packet/streaming_dload_*.cpp \
		./src/qualcomm/sahara_client.cpp \
		./src/qualcomm/streaming_dload_client.cpp \
		./src/qualcomm/hdlc_packet_transporter.cpp \
		./src/main.cpp -o build/test -lpthread -lboost_system -lboost_thread


		#./src/transport/tcp_serial_client.cpp
clean:
	rm -rf build/*