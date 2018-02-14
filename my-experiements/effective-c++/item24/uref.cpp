#include<iostream>
#include<memory>

using namespace std;

template<typename T> void foo(T& param) {
    cout << "param is a lvalue reference" << endl;
}

template<typename T> void foo(T&& param) {
    //cout << "++" << __FUNCTION__ << " : " << __LINE__ << endl;
    cout << "param is a universal reference" << endl;
    //cout << "param = " << reinterpret_cast<int>(param) << endl;
    //cout << "--" << __FUNCTION__ << " : " << __LINE__ << endl;
}

struct Integer {
    Integer(int v) :v_(unique_ptr<int>(new int(5))) {;}

    unique_ptr<int> v_;
};

template<> void foo(Integer&& param) {
    //cout << "++" << __FUNCTION__ << " : " << __LINE__ << endl;
    cout << "param is rvalue reference" << endl;
    //cout << "param = " << reinterpret_cast<int>(param) << endl;
    //cout << "--" << __FUNCTION__ << " : " << __LINE__ << endl;
}

void bar(Integer&& param) {
    //cout << "++" << __FUNCTION__ << " : " << __LINE__ << endl;
    cout << "param is rvalue reference" << endl;
    //cout << "param = " << reinterpret_cast<int>(param) << endl;
    //cout << "--" << __FUNCTION__ << " : " << __LINE__ << endl;
}

int main() {
    Integer&& rv = Integer(5); // rvalue reference
    auto&& uref = Integer(5);  // universal reference

    Integer v(5);

    cout << "foo<Integer>(std::forward<Integer>(rv)): ";
    foo<Integer>(std::forward<Integer>(rv)); // rvalue reference

    cout << "foo<Integer>(std::move(v)): ";
    foo<Integer>(std::move(v));              // rvalue reference
    foo<Integer>(v);                         // universal reference, compiler error?

    cout << "bar(std::forward<Integer>(uref)): ";
    bar(std::forward<Integer>(uref));

    cout <<" bar(std::move(v)): ";
    bar(std::move(v));

    cout <<" foo(1): ";
    foo(1);

    cout << " foo(move(1)): ";
    foo(move(1));

    int k = 2;
    cout <<" foo(k): ";
    foo(k);

    cout <<" foo(move(k)): ";
    foo(move(k));
    
    return 0;
}

