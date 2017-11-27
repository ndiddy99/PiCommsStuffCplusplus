#include <iostream>
#include <string>
#ifndef __VISION_PACKET__
#define __VISION_PACKET__
#include "VisionPacketHandler.cpp"
using namespace std;

int main() {
   // VisionPacket packet("wew",20);
    //cout << packet.getVal() << endl;
    vector<VisionPacket> visionPackets;
    visionPackets=VisionPacketHandler::decodeVisionPacket("wew:1!lad:2!");
    cout << visionPackets.data()->outputPacket() << endl;
	cout << VisionPacketHandler::outputvisionpacket(visionPackets) << endl;
	return 0;
}
#endif
