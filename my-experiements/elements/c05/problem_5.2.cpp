#include<iostream>
#include<cstdint>
#include<bitset>

template <typename T> 
T swapbits(T& n, size_t i, size_t j)
{
    if (((n >> i) & 1) != ((n >> j) & 1)) {
        return n ^ ((1 << i) | (1 << j));
    }
    return n;
}

template <typename T>
T same_weight_next_number(T& n) {
    return (n & (n -1)) & (n & (n+1));
}

int main() {
    using namespace std;
    uint8_t x = 0b01001001;
    uint8_t r = swapbits(x, 6, 1);
    
    ios::fmtflags f(cout.flags());
    cout << "original:\t"  <<  bitset<8>(x)  << endl;
    cout << "processed:\t" <<  bitset<8>(r)  << endl;
    cout.flags(f);

    x = 0b11110010;
    r = swapbits(x,5,2);

    cout << "original:\t"  <<  bitset<8>(x)  << endl;
    cout << "processed:\t" <<  bitset<8>(r)  << endl;

    x = 0b01011100;
    r = same_weight_next_number(x);
    cout << "Find a closest integer with the same weight" << endl;
    cout << "original:\t"  <<  bitset<8>(x)  << endl;
    cout << "processed:\t" <<  bitset<8>(r)  << endl;



    return 0;
}
