#include<iostream>
#include<cstdio>
#include<cstdarg>

using std::cout;
using std::endl;

void myprint1(const char* str, ...) {
    va_list list;
    va_start(list, str);
    vfprintf(stdout, str, list);
    va_end(list);
    cout << endl;
}


void myprint2(int num, ...)  {
    va_list list;
    va_start(list, num);
    for (int i = 0; i < num; ++i) {
        cout << va_arg(list, int) << ", ";
    }
    va_end(list);

    cout << endl;
}

int main() {

    // print weekdays
    myprint1("%s,%s,%s,%s,%s,%s,%s", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun");

    // first 5 prime numbers 
    myprint2(5, 1,3,5,7,11);

    return 0;
}
