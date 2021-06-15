#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;
using namespace chrono;

int main() {
  cout << "clocks eaxamples" << endl;

  auto current_time = system_clock::now();
  auto tt = system_clock::to_time_t(current_time);
  auto local_time = localtime(&tt);

  cout << put_time(local_time, "%H:%M:%S") << endl;

  stringstream ss;
  ss << put_time(local_time, "%H:%M:%S");
  auto time_str = ss.str();

  cout << "time_str = " << time_str << endl;

  time_point<steady_clock, milliseconds> tp_ms(42'424ms);
  time_point<steady_clock, seconds> tp_s(time_point_cast<seconds>(tp_ms));

  milliseconds ms(tp_ms.time_since_epoch());
  cout << "ms = " << ms.count() << endl;


  return 0;
}

