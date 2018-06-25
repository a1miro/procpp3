#include<iostream>
#include<string>
#include<charconv>

using namespace std;

int main() {

    std::string out(10, ' ');
    auto [ptr, ec] = std::to_chars(out.data(), out.data() + out.size(), 12345);
    if (ec == std::errc()) 
    {
        cout << "number: " << ptr << endl;
    }

    return 0;
}
