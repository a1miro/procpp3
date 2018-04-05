#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool is_palindrom(const string& str) {
    size_t i = 0, j =  str.size() - 1;
    while(i < j) {
        if (tolower(str[i++]) != tolower(str[j--])) { 
            cout << "missmatch i=" << i << ", j=" << j << endl;
            return false;
        }
    }

    return true;
}

int main() {
    string str1("iTopiNonAvevanoNipoti"); 
    string str2("iGattiNonAvevanoCugini");

    //transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    //transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    

    cout << "str1: " << is_palindrom(str1) << endl;
    cout << "str2: " << is_palindrom(str2) << endl;

    return 0;
}
