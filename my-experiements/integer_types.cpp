#include<iostream>
#include<cstdint>
#include<iomanip>

using std::cout;
using std::endl;
using std::hex;
using std::dec;
using std::uppercase;
using std::setfill;
using std::setw;

int main() {

    cout << "sizeof(char) = "       << sizeof(char)     << endl;
    cout << "sizeof(short) = "      << sizeof(short)    << endl;
    cout << "sizeof(int) = "        << sizeof(int)      << endl;
    cout << "sizeof(long) = "       << sizeof(long)     << endl;
    cout << "sizeof(long long) = "  << sizeof(long long)<< endl;

    cout << "sizeof(int8_t) ="      << sizeof(int8_t)    << endl; 
    cout << "sizeof(int16_t) ="     << sizeof(int16_t)   << endl; 
    cout << "sizeof(int32_t) ="     << sizeof(int32_t)   << endl; 
    cout << "sizeof(int64_t) ="     << sizeof(int64_t)   << endl;

    // Numeric literals
    int myOct = 062; // octal notation 
    int myHex = 0x32FF; // hexademical notation
    int myBin = 0b0001'0101'1010'1111;

    cout << "myBin=0x" << hex << uppercase << setfill('0') << setw(8) << myBin << dec << endl;
    cout << "myHex=0x" << hex << myHex << dec << endl;

    return 0;
}
