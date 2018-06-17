#include<iostream>
#include<cstdint>
#include<array>

using namespace std;


int main() {

    // c-array zero-initialiation
    int a1[3] = {0};
    // same effect
    int a2[3] = {};
    // explicit initialisation
    int a3[] = {1,2,3};
    // part initialisation, a4[0] = 1, all other elements zeros
    int a4[3] = {1};

    // Old style of getting array size
    cout << "a1 size = " <<  sizeof(a1) / sizeof(a1[0]) << endl;

    // C++17
    cout << "a2 size = " << size(a2) << endl;
    cout << "a3 size = " << size(a3) << endl;
    cout << "a4 size = " << size(a4) << endl;

    // C++17 structured bindings, similar to the tuple/list unpacking in Python 
    array<int,3> coords = {1,2,3};
    auto[x,y,z] = coords;
    cout << "x = " << x << "y = " << y << "z = " << z << endl;


    return 0;
}
