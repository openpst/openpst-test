
all: default

default:
	if [ ! -d "./build" ]; then mkdir -p build;  fi
	$(CXX) -I./ \
		-I./../../libopenpst/include \
		-I./../../libopenpst/lib/serial/include \
		-I./../../libopenpst/lib/pugixml/src \
		-I./lib/tclap/include \
		-I./src -std=gnu++11 $(CXX_FLAGS) \
		./../../libopenpst/lib/pugixml/src/pugixml.cpp \
		./../../libopenpst/src/qualcomm/streaming_dload_serial.cpp \
		./../../libopenpst/src/qualcomm/sahara_serial.cpp \
		./../../libopenpst/src/qualcomm/hdlc_encoder.cpp \
		./../../libopenpst/src/qualcomm/hdlc_serial.cpp \
		./../../libopenpst/src/qualcomm/sahara_xml_reader.cpp \
		./../../libopenpst/src/qualcomm/raw_program_xml_reader.cpp \
		./../../libopenpst/src/serial/generic_serial.cpp \
		./../../libopenpst/lib/serial/src/serial.cc \
		./../../libopenpst/lib/serial/src/impl/unix.cc \
		./../../libopenpst/lib/serial/src/impl/list_ports/list_ports_linux.cc \
		./../../libopenpst/src/util/hexdump.cpp \
		./../../libopenpst/src/util/string_helper.cpp \
		./../../libopenpst/src/util/math_string_evaluator.cpp \
		./main_sahara.cpp \
		./main_streaming_dload.cpp \
		./main.cpp -o build/openpst-cli 