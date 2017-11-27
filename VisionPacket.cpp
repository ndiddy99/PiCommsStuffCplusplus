#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class VisionPacket {
private:
	string name;
	int value;

public:
	VisionPacket(string name, int value){
	    this->name = name;
	    this->value = value;
	}

	const string outputPacket() { //string concatenation in c++ is shit
		stringstream packetStream;
		packetStream << name << ":" << value << "!";
		return packetStream.str();
	}
	const int getVal() {
	    return value;
	}
};
