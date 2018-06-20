#include<iostream>


struct CircleStruct 
{
    int x, y;
    double radius;
}

class CircleClass
{
    private:
        int x,y;
        double radius;
}



int main() 
{
    // Since C++11
    CircleStruct circle2 = {10, 10, 2.5};
    CircleClass circle3 {10, 10, 2.5}; 

    return 0;
}
