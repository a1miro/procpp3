#include <iostream>
#include <thread>
#include <stdexcept>
#include <exception>
#include <functional>
#include <map>
#include <memory>

using namespace std;

#define TP()  cout << __FUNCTION__ << ":" << __LINE__ << endl;
#if 0
template <typename T, typename... Args> 
decltype(auto) run_async(T* obj, void (T::*func)(Args... args), exception_ptr& err, Args... args)
{
    return move(thread
                    (
                     [obj, func, err, args...]()->void 
                     {
                     TP();
                         try 
                         {
                             (obj->*func)(args...);
                             TP();
                         }
                         catch (...)
                         {
                             //err = current_exception();
                             cout << "Thread exception ..." << endl;
                             TP()
                         }
                     TP();
                     }
                    ));
 
}
#endif

template <typename T> 
auto run_async(T* obj, void (T::*func)(), exception_ptr& err) 
{
    return move(
            thread
                    (
                     [obj, func, err]()->void 
                     {
                     TP();
                         try 
                         {
                             (obj->*func)();
                             TP();
                         }
                         catch (...)
                         {
                             //err = current_exception();
                             cout << "Thread exception ..." << endl;
                             TP()
                         }
                     TP();
                     }
                    )
            );
}

class A
{
    public:
        void print_letters() 
        {
            char last = 'z';
            TP();
            for (char c = 'a'; c < last; c++) 
            {
                cout << c << ", ";
                if(c == last - 3)
                {
                    TP();
                    //throw runtime_error("Exception from print_letters");
                }
            }
            cout << endl;
        }
};

class B 
{
    public:
        void print_numbers() 
        {
            int last = 10;
            TP();
            for (int i = 0; i < last; i++)
            {
                cout << i << ", ";
                if (i == last - 3) 
                {
                    TP();
                    //throw runtime_error("Exception from print_numbers");
                }
            }
            cout << endl;
        }
};


int main() {

    A a;
    B b;
    
    exception_ptr err1;
    exception_ptr err2;

    cout << "Call a-object function async" << endl;
   
    auto t1 = run_async(&a, &A::print_letters, err1);
    auto t2 = run_async(&b, &B::print_numbers, err2);
    t1.join();
    t2.join();

    return 0;
}
