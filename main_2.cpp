#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>

void test(std::ifstream& f, size_t amount)
{
	std::vector<uint8_t> data;

	data.resize(amount);

	if (!f.read(reinterpret_cast<char*>(&data[0]), amount)) {
    	std::cout << "Error reading from file. Expected " << amount << " but read " << f.gcount() << std::endl;
    }

    std::cout << "Read " << f.gcount() << " of requested " << amount << " Vector Size: " << data.size() << std::endl;
	
}

void test2(std::ifstream& f, size_t amount)
{
	return test(f, amount);
}

int main(int argc, char* argv[])
{
	std::ifstream f("test/if_test.bin", std::ios::in | std::ios::binary);
	
	f.exceptions ( std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit );

	if (!f.is_open()){
		std::cout << "Could not open file" << std:: endl;
	}

	test(f, 10);

	test2(f, 10);

	return 0;
}
