#include<iostream>
#include<deque>
#include<typeinfo>

template<typename T> 
class TD;

template<typename T>
decltype(auto) func (T&& v, int id) {

    return std::forward<T>(v)[id];
}

int main(int argc, char** argv) {
    using namespace std;

    int a = 3;
    int *pa = &a;
    const int *cpa = &a;

    //TD<decltype(cpa)> Type;

    std::deque<int> array = {1,3,4,5,6};
    
    //TD<decltype(func(array,2))> Type;
    //auto v = func(array,2);

    
    //TD<decltype(func(deque<int>({1,2,3,4}),2)> Type;
    //func(array,2) = 10;
    cout << "array[2] = " << func(deque<int>({1,2,3,4}),2) << endl;

    cout << "type:" << typeid(func(deque<int>({1,2,3,4}),2)).name() << endl;
    



    return 0;
}
