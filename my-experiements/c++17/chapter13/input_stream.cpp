#include<iostream>

using namespace std;

int main()  {

  int number = 0;
  int sum = 0;

  cout << "Enter numbers (Ctrl+D) to stop" << endl;

  while(!cin.bad()) {
    cin >> number;
    if (cin.good())
      sum += number;
    else if (cin.eof())
      break;
    else if (cin.fail())
    {
      cin.clear();
      string badToken;
      cin >> badToken;
      cerr << "WARNING: Bad input encountered: " << badToken << endl;
      cout << "Please continue, enter numbers" << endl;
    }
  }

  cout << "The sum is " << sum << endl;


  return 0;
}
