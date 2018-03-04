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
    auto&& uref1 = x;
    int&& uref2(int(27));

    f(x);   // lvalue 
    f(cx);  // lvalue 
    f(rx);  // lvalue 
    f(27);  // rvalue
    f(uref1); // lvalue
    f(uref2); // lvalue
    f(int(27)); // rvalue

    return 0;
}
