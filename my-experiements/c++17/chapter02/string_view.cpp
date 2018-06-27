#include<iostream>
#include<string_view>
#include<string>

using namespace std;

int main() 
{
    string str = "Hello";
    string_view sv = " world"sv;
    auto result = str + sv.data();

	// remove_prefix and remove_suffix examples
	string_view sv1 = "prefix.helloworld.suffix";
	cout << R"("remove_prefix(len("prefix."))=)"  << sv1.remove_prefix(len("prefix.")) << endl;
	cout << R"("remove_suffix(len("suffix."))=)"  << sv1.remove_suffix(len("suffix.")) << endl;

    return 0;
}
