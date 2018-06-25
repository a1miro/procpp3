#include<iostream>
#include<string_view>
#include<string>

using namespace std;

int main() 
{
    string str = "Hello";
    string_view sv = " world";
    auto result = str + sv.data();

    return 0;
}
