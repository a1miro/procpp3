#include <boost/type_index.hpp>
#include<iostream>
#include<deque>

template<typename T>
decltype(auto) func (T&& v, int id) {

    return std::forward<T>(v)[id];
}


int main(int argc, char** argv) {
    using std::cout;
    using std::endl;
    using std::deque;
    using boost::typeindex::type_id_with_cvr;


    cout << "type:" << typeid(func(deque<int>({1,2,3,4}),2)).name() << endl;
    cout << "type:" << type_id_with_cvr<decltype(func(deque<int>({1,2,3,4}),2)>().pretty_name() << endl;


    return 0;
}
