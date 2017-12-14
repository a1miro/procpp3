#include<iostream>
using namespace std;

// Increment value using lvalue reference parameter
void incr(int& value)
{
    cout << "increment with lvalue reference" << endl;
    ++value;
    cout << "value = " << value << endl;
}

// Increment value using rvalue reference parameter
void incr(int&& value) 
{
    cout << "increment with rvalue reference" << endl;
    ++value;
    cout << "value = " << value << endl;
}

template<typename T>
void incr_wrapper(T&& param) {
    incr(std::forward<T>(param));
}

int main() {
    int a = 1;
    int b = 2;
    int& ra = a;            // just a reference

    int&& rvref1 = 5;       // rvalue reference
    int&& rvref2 = int(5);  // rvalue reference

    cout << "incr(a), expected: lvalue reference" << endl;
    incr(a);                // just a reference

    cout << "incr(a+b), expected: rvalue reference" << endl;
    incr(a+b);              // rvalue reference

    cout << "incr(10), expected: rvalue reference" << endl;
    incr(10);               // rvalue reference

    cout << "incr(rvref1), expected: lvalue reference" << endl;
    incr(rvref1);           // rvalue reference

    cout << "incr(rvref2), expected: lvalue reference" << endl;
    incr(rvref2);           // rvalue reference

    cout << "incr(b), expected: lvalue reference" << endl;
    incr(b);                        

    cout << "incr(std::move(b), expected: rvalue reference" << endl;
    incr(std::move(b));             


    cout << "incr(std::forward<int>(a)), expected: rvalue reference" << endl;
    incr(std::forward<int>(a));    


    cout << "incr(std::forward<int>(rvref1)), expected: rvalue reference" << endl;
    incr(std::forward<int>(rvref1));// rvalue reference

    cout << "incr_wrapper(a), expected: lvalue reference" << endl;
    incr_wrapper(a);

    cout << "incr_wrapper(move(a)), expected: rvalue reference" << endl;
    incr_wrapper(move(a));

    cout << "incr_wrapper(rvref1), expected: rvalue reference" << endl;
    incr_wrapper(rvref1);

    cout << "incr_wrapper(rvref2), expected: rvalue reference" << endl;
    incr_wrapper(rvref2);

    return 0;
}
