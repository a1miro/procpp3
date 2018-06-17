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

    //Example of using std::string for number conversation
    string orbits(to_string(686.97));
    orbits += " "; //separation symbol
    orbits += to_string(365.24);

    cout << "orbits: " << orbits << endl;


    //string orbits ("686.97 365.24");
    string::size_type sz;     // alias of size_t

    float mars = stof (orbits,&sz);
    float earth = stof (orbits.substr(sz));
    std::cout << "One martian year takes " << (mars/earth) << " Earth years.\n";

    // Raw strings literal examples
    string greetings = R"(Hello "World"!)";
    string multiline = R"(Line 1
                            Line2 with \t)";
    cout << "greetings: " << greetings << endl;
    cout << "multiline: " << multiline << endl;

    return 0;
}
