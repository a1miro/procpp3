#include <iostream>
#include <string>

using std::cout;
using std::endl;

std::string getString() {return "Hello world!";};

void swap(int& first, int& second) {}

int main() {

  //std::string& string1 = getString();  // not compoliable
  const std::string& string2 = getString();
  cout << string2 << endl;

  int x = 5, y = 6;
  swap(x, y);
  //swap(3,5);  // it does not compile, expect l-value
  //
  int const& xRef=x;


  return 0;
}

