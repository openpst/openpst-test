#include "main_sahara.h"

int main_sahara(int argc, char* argv[], CmdLine& args)
{
	UnlabeledValueArg<std::string> programArg("program", "Program to execute", true, ""," string"); // only way I could get multiple mains to work
	ValueArg<std::string> portArg("p", "port", "The port to open. For example /dev/ttyUSB0 or \\.\\COM1", true, "", "string");
    ValueArg<std::string> fileArg("f", "file", "Path to image file to send when requested for one", false, "", "string");
    ValueArg<std::string> saharaXmlArg("x", "sahara-xml", "Path to sahara.xml file", false, "", "string");
    ValueArg<std::string> modeArg("m", "mode", "Specify: auto, transfer, memorydump, or command", false, "auto", "string");

    args.add(programArg);
    args.add(portArg);
    args.add(fileArg);
    args.add(saharaXmlArg);
    args.add(modeArg);

    args.parse(argc, argv);

    try {
    	SaharaSerial port(portArg.value());
    } catch(std::exception& e) {

    }

	return 0;
}