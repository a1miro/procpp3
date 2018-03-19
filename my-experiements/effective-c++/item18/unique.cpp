#include<iostream>
#include<memory>


int main() {

    using std::cout;
    using std::endl;
    using std::unique_ptr;

    // Creating std::unique_ptr<T[]>
    unique_ptr<int[]> array(new int[10]);
    auto array1 = std::make_unique<int[]>(10);


    

    

    return 0;
}
