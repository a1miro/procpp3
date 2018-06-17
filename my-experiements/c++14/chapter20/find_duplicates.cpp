#include<iostream>
#include<set>
#include<iterator>


int main() {
    using namespace std;

    int a[] = {10,20,30,40,30,50,30};

    multiset<int> ms(a, a+7);

    auto elements = ms.equal_range(30);

    cout << "num of duplicates: " << distance(elements.first, elements.second)  << endl;
    


}
