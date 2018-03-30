#include<iostream>
#include<initializer_list>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::string;

template <typename T>
class Array {
    public:
        Array(T&& a1, T&& a2, T&& a3) {
            cout << "Array(a1, a2, a3)" << endl;
            mArray.push_back(a1);
            mArray.push_back(a2);
            mArray.push_back(a3);
        }

        Array(std::initializer_list<T> list) {
            cout << "Array(initializer_list)" << endl;
            for (auto&& v: list) {
                mArray.push_back(v);
            }
        }

        void print() {
            for (auto& v : mArray) {
                cout << v << ", ";
            }
            cout << endl;
        }

    private:
        std::vector<T> mArray;
};

int main() {
    Array<string> weekend_days{"Sat", "Sun"};
    Array<int> prime_numbers{1,3,5,7,11,13,17};
    Array<int>({1,2,3,4,5}).print();
    Array<int>{5,4,3,2,1}.print();

    weekend_days.print();
    prime_numbers.print();

    Array<int>{1,2,3}.print();



    return 0;
}
