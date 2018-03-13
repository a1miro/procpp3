#include<iostream>

using std::cout;
using std::endl;

short parity(unsigned long x) {
    short result = 0;
    while(x) {
        result ^= 1;
        x &= (x-1);
    }
    return result;
}


int main () {

    cout << "parity(0b1011) = " << parity(0b1011) << endl;
    cout << "parity(0b1001) = " << parity(0b1001) << endl;

return 0;
}
