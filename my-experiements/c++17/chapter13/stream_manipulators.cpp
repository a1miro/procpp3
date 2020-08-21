#include<iostream>
#include<iomanip>

using namespace std;

int main() {
  cout << "Stream maninuplator examples\n";
  
  cout << "===== Boolean values ====" << endl;
  bool myBool = true;
  cout << "This is the default: " << myBool << endl;
  cout << "This should be true: " << boolalpha << myBool << endl;
  cout << "This should be 1: " << noboolalpha << myBool << endl;
  
  cout << "==== Simulate \"%6d\" with streams ====\n";
  int i = 123;
  printf("This should be '123': %6d\n", i);
  cout << "This should be '123': " << setw(6) << i << endl;

  cout << "==== Simulate  \"%06d\" with streams ==== \n"; 
  printf("This should be '000123': %06d\n", i);
  cout << "This should be '000123': " << setfill('0') << setw(6) << i << endl;
  cout << "Fill with *\n";
  cout << "This should be '***123': " << setfill('*') << setw(6) << i << endl;
  
  cout << " ==== Reset fill character ==== \n";
  cout << setfill(' ');
 
  cout << "==== Floating point values ==== \n"; 
  double dbl = 1.452;
  double dbl2 = 5;
  cout << "This should be ' 5': " << setw(2) << noshowpoint << dbl2 << endl;
  cout << "This should be @@1.452: " << setw(7) << setfill('@') << dbl << endl;
  
  cout << "==== Reset fill character ==== \n";
  cout << setfill(' ');

  cout << "==== Set precision ====\n";
  cout << "This should be '1.2346':" << setprecision(5) << 1.23456789 << endl;
  auto prev_precision = cout.precision(4);
  cout << "This should be '1.235, the last for rounded by 1'" << 1.23456789 << endl;
  cout << "reset to prvious precision 5 \n";
  cout << "This should be '1.2346':" << setprecision(prev_precision) << 1.23456789 << endl;



  cout << "Instructs cout to start formatting numbers according to your location.\n";
  cout << "Chapter 19 explains the details of the imbue call and the locale object.\n";
  cout.imbue(locale(""));
  
  cout << "==== Format numbers according to your location ==== \n";
  cout << "This is 1234567 formatted according to your location: " << 1234567 << endl;
  cout << "Monetary value. What exactly a monetary value means depends on your \n";
  cout << "location. For example, in the USA, a monetary value of 120000 means 120000 \n";
  cout << "dollar cents, which is 1200.00 dollars.\n"; 
  cout << "This should be a monetary value of 120000, "
    << "formatted according to your location: "
    << put_money("120000") << endl;
  
  cout << "==== Date and time ==== \n";
  time_t t_t = time(nullptr); // Get current system time
  tm* t = localtime(&t_t);
  
  cout << "==== Convert to local time ==== \n";
  cout << "This should be the current date and time "
    << "formatted according to your location: "
    << put_time(t, "%c") << endl;

  cout << "==== Quoted string ==== \n";
  cout << "This should be: \"Quoted string with \\\"embedded quotes\\\".\": "
    << quoted("Quoted string with \"embedded quotes\".") << endl;

  return 0;
}
