#include<iostream>
#include<initializer_list>

using namespace std;

template <typename T> 
auto median(initializer_list<T> items) 
{
    T sum = 0;
    size_t count = 0;
    for (auto i : items) {
        sum += i;
        count ++;
    }

    return sum/count;
}



int main() {

    auto md = median({1,2,3,4,5,6,7,8,9});
    auto mixed = median({1,2,3,0});
    cout << "median = " << md << endl;

    return 0;
}
