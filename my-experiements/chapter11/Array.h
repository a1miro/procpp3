#include<iostream>
#include<vector>
#include<initializer_list>
#include<stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::initializer_list;


template <typename T>
class Array {
    public:
        Array(std::initializer_list<T> l) {
            array_.insert(array_.end(), l.begin(), l.end());
        }

        virtual ~Array() = default;

        virtual void print() const {
            for (auto v: array_) {
                cout << v << ", "; 
            }
            cout << endl;
        }

        virtual T& operator[] (int index) {
            return array_[index];
        }

    protected:
        vector<T> array_;
};


template <typename T>
class SafeArray : public Array<T> {
    public:
        SafeArray(std::initializer_list<T> l):Array<T>(l){} 
        virtual ~SafeArray() = default;

        void print() const override {
           //cout << this->array_ << endl;
            for (auto v: this->array_) {
                cout << v << ", "; 
            }
            cout << endl;

        }

        T& operator[] (int index) override {
            if (index >= this->array_.size()) {
                throw std::runtime_error("Index exceeds array size!");
            }
            return this->array_[index];
        }
};

template <typename T>
auto echo(T&& obj) {
    cout << "template echo(T&&)" << endl;
    cout << obj << endl;
    return obj;
}

auto echo(std::string&& obj) {
    cout << "echo(std::string&&)" << endl;
    cout << obj << endl;
    return obj;
}

template <typename T>
auto echo(T& obj) {
    cout << "template echo(T&)" << endl;
    cout << obj << endl;
    return obj;
}

#if 0
auto echo(std::string& obj) {
    cout << "echo(string&)" << endl;
    cout << obj << endl;
    return obj;
}
#endif
