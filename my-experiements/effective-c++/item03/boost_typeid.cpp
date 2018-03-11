#include <boost/type_index.hpp>
#include<iostream>
#include<deque>

template<typename T>
decltype(auto) func (T&& v, int id) {
    using std::cout;


    return std::forward<T>(v)[id];
}


int main(int argc, char** argv) {
    using std::cout;
    using std::endl;
    using std::deque;
    using boost::typeindex::type_id_with_cvr;

    int& rv = func(deque<int>({1,2,3,4}),2);
    int v = func(deque<int>({1,2,3,4}),3);

    cout << "rv = " << rv << endl;
    cout << "v = " << v << endl;

    cout << "type:" << type_id_with_cvr<decltype(func(deque<int>({1,2,3,4}),2))>().pretty_name() << endl;


    return 0;
}
