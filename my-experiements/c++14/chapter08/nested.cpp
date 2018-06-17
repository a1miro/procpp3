#include<iostream>
#include<memory>

using namespace std;

class A {
    public:
        class B {
            public:
                B();
                virtual ~B();
        };

        explicit A (B* b);

        virtual ~A(); 

    private:
        unique_ptr<B> b_;
};

using AB=A::B;

AB::B() { 
    cout << "B::ctor" << endl;
}
AB::~B() {
    cout << "B::dtor" << endl;
}

A::A (AB* b) : b_(b) {
    cout << "A::ctor" << endl;
}

A::~A() {
    cout << "A::dtor" << endl;
}


int main() {

    A a(new AB);

    return 0;
}
