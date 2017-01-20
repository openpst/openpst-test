#include "serial/serial_queue.h"

using namespace OpenPST::Serial;

SerialQueue::SerialQueue()
{

}

SerialQueue::~SerialQueue()
{
	
}


void SerialQueue::add(Packet* p)
{
	if (p != nullptr) {
		queue.push_back(p);
	}
}

bool SerialQueue::has(Packet* p)
{
	if (p == nullptr) {
		return false;
	}

	/*for (auto q : queue.begin()) {
		if (q == p) {
			return true;
		}
	}*/

	return false;
}

int SerialQueue::count()
{
	return queue.size();
}