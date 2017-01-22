#include "qualcomm/packet/streaming_dload_hello_request.h"

using namespace OpenPST::QC;

StreamingDloadHelloRequest::StreamingDloadHelloRequest() : 
StreamingDloadPacket()
{
	
}

StreamingDloadHelloRequest::~StreamingDloadHelloRequest()
{

}

void StreamingDloadHelloRequest::setMagic(const std::string& magic)
{

}

std::string StreamingDloadHelloRequest::getMagic()
{
	return "";
}

void StreamingDloadHelloRequest::setVersion(uint8_t version)
{
	
}

uint8_t StreamingDloadHelloRequest::getVersion()
{
	return 0;
}

void StreamingDloadHelloRequest::setCompatibleVersion(uint8_t compatibleVersion)
{

}

uint8_t StreamingDloadHelloRequest::getCompatibleVersion()
{
	return 0;
}

void StreamingDloadHelloRequest::setFeatureBits(uint8_t featureBits)
{

}

uint8_t StreamingDloadHelloRequest::getFeatureBits()
{
	return 0;
}