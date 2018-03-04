#include <iostream>
#include <type_traits>

// Parameter deduction for Case1: 
//  ParamType is a reference/pointer, but not an universal reference
template<typename T> void f(T&& param) {
    using namespace std;
    const char* ref = std::is_lvalue_reference<T&&>::value ? "lvalue" : "rvalue";
    cout << "param = " << param;
    cout << ", " << ref << endl;
}

int main() {

    int x = 27;
    const int cx = x;
    const int& rx = x;

    f(x);   // lvalue: T is int, param's type is int&
    f(cx);  // lvalue: T is const int, param's type is const int&
    f(rx);  // lvalue: T is const int, param's type is const int&
    f(27);      // rvalue
    f(int(27)); // rvalue
    f(*new int(27)); // rvalue

    return 0;
}
