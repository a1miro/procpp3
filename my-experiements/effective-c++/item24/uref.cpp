#include<iostream>
using namespace std;

template<typename T> void f(T&& param) {
cout << "++" << __FUNCTION__ << " : " << __LINE__ << endl;
cout << "param is a universal reference" << endl;
cout << "param = " << param << endl;
cout << "--" << __FUNCTION__ << " : " << __LINE__ << endl;
}

struct Integer {
    Integer(int v) :v_(v) {}}
    Integer(const Integer&) = default;
    Integer& operator=(const Integer&) = default;
    Integer(Integer&&) = default;
    Integer& operator=(Integer&&) = default;

    int v_;
}

int main() {
    //int&& v = int(5); // rvalue reference
    //int&& uref = v;   // universal reference

    //f<int>(rv);
    //f<int>(5);



    return 0;
}

