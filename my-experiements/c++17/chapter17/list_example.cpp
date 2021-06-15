#include <iostream>
#include <list>
#include <string>
#include <ostream>
#include <iterator>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::ostream;

template <class T>
ostream& operator<<(ostream& os, const list<T>& v)
{
  std::copy(v.cbegin(), v.cend(), std::ostream_iterator<T>(os, ", "));
  os.flush();
  return os;
}

auto fn01 = [] ()
{
  cout << "=============Splicing example======================== \n\n";
  list<string> dictionary{"aardavark", "ambulance"};
  list<string> b_words{"bathos", "balderdash"};

  dictionary.push_back("canticle");
  dictionary.push_back("consumerism");

  cout << "original dictionary:" << "\n";
  cout << dictionary << '\n';
  cout << '\n';

  if (!b_words.empty())
  {
    auto b_words_last = --(cend(b_words));
    auto it = cbegin(dictionary);
    for (; it != cend(dictionary); ++it)
    {
      if (*it > *b_words_last)
      {
        break;
      }
    }
    dictionary.splice(it, b_words);

    cout << "dictionary after splice: " << "\n";
    cout << dictionary << endl;
    cout << '\n';
    cout << "b_words.size() = " << std::size(b_words) << "\n";
  }
};

int main()
{
  cout << "Code examples fro std::list class" << "\n\n";
  fn01();
}
