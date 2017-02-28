#include<iostream>
#include<string>
#include<cstring>

using namespace std;
//page 102
int main()
{
    auto string1 = "Hello World"; //C-string
    auto string2 = "Hello Worlds"s; //std::string 

    cout << "len(string1)=" << strlen(string1) << endl;
    cout << "len(string2)=" << string2.length() << endl;

    






    return 0;
}
