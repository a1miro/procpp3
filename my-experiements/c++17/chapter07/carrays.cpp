#include <iostream>
#include <exception>
#include <cstdint>
#include <memory>

using std::cerr;
using std::cout;
using std::endl;


class Simple {
    public:
        Simple() {cout << __FUNCTION__<< endl;}
        ~Simple() {cout << __FUNCTION__<< endl;}  
        Simple(const Simple&) = delete;
        Simple& operator=(const Simple&) = delete;
};

int main(int argc, char** argv) 
{
    int* numbers = nullptr;
    Simple* objects = nullptr;
    try {
        numbers = new int[10];
        // When an array of objects is allocated, default ctor is called for
        // each of the object
        objects = new Simple[10];
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        delete [] numbers;
        // the same happened for deleting of the array of objects. The dtor is
        // called for each of the allocated object
        delete [] objects;
    }
    delete [] numbers;
    delete [] objects;

    cout << "Allocating 2d-array" << endl;
    size_t x_size = 2;
    size_t y_size = 2;
    Simple** darray = new Simple* [x_size];
    for (size_t x = 0; x < x_size; ++x) 
    {
        darray[x] = new Simple[y_size];
    }


    cout << "Deallocating 2d-array" << endl;
    for (size_t x = 0; x < x_size; ++x)
    {
        delete [] darray[x];
    }
    delete [] darray;


    x_size = 3;
    y_size = 3;
    size_t z_size = 3;

    cout << "Allocating 3d-array" << endl;
    int*** array3d = new int** [x_size];

    
    for (size_t x = 0; x < x_size; ++x)
    {
        
        array3d[x] = new int* [y_size];
        for (size_t y = 0; y < y_size; ++y)
        {
            
            array3d[x][y] = new int[z_size];
        }
        
    }

    cout << "Initalising 3d-array" << endl;
    for (size_t x = 0; x < x_size; ++x)
        for (size_t y = 0; y < y_size; ++y)
            for (size_t z = 0; z < z_size; ++z)
                array3d[x][y][z] = x*y*z;

    
    cout << "Printing 3d-array" << endl;
    for (size_t x = 0; x < x_size; ++x)
        for (size_t y = 0; y < y_size; ++y)
            for (size_t z = 0; z < z_size; ++z)
                cout << "[" << x << "]["<< y << "][" << z << "] ";

    cout << "Using unique_ptr for C-style arrays" << endl;
    auto simple_objects_array = std::make_unique<Simple[]>(10);


    return 0;
}
