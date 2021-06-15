#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <functional>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ref;
using std::reference_wrapper;
using std::ostream;


template <class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
  std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, ", "));
  os.flush();
  return os;
}


// create a vector of ints with zero elements
auto fn1 = []()
{
  cout << "**************************************************************" << '\n';
  cout << "creating vector with zero elements using default ctor" << endl;
  cout << "**************************************************************" << '\n';
  vector<int> v1;
  cout << "v1.size() = " << v1.size() << '\n';
  cout << '\n';
};

// create a vector of 10 ints with value 5
auto fn2 = []()
{
  cout << "**************************************************************" << '\n';
  cout << "create a vector of 10 ints with value 5" << endl;
  cout << "**************************************************************" << '\n';

  vector<int> v1(10, 5);
  cout << "v1.size() = " << v1.size() << "\n";
  cout << "v1 elements:" << "\n";
  cout << v1 << '\n';
  cout << '\n';
  cout << '\n';
};

// create a vector with linializer_list
auto fn3 = []()
{
  cout << "**************************************************************" << '\n';
  cout << "create a vector with linializer_list" << '\n';
  cout << "**************************************************************" << '\n';

  vector<int> v1({1,2,3,4,5});
  cout << "vector<int> v1({1,2,3,4,5});" << '\n';
  cout << "v1.size() = " << v1.size() << '\n';
  cout << "v1:" << '\n';
  cout << v1 << '\n';

  cout << '\n';
  cout << '\n';
};

// create a vector with uniform initialisation
auto fn4 = []()
{
  cout << "**************************************************************" << '\n';
  cout << "create a vector with uniform initialisation"                    << '\n';
  cout << "**************************************************************" << '\n';

  vector<int> v1 {1, 2, 3, 4, 5};
  vector<int> v2 = {6, 7, 8, 9, 10};

  cout << v1 << '\n';
  cout << '\n';

  cout << v2 << '\n';
  cout << '\n';

  cout << '\n';
};

// copying vectors
auto fn5 = []()
{

  cout << "v1: " << '\n';
  vector<int> v1 {1, 2, 3, 4, 5};
  cout << "v1:" << '\n';
  cout << v1 << '\n';
  cout << '\n';

  cout << "copy constructor v2 = v1" << '\n';
  vector<int> v2 = v1;

  cout << "v2: " << '\n';
  cout << v2  << '\n';

  cout << "copy constructor v3(v1)" << '\n';
  vector<int> v3(v1);
  cout << "v3:" << '\n';

  cout << "assignment operator v4 = v5" << '\n';
  vector<int> v4 {1, 2, 3, 4, 5};
  vector<int> v5;
  v5 = v4;

  cout << "v5: " << '\n';
  cout << v5 << '\n';
};

// comparing vectors
auto fn6 = []()
{
  vector<int> v1{1,2,3,4,5};
  vector<int> v2(v1);
  vector<int> v3 {1,2,4,5};

  if (v1 == v2)
  {
    cout << "v1 and v2 are equal" << '\n';
  }
  else
  {
    cout << "v1 and v2 are not equal" << '\n';
  }

  cout << '\n';

  if (v1 == v3)
  {
    cout << "v1 and v3 are equal" << '\n';
  }
  else
  {
    cout << "v1 and v3 are not equal" << '\n';
  }

  cout << '\n';

  if (v1 > v3)
  {
    cout << "v1 is greater than v3" << '\n';
  }
  else
  {
    cout << "v1 is less than v3" << '\n';
  }

  cout << '\n';
};

// assign vectors
auto fn7 = []()
{
  // assign == clear + assign
  vector<int> v1 {1,2,3,4,5};
  v1.assign({10,11,12,13});
  // now v1 has 10, 11, 12, 13

  cout << "v1: " << '\n';
  cout << v1 << '\n';
  cout << '\n';
};

// swap two vectors
auto fn8 = []()
{
  vector<int> v1 {1,2,3,4,5};
  vector<int> v2 {6,7,8,9,0};

  cout << "v1 and v2 before swap" << '\n';
  cout << "v1: " << '\n';
  cout << v1 << '\n';

  cout << "v2: " << '\n';
  cout << v2 << '\n';
  cout << '\n';

  v1.swap(v2);

  cout << "v1 and v2 after swap" << '\n';
  cout << "v1: " << '\n';
  cout << v1 << "\n";

  cout << "v2: " << '\n';
  cout << v2 << '\n';
  cout << '\n';
};

// storring reference
auto fn9 = []()
{
  string str1 = "Hello";
  string str2 = "World";

  vector<reference_wrapper<string>> messages{ref(str1)};
  messages.push_back(ref(str2));
  messages[1].get() += "!";

  cout << "str1 = " << str1 << ", " <<  "str2 = " << str2 << endl;
};

