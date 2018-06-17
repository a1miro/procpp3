#include<iostream>

class Int {
    public:
        Int(int i): mInt(i) {}
        explicit operator int() const { return mInt;}


    private:
        int mInt;
};




int main() {

    Int c(123);
    //int a = c; // compiler error because operator int() was declared explicit
    int a = static_cast<int>(c);
    auto b = c;

    return 0;
}
