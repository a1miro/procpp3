#include <iostream>
#include <thread>
#include <stdexcept>
#include <exception>
#include <atomic>
#include <utility>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

#define TP()  cout << __FUNCTION__ << ":" << __LINE__ << endl;

template <typename T, typename... Args> 
auto run_async(T* obj, auto (T::*func)(Args... args), exception_ptr& err, Args... args) 
{
    return move(
            thread
                    (
                     [obj, func, args...](exception_ptr& err)->void 
                     {
                         try 
                         {
                             (obj->*func)(args...);
                         }
                         catch (...)
                         {
                             err = current_exception();
                             cout << "Thread exception ..." << endl;
                         }
                     },
                     ref(err)
                    )
            );
}

template <typename T> 
auto run_async(T* obj, auto (T::*func)(), exception_ptr& err) 
{
    return move(
            thread
                    (
                     [obj, func](exception_ptr& err)->void 
                     {
                         try 
                         {
                             (obj->*func)();
                         }
                         catch (...)
                         {
                             err = current_exception();
                             cout << "Thread exception ..." << endl;
                         }
                     },
                     ref(err)
                    )
            );
}


struct A { int a[100]; };
struct B { int x, y; };

struct C {
    C() : counter_(0) {}
    C(const C& c) {this->counter_ = c.counter_.load();}

    void increment() { cout << "increment: " << ++counter_ << '\n'; this_thread::sleep_for(300ms);}
    void decrement() { cout << "decrement: " << --counter_ << '\n'; this_thread::sleep_for(300ms);}
    
    C& operator++() { cout << "increment: "  << ++counter_ << '\n'; return *this;}
    C& operator--() { cout << "increment: "  << --counter_ << '\n'; return *this;}
    
    C operator++(int) 
    {
        C* tmp = new C();
        tmp->counter_ = counter_++;
        return *tmp;
    }
    C operator--(int) { 
        C* tmp = new C();
        tmp->counter_ = counter_++;
        return *tmp;
    }


    atomic_int counter_;
};

int main() {

    cout << boolalpha
              << "std::atomic<A> is lock free? "
              << atomic<A>{}.is_lock_free() << '\n' 
              << "std::atomic<B> is lock free? "
              << atomic<B>{}.is_lock_free() <<  endl;

    std::vector<thread> threads;
    exception_ptr err;
    C c;

    for (int t = 0; t < 20; t++) 
    {
        threads.emplace_back(run_async(&c, &C::operator++, err));
        threads.emplace_back(run_async(&c, &C::operator++, err));
        threads.emplace_back(run_async(&c, &C::operator++, err));
        threads.emplace_back(run_async(&c, &C::operator--, err));
    }

    for (auto&& t : threads) 
    {
        t.join();
    }

    return 0;
}