// iterator and const_iterator
auto fn10 = []()
{
  vector<int> v1 {1,2,3,4,5,6,7,8,9,0};
  for(vector<int>::iterator iter = begin(v1); iter != end(v1); ++ iter)
  {
    cout << *iter << ", ";
  }
  cout << '\n' << '\n';

  for(auto iter = begin(v1); iter != end(v1); ++ iter)
  {
    cout << *iter << ", ";
  }
  cout << '\n' << '\n';

  for(auto iter = begin(v1); iter != end(v1); ++ iter)
  {
    cout << *iter << ", ";
  }
  cout << '\n' << '\n';

  // reverse iterators
  for (auto riter = std::make_reverse_iterator(v1.end()); riter != std::make_reverse_iterator(v1.begin()); ++riter)
  {
    cout << *riter << ", ";
  }

  cout << '\n' << '\n';

  std::copy(std::make_reverse_iterator(v1.end()),
      std::make_reverse_iterator(v1.begin()),
      std::ostream_iterator<int>(std::cout, ", ")
      );

  cout << '\n' << '\n';

  string message = "You don't know what I'm capable of";
  //std::reverse_iterator<std::string::iterator> riter = message.rbegin();
  for (auto riter = message.rbegin() ; riter != message.rend(); riter++)
  {
    cout << *riter << ", ";
  }

  cout << '\n' << '\n';

  cout << "using stream operator for vector" << '\n';
  cout << v1 << '\n';

  vector<string> books {"one", "two", "three"};
  cout << "books:" << '\n';
  cout << books << '\n';
  cout << '\n';
};

// insert, clear, erase, pop_back no element returned,  back element returned
auto fn11 = []()
{
  vector<int> v1 = {1, 2, 3, 5};
  vector<int> v2;

  cout << "inserting single element 4 at pos 3" << '\n';
  v1.insert(cbegin(v1) + 3, 4);
  cout << "v1:" << '\n';
  cout << v1 << '\n';

  cout << "adding some elements to v2 using push_back 6, 7, 9, 9, 10" << '\n';
  for (auto& n : {6,7,8,9,10})
  {
    v2.push_back(n);
  }
  cout << v2 << '\n';

  cout << "adding all elements of v2 to the end of v1" << '\n';
  v1.insert(v1.end(), cbegin(v2), cend(v2));
  cout << "v1:" << '\n';
  cout << v1 << '\n';

  cout << "now erase element from 4 to 7 from v1" << '\n';
  auto start = v1.begin();
  v1.erase(start + 4, start + 7);
  cout << "v1:" << '\n';
  cout << v1 << '\n';
  cout << '\n';

  cout << "clear v2 completely" << '\n';
  v2.clear();
  cout << "v2.size() = " << v2.size() << '\n';
  cout << '\n';

  cout << "insert 10 copies of the value 100" << '\n';
  v2.insert(cbegin(v2), 10, 100);
  cout << "v2:" << '\n';
  cout << v2 << '\n';
  cout << '\n';

  auto last = v1.back();
  cout << "v1 last element = " << last << '\n';
  cout << "pop_back last element " << last << " from v1" << '\n';
  v1.pop_back();
  cout << "v1:" << '\n';
  cout << v1 << '\n';
  cout << '\n';
};

// move semantics and emplace operations
auto fn12 = []()
{
  cout << "push_back some strings to words vector with move semantics" << '\n';
  vector<string> words;
  cout << "capacity:" << words.capacity() << '\n';
  words.push_back(string("one"));
  words.push_back(string("two"));
  words.push_back(string("three"));
  words.push_back(string("four"));
  cout << "vector words: " << '\n';
  cout << words << '\n';
  cout << "capacity:" << words.capacity() << '\n';
  cout << '\n';

  cout << "emplace_back some strings to words vector" << '\n';
  cout << "emplace_back word: " << words.emplace_back("five") << '\n';
  cout << "emplace_back word: " << words.emplace_back("six") << '\n';
  cout << "emplace_back word: " << words.emplace_back("seven") << '\n';
  cout << "vector words: " << '\n';
  cout << words << '\n';
  cout << '\n';

  cout << "emplace 'three and half' to words vector" << '\n';
  words.emplace(begin(words) + 3, "three and half");
  cout << "vector words: " << '\n';
  cout << words << '\n';
  cout << '\n';
};

auto fn13 = []()
{
  cout <<"creating an empty vector and use reserve to preallocate memory" << '\n';
  vector<int> v1;
  cout << "v1.size = " << v1.size() << '\n';
  cout << "v1.capacity() = " << v1.capacity() << '\n';
  cout << "now call v1.reserve(10)" << '\n';
  v1.reserve(10);
  cout << "v1.size = " << v1.size() << '\n';
  cout << "v1.capacity() = " << v1.capacity() << '\n';

  cout << "push_back {1,2,3}" << '\n';
  for (auto i: {1,2,3})
    v1.push_back(i);
  cout << "v1.size = " << v1.size() << '\n';
  cout << "v1.capacity() = " << v1.capacity() << '\n';

  cout << "push_back another 7 integers" << '\n';
  for (auto i: {4,5,6,7,8,9,0})
    v1.push_back(i);
  cout << "v1.size = " << v1.size() << '\n';
  cout << "v1.capacity() = " << v1.capacity() << '\n';
};



int main(int argc, char** argv)
{
  cout << "argc = " << argc << endl;
  cout << "argv = " << argv << endl;

  // create a vector of ints with zero elements
  fn1();

  // create a vector of 10 ints with value 5
  fn2();

  // create a vector with linializer_list
  fn3();

  // create a vector with uniform initialisation
  fn4();

  // copying vectors
  fn5();

  // comparing vectors
  fn6();

  // assign vectors
  fn7();

  // swap two vectors
  fn8();

  // storring references in vector
  fn9();

  // iterator and const_iterator
  fn10();

  // insert
  // erase
  // clear
  // pop_back no element returned
  // back element returned
  fn11();

  // move semantics and emplace operations
  fn12();

  //creating an empty vector and use reserve to preallocate memory
  fn13();

    return 0;
}
