#include<iostream>
#include<memory>

using namespace std;

template<typename T> void foo(T&& param) {
    cout << "++" << __FUNCTION__ << " : " << __LINE__ << endl;
    cout << "param is a universal reference" << endl;
    //cout << "param = " << reinterpret_cast<int>(param) << endl;
    cout << "--" << __FUNCTION__ << " : " << __LINE__ << endl;
}

struct Integer {
    Integer(int v) :v_(unique_ptr<int>(new int(5))) {;}

    unique_ptr<int> v_;
};

template<> void foo(Integer&& param) {
    cout << "++" << __FUNCTION__ << " : " << __LINE__ << endl;
    cout << "param is rvalue reference" << endl;
    //cout << "param = " << reinterpret_cast<int>(param) << endl;
    cout << "--" << __FUNCTION__ << " : " << __LINE__ << endl;
}

void bar(Integer&& param) {
    cout << "++" << __FUNCTION__ << " : " << __LINE__ << endl;
    cout << "param is rvalue reference" << endl;
    //cout << "param = " << reinterpret_cast<int>(param) << endl;
    cout << "--" << __FUNCTION__ << " : " << __LINE__ << endl;
}

int main() {
    Integer&& rv = Integer(5); // rvalue reference
    auto&& uref = rv;          // universal reference

    Integer v(5);

    foo<Integer>(std::forward<Integer>(rv)); // rvalue reference
    foo<Integer>(std::move(v)); //rvalue reference

    bar(std::forward<Integer>(uref));
    bar(std::move(v));

    foo(1);
    int k = 2;
    foo(k);
    
    return 0;
}

