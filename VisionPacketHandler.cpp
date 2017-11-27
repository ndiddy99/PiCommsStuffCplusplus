#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "stdlib.h"
#include "VisionPacket.cpp"
using namespace std;

class VisionPacketHandler {

public:

	static string outputvisionpacket(vector<VisionPacket> visionPackets) {
		string stringToOutput="<";
		//cout << sizeof(visionPackets) << endl;
		//cout << sizeof(visionPackets[0]) << endl;
		for (int i=0; i < visionPackets.size();i++) {
			stringToOutput+=visionPackets[i].outputPacket();
		}
		stringToOutput+=">";
		return stringToOutput;
	}
	static vector<VisionPacket> decodeVisionPacket(string packetToDecode) {
		static vector<VisionPacket> visionPackets;
//		VisionPacket visionPacket("wew lad",20);
//		visionPackets.push_back(visionPacket);
		//cout << packetToDecode << endl;
		while (packetToDecode.find("!")!= string::npos) {
			string name = packetToDecode.substr(0,packetToDecode.find(":"));
			string stringValue = packetToDecode.substr(packetToDecode.find(":")+1,packetToDecode.find("!")-(packetToDecode.find(":")+1));
			int value=atoi(stringValue.c_str());
			VisionPacket visionPacket(name,value);
			visionPackets.push_back(visionPacket);
			packetToDecode=packetToDecode.substr(packetToDecode.find("!")+1,packetToDecode.length());
		}

		return visionPackets;
	}
};
