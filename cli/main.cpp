#include "definitions.h"
#include "main_sahara.h"
#include "main_streaming_dload.h"
#include "tclap/CmdLine.h"
#include <string>

int main(int argc, char* argv[])
{
	if (argc < 2) {
		// show help
		return 0;
	}

	CmdLine args("openpst-cli", ' ', "0.1"); 
	
	std::string program(argv[1]);

	if (program.compare("sahara") == 0) {
		return main_sahara(argc, argv, args);
	} else if (program.compare("streaming-dload") == 0) {
		return main_streaming_dload(argc, argv, args);
	} else {
		// show help
	}
   
	return 0;
}