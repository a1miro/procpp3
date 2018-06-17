#include<iostream>
#include<sstream>
#include<fstream>
#include<ios>
#include<string>


int main() { 
    using namespace std;
    char buf[255];
    
    ostringstream  oss;
    cin.tie(&oss);

    cout << "Enter some text here:" << endl;
    while(cin)
    {
       cin.getline(buf,255);  
    }

    cout << "oss: " << oss.str() << endl;

    return 0;
}


