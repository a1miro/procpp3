#include<iostream>

using namespace std;

[[noreturn]] void forceProgramTermination() 
{
  std::exit(1);
}

bool isDongleAvailable()
{
  bool isAvailable = false;
  return isAvailable;
}

bool isFeatureLicensed(int featureId) 
{
  if (!isDongleAvailable()) {
    forceProgramTermination();
  } else {
    bool isLicensed = false;
    return isLicensed;
  }
}

[[deprecated("Unsafe method. Don't use it")]] void unsafe(){cout << "unsafe call" << endl;}

[[nodiscard]] bool something_in_return() { return true;}

int main() {
  cout << "C++ attributest examples" << endl;
  unsafe();

  something_in_return();
  
  
  
  bool isLicensed = isFeatureLicensed(42);

  return 0;
}
