#include <iostream>
#include <initializer_list>
#include <vector>
#include <stdexcept>
#include <sstream>

using std::initializer_list;
using std::invalid_argument;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::exception;
using std::stringstream;

class EvenSequence
{
  public:
    EvenSequence(initializer_list<double> args)
    {
      if (args.size() % 2 != 0)
      {
        stringstream ss;

        ss << "Got this sequence:" << endl;
        for (const auto& v : args)
        {
          ss  << v << ", ";
        }
        ss << endl;

        throw invalid_argument(ss.str());
      }

      mSequence.assign(args);
    }

    void dump()
    {
      for (auto& v : mSequence)
      {
        cout << v << ", ";
      }
      cout << endl;
    }

  private:
    vector<double> mSequence;
};

int main()
{
  EvenSequence es1 = {1.05, 2.04, 3.05, 6.07};
  es1.dump();
  try {
    EvenSequence es2 = {2.05, 3.04, 4.05, 7.07, 8.09};
  }
  catch(const exception& e) {
    cout << e.what() << endl;
  }

  EvenSequence es3 {1.05, 2.04, 3.05, 6.07};
  es3.dump();
  try {
    EvenSequence es4 {2.05, 3.04, 4.05, 7.07, 8.09};
  }
  catch(const exception& e) {
    cout << e.what() << endl;
  }

  return 0;
}
