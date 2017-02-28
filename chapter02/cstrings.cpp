#include<cstring>

char* copyString (const char* str)
{
    char* result = new char [strlen(str) + 1];
    strcpy(result, str);
    return result;
}

int main()
{
    const char* greeting = "Hello C++1.4!";
    const char* copy = copyString(greeting);


    return 0;

}
