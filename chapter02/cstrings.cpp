#include<iostream>
#include<cstring>

using namespace std;

char* copyString (const char* str)
{
    char* result = new char [strlen(str) + 1];
    strcpy(result, str);
    return result;
}

char* appendString(const char* str1, const char* str2, const char* str3)
{
    char* result = new char [strlen(str1) + strlen(str2) + strlen(str3) + 1];
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);

    return result;
}

int main()
{
    const char* greeting = "Hello C++1.4!";
    const char* copy = copyString(greeting);

    cout << appendString("Hello", " ", "world!") << endl;

    return 0;
}
