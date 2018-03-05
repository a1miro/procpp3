#include <iostream>
#include <typeinfo>
#include <utility>

// return size of an array as a compile-time constant. 
// print type info of the type T
template <typename T, std::size_t N> 
constexpr std::size_t arraySize(T (&a)[N]) noexcept {
    using namespace std;
    cout << "T (&a) [N]" << endl;
    cout << "type: " << typeid(a).name() << endl; 

    return N;
}

template <typename T, std::size_t N> 
constexpr std::size_t arraySize(T (&&a)[N]) noexcept {
    using namespace std;

    cout << "T (&&a) [N]" << endl;
    cout << "type: " << typeid(a).name() << endl; 
    int array[N](std::forward<T>(a));

    return N;
}



int main(int argc, char** argv) {
    using namespace std;

    const char name[] = "J.P. Briggs"; // type is const char[13]
    const char *pname = name;          // arrays decays to pointer

    int keyVals[] = {1, 3, 7, 9, 11};
    int mappedVals1[arraySize(keyVals)];
    int mappedVals2[arraySize({1,3,4,5,6,7,8})];
    int predefined[5];

    // the line below would not compile 
    // cout << "size(mappedVals) = " << arraySize(mappedVals) << endl; 
    cout << "size(predefined) = " << arraySize(predefined) << endl;

    return 0;
}
