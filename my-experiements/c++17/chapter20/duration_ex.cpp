#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
using namespace chrono;

int main() 
{
  duration<long, ratio<60>> d1(123);
  cout << d1.count() << endl;

  duration<double> d2;
  d2 = d2.max();
  cout << d2.count() << endl;

  // Define 2 durations:
  // For the first duration, each tick is 1 minute
  // For the second duration, each tick is 1 second
  duration<long, ratio<60>> d3(10); // = 10 minutes
  duration<long, ratio<1>> d4(14);  //= 14 seconds
  
  cout << "d3 = " << d3.count() << " minutes" << endl;
  cout << "d4 = " << d4.count() << " secounds" << endl;

  if (d3 > d4)
    cout << "d3 > d4 " << endl;
  else
    cout << "d3 <= d4" << endl;


  cout << "prefix increment" << endl;
  ++ d4;
  cout << "d4 = " << d4.count() << " secounds" << endl;

  cout << "Multiplication d4 *= 2 : ";
  d4 *= 2;
  cout << "d4 = " << d4.count() << " secounds" << endl;

  cout << "Add both durations and store as minutes" << endl;
  duration<double, ratio<60>> d5 = d3 + d4;
  cout << "duration<double, ratio<60>>> d5 = d3 + d4; // d5 = " << d5.count() << " minutes";

  cout << "Add both durations and store as seconds" << endl;
  duration<long, ratio<1>> d6 = d3 + d4;
  cout << "duration<long, ratio<1>> d6 = d3 + d4; // d6 = " << d6.count() << " seconds" << endl;


  


  return 0;
}
