#include<iostream>
#include<memory>

// NO WARNINGS from GCC !!!!!


class Base {

    public:
        virtual void mf1() const {}
        virtual void mf2(int x) {}
        virtual void mf3() & {}
        void mf4() const {}
};


class Derived: public Base {
    public:
        virtual void mf1(){};               // it must be const
        virtual void mf2(unsigned int x){}; // it must be int
        virtual void mf3() && {};           // it must be lvalue reference
        void mf4() const{};                 // it must be declared virtual in b base class
};


int main() {

    std::unique_ptr<Base> p = std::make_unique<Derived>();

    return 0;
}
