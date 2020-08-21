#include <iostream>

using namespace std;

string read_name(istream& stream)
{
  string name;
  char next;

  while (stream.get(next))
  {
    name += next;
  }

  return name;
}


int main() {
  cout << "Enter your name: ";
  string name = read_name(cin);
  cout << "your name is " << name << endl;
  return 0;
}
