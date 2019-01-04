#include <iostream>
#include <limits>
#include <cmath>


int main() {
    using std::cout;
    using std::endl;


    cout << "C++ limits:" << endl;
    cout << "min(int) = " << std::numeric_limits<int>::min() << endl;
    cout << "max(int) = " << std::numeric_limits<int>::max() << endl;

    cout << "min(long) = " << std::numeric_limits<long>::min() << endl;
    cout << "max(long) = " << std::numeric_limits<long>::max() << endl;

    cout << "min(long long) = " << std::numeric_limits<long long>::min() << endl;
    cout << "max(long long) = " << std::numeric_limits<long long>::max() << endl;

    cout << "min(float) = " << std::numeric_limits<float>::min() << endl;
    cout << "max(float) = " << std::numeric_limits<float>::max() << endl;

    cout << "min(double) = " << std::numeric_limits<double>::min() << endl;
    cout << "max(double) = " << std::numeric_limits<double>::max() << endl;

    cout << "infinity(double) = " << std::numeric_limits<double>::infinity() << endl;


    double result = 1.5/0;
    cout << "isinf(result) = " << std::isinf(result) << endl;
    
    result += 1.5;
    cout << "isinf(result) = " << std::isinf(result) << endl;

    result = result / result;
    cout << "isinf(result) = " << std::isinf(result) << endl;
    cout << "isnan(result) = " << std::isnan(result) << endl;

    result = 0.0/0.0;
    cout << "isinf(result) = " << std::isinf(result) << endl;
    cout << "isnan(result) = " << std::isnan(result) << endl;

    return 0;
}
