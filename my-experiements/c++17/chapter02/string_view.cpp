#include<iostream>
#include<string_view>
#include<string>

using namespace std;

int main() 
{
    string str = "Hello";
    string_view sv = " world"sv;
    auto result = str + sv.data();

    return 0;
}
