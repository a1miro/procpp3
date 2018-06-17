#include<iostream>
#include<cstdint>

using namespace std;

struct Integer32 {

    // Binary bitwise operators
    friend Integer32 operator<<(const Integer32& lhs, const int& shift) {
        Integer32 tmp(lhs);
        tmp.val_= tmp.val_ << shift; 
        return tmp;
    }

    friend Integer32 operator>>(const Integer32& lhs, const int& shift) {
        Integer32 tmp(lhs);
        tmp.val_= tmp.val_ >> shift; 
        return tmp;
    }

    // Shorthand bitwise operator assignment
    Integer32& operator<<=(const int& shift) {
        val_ = val_ << shift;
        return *this;
    }

    Integer32& operator>>=(const int& shift) {
        val_ = val_ >> shift;
        return *this;
    }

    friend ostream& operator<<(ostream& stream, const Integer32& obj) {
        stream << obj.val_;
        return stream;
    }

    friend istream& operator>>(istream& stream, Integer32& obj) {
        stream >> obj.val_;
        return stream;
    }


    Integer32() : val_(0) {}
    Integer32(uint32_t val) : val_(val) {}
    
    Integer32(const Integer32& num) : val_(num.val_) {}
    Integer32& operator=(const Integer32& num) {
        val_ = num.val_;
        return *this;
    }




    uint32_t val_;
};



int main() {

    Integer32 num1(0);
    
    cout << "Enter number:"<< endl;
    cin >> num1;
    cout << "num1 = " << num1 << endl;

    cout << "shifting num1 << 3" << endl;
    num1 = num1 << 3;
    cout << "num1 = " << num1 << endl;

    cout << "shifting num1 >> 1" << endl;
    num1 = num1 >> 1;
    cout << "num1 = " << num1 << endl; 

    cout << "num1 <<= 3" << endl;
    num1 <<= 3;
    cout << "num1 = " << num1 << endl;
    return 0;
}
