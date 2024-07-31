#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

bitset<8> invertLastTwoBits(bitset<8> n) {
	// Invert the last two bits
	n.flip(0);
	n.flip(1);
	return n;

}

bitset<8> exchange4Bits(bitset<8> n) {
	bitset<8> highNibble = (n >> 4) & bitset<8>("00001111");
    bitset<8> lowNibble = (n << 4) & bitset<8>("11110000");

	bitset<8> swappedByte = highNibble | lowNibble;

	return swappedByte;

}

int main() {
	string message = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";

 	istringstream stream(message);
    string byte;
	vector<bitset<8>> bitsets;

    while (stream >> byte) {
        bitsets.push_back(bitset<8>(byte));
    }


	for (bitset<8>& b : bitsets) {
		b = invertLastTwoBits(b);
		b = exchange4Bits(b);
		unsigned char asciiChar = static_cast<unsigned char>(b.to_ulong());
		cout << asciiChar;


	}

	return 0;
}