#include <iostream>
#include <vector>
#include <atomic>

#include <boost/type_index.hpp>

class Widget {

    public:
        Widget() {}
        Widget(int i) : x(i), y(i) {}

    public:
        int x{0}; // fine
        int y=0;  // also fine
        //int z(0); // error!
};



int main() {
    using std::cout;
    using std::endl;
    using boost::typeindex::type_id_with_cvr;

    


    std::atomic<int> ai1{0}; // fine
    std::atomic<int> ai2(0); // fine
    //std::atomic<int> ai3 = 0; // error
    

    double a(1.0), b(2.0), c(3.0);

    //int sum1 { a + b + c }; // error, narrowing conversation 
    int sum2 ( a + b + c ); // okay legacy
    int sum3 = a + b + c;   // okay legacy 


    Widget w1(10); // call Widget ctor with argument 10
    cout << "w1.x = " << w1.x << endl;
    cout << "w1.y = " << w1.y << endl;

    Widget w2(); // w2 is a function!!!!
    //cout << "w2.x = " << w2.x << endl; // error, non-class type
    //cout << "w2.y = " << w2.y << endl; // error, non-class type
    cout << "w2 type:" << type_id_with_cvr<decltype(w2)>().pretty_name() << endl;

    Widget w3{}; // calls Widget ctor with no args
    cout << "w3.x = " << w3.x << endl; 
    cout << "w3.y = " << w3.y << endl;


    std::vector <int> v1(10, 20); // use of non-std::initializer_list ctor
    std::vector <int> v2{10, 20}; // std::initializer_list ctor

    cout << "v1.size = " << v1.size() << endl;
    cout << "v2.size = " << v2.size() << endl;

return 0;
}
