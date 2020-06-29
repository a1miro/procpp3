#include <iostream>
#include <optional>

using namespace std;


using oint = optional<int>;

oint read_int()
{
  int i;
  cout << "Please enter 2 integers : \n";

  if (cin >> i) {return {i};}

  return {};
}

oint operator+(oint a, oint b)
{
  if (!a or !b) {return {};}
  return {*a + *b};
}



int main()
{
  auto a {read_int()};
  auto b {read_int()};

  auto sum (a + b + 10);

  if (sum) {
    cout << *a << "+" << *b << " + 10 = " << *sum << endl;
  } else {
    cout << "sorry, the input was something else than 2 numbers." << endl;
  }
  
  return 0;
}
