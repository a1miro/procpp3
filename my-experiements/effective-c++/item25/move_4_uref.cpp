#include<iostream>
#include<string>
#include<cstdint>

using namespace std;


// A class that contains a memory resource.  
class MemoryBlock  
{  
    // TODO: Add resources for the class here.  
};  

template <typename T>
void f(const T&&)  
{  
    cout << "In f(const MemoryBlock&). This version cannot modify the parameter." << endl;  
}  

template <typename T>
void f(T&&)  
{  
    cout << "In f(MemoryBlock&&). This version can modify the parameter." << endl;  
}  

int main()  
{ 
    int b;
    f(b);
    f(5);

    const int c = 6;
    f(c);

    MemoryBlock block;  
    const MemoryBlock block1;
    f(block);  
    f(MemoryBlock());
    f(block1);
}  

