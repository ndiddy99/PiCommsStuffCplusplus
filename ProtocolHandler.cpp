#include <string>
#include <iostream>
using namespace std;
	/*
	 * Example packet of the protocol we're using:
	 *  <Name1:1!Name2:2!Name3:3!>
	 *  pretty much, the greater than/less than symbols frame the packets
	 *  the "Namex" text is the variable name(can be any string)
	 *  the numbers are the values stored by the values
	 *  the exclamation points separate values
	 */
class ProtocolHandler {
private:
	string buffer;
	string lastCompletedString;
public:
	ProtocolHandler() {
		buffer="";
		lastCompletedString="";
	}

	void addToBuffer(string stringToAppend) {
		int stringLength=stringToAppend.length();
		for (int i=0; i < stringLength; i++) {
			char charToAppend=stringToAppend.at(i);
			if (charToAppend != '<') {
				if (charToAppend=='>')
					lastCompletedString=buffer;
				else
					buffer+=charToAppend;
			}
		}
	}
	string getLastString() {
		return lastCompletedString;
	}
};
