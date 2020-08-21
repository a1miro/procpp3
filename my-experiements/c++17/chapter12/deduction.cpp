#include <iostream>
#include <utility>

using namespace std;

template <typename T>
class Content
{
  public:
    Content(const T& t): _content(t) {}
    const T& getContent() const {return _content;}
  private:
    T _content;
};

// C++17 feature, user define deduction guides
Content(const char*) -> Content<string>; 

int main()
{
  // template parameter type is not deduced
  pair<int, double> pair1(1, 2.3);
  cout << "pair1: ( " << pair1.first << ", " << pair1.second << ")" <<  endl;

  // using make_pair to deduce parameters type
  auto pair2 = make_pair(1, 2.3);
  cout << "pair1: ( " << pair2.first << ", " << pair2.second << ")" <<  endl;

  // C++17, fully auto deducing
  pair pair3(1, 2.3);
  cout << "pair1: ( " << pair3.first << ", " << pair3.second << ")" <<  endl;

  Content ct("Hello world");
  cout << "ct.getContent: " << ct.getContent() << endl;

  return 0;
}
