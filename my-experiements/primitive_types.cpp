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

    // Floating-point types
    float myFloat;              // 7  digits
    double myDouble;            // 15 digits 
    long double myLongDouble;   // typically same as double

    myFloat = 12345.678; // rounded to 12345.68
    cout << "myFloat = " << myFloat << endl;

    myDouble = 123456789.01234567;
    cout << "myDouble = " << myDouble << endl;

    float float_0 = 0;
    float float_1_0 = 1.0;
    float float_0_5 = 0.5;
    float float_3_0 = 3;

    //Rvalue reference
    int &&rref = 2 + 3;
    rref ++;
    cout << "rref = " << rref << endl;

    return 0;
}
