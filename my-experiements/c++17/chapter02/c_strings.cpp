#include<iostream>
#include<cstring>

using namespace std;

char* copy_string(const char* original) {
    char* copied = new char[strlen(original) + 1];
    strcpy(copied, original);
    return copied;
}

char* add(const char* str1, const char* str2) 
{
    char* tmp = new char[strlen(str1) + strlen(str2) + 1];
    strcpy(tmp, str1);
    strcat(tmp, str2);
    return tmp;
}

int main() {

    char* hello = copy_string("Hello!");
    char* hello_world = add("Hello", "World");

    cout << "hello_world: " << hello_world << endl;

    // Deallocate buffers
    delete [] hello;
    delete [] hello_world;

    char text1[] = "abcdef";

    cout << "text1: " << text1 << endl;
    cout << "sizeof(text1) = " << sizeof(text1) << endl;
    cout << "strlen(text1) = " << strlen(text1) << endl;

    const char* text2 = "chicken nuggets";
    cout << "text2: " << text2 << endl;
    cout << "sizeof(text2) = " << sizeof(text2) << endl;
    cout << "strlen(text2) = " << strlen(text2) << endl;

    // Example of so-called raw string
    const char* str = R"(Hello "'World!'")";
    cout << "str:" << str << endl;
    
    // COMPILER ERROR - "()" can't be used in the text 
    // const char* str = R"("(Hello World)")";
    
    return 0;
}
