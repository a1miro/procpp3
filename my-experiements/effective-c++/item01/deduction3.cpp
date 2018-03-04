#include <iostream>
#include <typeinfo>



template <typename T> 
void f(T param) {
    using namespace std;
    cout << "param: value = " << param;
    cout << ", type:" << typeid(param).name() << endl;
}


int main(int argc, char** argv) {
    int x = 27;
    const int cx = x;
    const int& rx = x;
    const char* const ptr = "Fun with pointers";


    f(x);   
    f(cx);
    f(rx);
    f(ptr);

    return 0;
}
