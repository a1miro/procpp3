#include<iostream>


struct CircleStruct 
{
    int x, y;
    double radius;
};

class CircleA
{
    public:
        int x,y;
        double radius;
};

class CircleB
{
    public:
    CircleB(int x, int y, double radious):_x(x), _y(y), _radious(radious){};

    private:
        int _x;
        int _y;
        double _radious;
};



int main() 
{
    // Since C++11
    CircleStruct circle0 = {10, 10, 2.5};
    CircleA circle1 = {10, 10, 2.5}; 
    CircleB circle2 = {10, 10, 2.5};

    // or equally the same by skipping '='
    CircleStruct circle3 {10, 10, 2.5};
    CircleA circle4 {10, 10, 2.5}; 
    CircleB circle5 {10, 10, 2.5};

    // Variable initialization
    int a = 3;
    int b(3);
    int c = {3}; // uniform initialization
    int d{3};    // uniform initialization

    // COMPILER ERROR - narrowing from double to int
    // int x = {3.14};
    //

    // Direct list initialisation
    auto  e = {11};    // initializer_list<int>
    auto  f = {11,22}; // initializer_list<int>

    // COMPILER ERROR - different type of elements 
    // auto g = {11, 22.33} 



    
    



    return 0;
}
