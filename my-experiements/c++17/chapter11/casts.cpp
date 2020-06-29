#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main()
{
  cout << "C++ casts examples" << endl;

  // non-const to const cast
  char* str = "Hello world!";
  const char* conststr = const_cast<char*>(str);

  string language = "C++";
  // non-const to const cast
  const string& const_language = as_const(language); 
  //oposite const to non-const cast 
  string& non_const_language = const_cast<string&>(const_language);
  
  return 0;
}
