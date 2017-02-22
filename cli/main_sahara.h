#pragma once 

#include "definitions.h"
#include "tclap/CmdLine.h"
#include "qualcomm/sahara_serial.h"
#include "qualcomm/sahara_xml_reader.h"

using TCLAP::CmdLine;
using TCLAP::SwitchArg;
using TCLAP::ValueArg;
using TCLAP::UnlabeledValueArg;
using TCLAP::ArgException;
using OpenPST::QC::SaharaSerial;
using OpenPST::QC::SaharaSerialError;
using OpenPST::QC::SaharaXmlReader;
using OpenPST::QC::SaharaXmlReaderError;
using OpenPST::QC::SaharaXmlEntry;
using OpenPST::Serial::SerialError;

//void do_hello(SaharaSerial& port, CmdLine& args);
//void do_send_image_file(SaharaSerial& port, CmdLine& args);
//void do_send_image_xml(SaharaSerial& port, CmdLine& args);
//void do_reset(SaharaSerial& port, CmdLine& args);
//void do_done(SaharaSerial& port, CmdLine& args);

int main_sahara(int argc, char* argv[], CmdLine& args);