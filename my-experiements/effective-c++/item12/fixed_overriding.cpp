#include<iostream>
#include<memory>

class Base {

    public:
        virtual void mf1() const {};
        virtual void mf2(int x)  {};
        virtual void mf3() &     {};
        virtual void mf4() const {}; 
};


class Derived: public Base {
    public:
        void mf1() const            override {}; // const was missed
        void mf2(int x)             override {}; // int in base
        void mf3() &                override {}; // lvalue
        void mf4() const            override {}; // must be declared virtual
};


int main() {

    std::unique_ptr<Base> p = std::make_unique<Derived>();

    return 0;
}
