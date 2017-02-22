#pragma once 

#include "definitions.h"
#include "tclap/CmdLine.h"
#include "qualcomm/streaming_dload_serial.h"
#include "qualcomm/raw_program_xml_reader.h"

using TCLAP::CmdLine;
using TCLAP::SwitchArg;
using TCLAP::ValueArg;
using TCLAP::UnlabeledValueArg;
using TCLAP::ArgException;
using OpenPST::QC::StreamingDloadSerial;
using OpenPST::QC::StreamingDloadSerialError;
using OpenPST::Serial::SerialError;

//void do_hello(StreamingDloadSerial& port, CmdLine& args);
//void do_read_flash(StreamingDloadSerial& port, CmdLine& args);
//void do_write_flash(StreamingDloadSerial& port, CmdLine& args);
//void do_auto_write_rawprogram(StreamingDloadSerial& port, CmdLine& args);
//void do_auto_write_partition_txt(StreamingDloadSerial& port, CmdLine& args);
//void do_auto_write_gpt_header(StreamingDloadSerial& port, CmdLine& args);
//void do_erase_flash(StreamingDloadSerial& port, CmdLine& args);
//void do_reset(StreamingDloadSerial& port, CmdLine& args);
//void do_power_down(StreamingDloadSerial& port, CmdLine& args);

int main_streaming_dload(int argc, char* argv[], CmdLine& args);