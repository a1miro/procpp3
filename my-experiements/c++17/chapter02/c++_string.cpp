#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    string myString("hello");

    printf("%s\n", myString.c_str());

    myString[1] = 'e';
    cout << myString << endl;

    auto string1 = "Hello World"; // string1 is const char*
    auto string2 = "Hello World"s; //user-defined 's' makes string2 to be std::string

    // Number to string
    long double d = 3.14L;
    cout << "d = " << to_string(d) << endl;

    // String to Number
    string to_parse = "    123 USD";
    size_t index = 0;
    int value = stoi(to_parse, &index);
    cout << "Parsed value: " << value << endl;
    cout << "unparsed part: " << to_parse.substr(index) << endl;

    to_parse = "0x10AD Hex";
    index = 0;
    value = stoi(to_parse, &index, 16);
    cout << "Parsed value: 0x" << hex << uppercase << value << dec << nouppercase << endl;
    cout << "unparsed part: " << to_parse.substr(index) << endl;



    




    



    return 0;
}
