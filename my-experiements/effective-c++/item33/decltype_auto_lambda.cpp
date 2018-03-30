#include<iostream>

using std::cout;
using std::endl;

auto f = [](auto&& param) {
    return std::forward<decltype(param)>(param);
};

int main() {

    int a = 3;

    // passing lvalue reference
    cout << "f(a) = " << f(a) << endl;

    // passing rvalue reference
    cout << "f(int(5)) = " << f(int(5)) << endl;

    return 0;
}

