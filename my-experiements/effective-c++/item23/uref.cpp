#include<cstdint>
#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

auto profile = [](auto&& func, auto&&... params) {
    //high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::forward<decltype(func)>(func)(
            std::forward<decltype(params)>(params)...
            );

    //high_resolution_clock::time_point t2 = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    //cout << "duration is " << duration << endl;
};

void factorial(uint32_t n) {
    uint64_t s = 1;
    for (int i = 1; i <= n; i++) {
        s *= i;
    }

    //cout << "factorial of " << n << " is equal " << s << endl;
}

int main(int argc, char** argv) 
{
    using namespace std;
#if 0
    int var1 = 6;
    auto&& var2 = var1;

    int var3 = 7;
    //int&& var4 = 5;

    cout << "var2 = " << var2 << endl;
    //cout << "var4 = " << var4 << endl;
    //
    int n = 2;
    profile(factorial, n);
    n=3;
    profile(factorial, n);
    n=5;
    profile(factorial, n);
    n=10;
    profile(factorial, n);
    n=20;
    profile(factorial, n);
#endif

    cout << "================== Direct call to the function ===============================" << endl;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000000; i ++) {
        factorial(5);
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << " takes this duration : " << duration << endl;

    cout << "================== Call to the function template ===============================" << endl;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000000; i ++) {
        factorial(5);
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << " takes this duration : " << duration << endl;


    return 0;
}
