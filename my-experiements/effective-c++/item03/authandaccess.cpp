#include<iostream>
#include<deque>


template<typename Container, typename Index>
decltype(auto) authAndAccess(Container&& c, Index i) {

    return std::forward<Container>(c)[i];
}





int main(int argc, char** argv) {
    using namespace std;

    std::deque<int> d;

    authAndAccess(d,5) = 10;

    auto c = authAndAccess(std::deque<int>({1,2,3,4,5,6}),3);
    cout << "c = " << c << endl;

    return 0;
}
