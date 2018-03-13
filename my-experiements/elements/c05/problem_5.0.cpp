#include<iostream>
#include<limits>


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


    return 0;
}
