#include <iostream>

// Parameter deduction for Case1: 
//  ParamType is a reference/pointer, but not an universal reference
template<typename T> void f(T& param) {
    using namespace std;
    cout << "param = " << param << endl;
}

int main() {

    int x = 27;
    const int cx = x;
    const int& rx = x;

    f(x);   // T is int, param's type is int&
    f(cx);  // T is const int, param's type is const int&
    f(rx);  // T is const int, param's type is const int&

    return 0;
}
