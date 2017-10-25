#include<iostream>
using std::cout;
using std::endl;

int globalVar;


int main() {
    int localVar;

    // Global variable always intialised by zeroes;
    cout << "globalVar = " << globalVar << endl;
    // Standard does not guarantee that local variables
    // will be initialised
    cout << "localVar = " << localVar << endl;

    return 0;
}
