#include<iostream>
#include<vector>
#include<memory>

struct CircleStruct {
    int x, y;
    double radius;
};

class CircleClass {

    public:
        CircleClass(int x, int y, double radius) 
            : mX(x), mY(y), mRadius(radius) {}

    private:
        int mX, mY;
        double mRadius;
};


int func(int i) { return i;}


class Array {
    public:
        Array() : mArray{0, 1, 2, 3} {}

        void print() {
            for (auto& i : mArray) {
                std::cout << i << ", ";
            }
            std::cout << std::endl;
        }

    private:
        int mArray[4];
};

int main() {

    // Pre C++11 initialisation:
    CircleStruct myCircle1 = {10,10, 2.5};
    CircleClass myCircle2(10,10, 2.5); // C-tor initialisation

    // Since C++11
    CircleStruct myCircle3 = {10, 10, 2.5};
    CircleClass myCircle4 = {10, 10, 2.5};

    // equal sign might be emitted 
    CircleStruct myCircle5 {10, 10, 2.5};
    CircleClass myCircle6 {10, 10, 2.5};


    // Elementary type initialisation
    int a = 3;
    int b(3);
    int c = {3};
    int d{3};

    // Empty init to 0
    int e{};


    // C++ automatically performs narrowing, it truncates 3.14 to 3
    int x = 3.14;
    func(3.14);


    //int x1 = {3.14}; // Error
    //func({3.14});   // Error

    // Uniform vector initialisation 
    std::vector<std::string> work_days = {"Mon", "Tue", "Wed", "Thu", "Fri"};

    std::shared_ptr<Array> array = std::make_shared<Array>();
    array->print();

    


    return 0;
}

