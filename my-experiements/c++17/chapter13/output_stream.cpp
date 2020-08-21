#include<iostream>
#include<cstring>

using namespace std;

int main() 
{
  // Use  '\n' instead endl for a new line, to reduce the number of flushes 
  cout << "Line1\n";
  cout << "Line2\n";
  cout << "Line3\n";
  cout << endl; // flush now

  // Use put for single character
  cout.put('a');
  // and write for c-style array
  const char* hello = "\nhello\n";
  cout.write(hello, strlen(hello));
  cout.flush();

  // Steams error handling
  if (cout.good()) {
    cout << "All good" << endl;
  }

  if (cout.fail()) {
    cerr << "Unable to flush to standard output" << endl;
  }

  // the above example is equal to below one
  if (!cout) {
    cerr << "Unable to flush to standard output" << endl;
  }

  cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
  try {
    cout << "Hello World." << endl;
  } catch (const ios_base::failure& ex) {
    cerr << "Caught exception: " << ex.what()
      << ", error code = " << ex.code() << endl;
    // clear stream the error state
    cout.clear();
  }

return 0;
}
