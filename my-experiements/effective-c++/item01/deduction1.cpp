#include <iostream>

// Parameter deduction for Case1: 
//  ParamType is a reference/pointer, but not an universal reference
template<typename T> void f(T& param) {
    using namespace std;
    cout << "T& param = " << param << endl;
}

template<typename T> void f(const T& param) {
    using namespace std;
    cout << "const T& param = " << param << endl;
}

template<typename T> void f(T* param) {
    using namespace std;
    cout << "T* param = " << *param << endl;
}

template<typename T> void f(const T* param) {
    using namespace std;
    cout << "const T* param = " << *param << endl;
}

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
    const int *cpx = &x;
    int *px = &x;
   
    f(x);   // T is int, param's type is int&
    f(cx);  // T is const int, param's type is const int&
    f(rx);  // T is const int, param's type is const int&
    f(px);
    f(cpx);
    f(&x);
    f(&cx);
    f(27);
   


    return 0;
}
