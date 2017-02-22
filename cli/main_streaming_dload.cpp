#include "main_streaming_dload.h"

int main_streaming_dload(int argc, char* argv[], CmdLine& args)
{
	UnlabeledValueArg<std::string> programArg("program", "Program to execute", true, ""," string"); // only way I could get multiple mains to work
	ValueArg<std::string> portArg("p", "port", "The port to open. For example /dev/ttyUSB0 or \\.\\COM1", true, "", "string");

    args.add(programArg);
    args.add(portArg);

    args.parse(argc, argv);

    try {
    	StreamingDloadSerial port(portArg.value());
    } catch(std::exception& e) {

    }
	return 0;
}