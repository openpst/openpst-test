####
## Makefile for openpst/readmbn
####

all: old serial socket server async

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
		./src/serial/packet_writer.cpp \
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
		./src/transport/packet_writer.cpp \
		./src/qualcomm/packet/dm_spc_request.cpp \
		./src/qualcomm/packet/dm_spc_response.cpp \
		./src/qualcomm/packet/streaming_dload_hello_request.cpp \
		./src/qualcomm/packet/streaming_dload_hello_response.cpp \
		./src/qualcomm/packet/streaming_dload_security_mode_request.cpp \
		./src/qualcomm/packet/streaming_dload_security_mode_response.cpp \
		./src/qualcomm/packet/streaming_dload_open_multi_image_request.cpp \
		./src/qualcomm/packet/streaming_dload_open_multi_image_response.cpp \
		./src/qualcomm/packet/streaming_dload_read_request.cpp \
		./src/qualcomm/packet/streaming_dload_read_response.cpp \
		./src/new_serial.cpp -o build/new_serial -Bstatic -lboost_system

#		-DBOOST_ASIO_ENABLE_HANDLER_TRACKING 
messaged_serial:
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
		./src/transport/messaged_serial.cpp \
		./src/transport/packet_writer.cpp \
		./src/qualcomm/packet/dm_spc_request.cpp \
		./src/qualcomm/packet/dm_spc_response.cpp \
		./src/qualcomm/packet/streaming_dload_hello_request.cpp \
		./src/qualcomm/packet/streaming_dload_hello_response.cpp \
		./src/qualcomm/packet/streaming_dload_security_mode_request.cpp \
		./src/qualcomm/packet/streaming_dload_security_mode_response.cpp \
		./src/qualcomm/packet/streaming_dload_open_multi_image_request.cpp \
		./src/qualcomm/packet/streaming_dload_open_multi_image_response.cpp \
		./src/qualcomm/packet/streaming_dload_read_request.cpp \
		./src/qualcomm/packet/streaming_dload_read_response.cpp \
		./src/messaged_serial.cpp -o build/messaged_serial -Bstatic -lboost_system

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
async:
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
		-DBOOST_ASIO_ENABLE_BUFFER_DEBUGGING \
		./../libopenpst/src/util/hexdump.cpp \
		./src/transport/serial.cpp \
		./src/transport/async_serial.cpp \
		./src/async.cpp -o build/async -Bstatic -lboost_system -lboost_thread

messaged_async:
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
		-DBOOST_ASIO_ENABLE_BUFFER_DEBUGGING \
		./../libopenpst/src/util/hexdump.cpp \
		./src/transport/serial.cpp \
		./src/transport/async_serial.cpp \
		./src/transport/messaged_async_serial.cpp \
		./src/messaged_async.cpp -o build/messaged_async -Bstatic -lboost_system -lboost_thread

all_serial:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./include \
		-I./scripts/out/ \
		-I./../libopenpst/include \
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
		./src/transport/async_serial.cpp \
		./src/transport/messaged_serial.cpp \
		./src/transport/messaged_async_serial.cpp \
		./src/transport/packet_writer.cpp \
		./src/server/tcp_serial_server.cpp \
		./src/qualcomm/packet/dm_spc_request.cpp \
		./src/qualcomm/packet/dm_spc_response.cpp \
		./src/qualcomm/packet/streaming_dload_hello_request.cpp \
		./src/qualcomm/packet/streaming_dload_hello_response.cpp \
		./src/qualcomm/packet/streaming_dload_security_mode_request.cpp \
		./src/qualcomm/packet/streaming_dload_security_mode_response.cpp \
		./src/qualcomm/packet/streaming_dload_open_multi_image_request.cpp \
		./src/qualcomm/packet/streaming_dload_open_multi_image_response.cpp \
		./src/qualcomm/packet/streaming_dload_read_request.cpp \
		./src/qualcomm/packet/streaming_dload_read_response.cpp \
		./src/all.cpp -o build/all -Bstatic -lpthread -lboost_system -lboost_thread

		#./src/transport/tcp_serial_client.cpp
clean:
	rm -rf build/*