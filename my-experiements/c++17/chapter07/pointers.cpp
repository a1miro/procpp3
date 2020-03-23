#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <memory>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::string_view;

#define TP()    cout << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << endl
//#define WONT_COMPILE
//
class Base {
  public:
    virtual string_view name() = 0;
    virtual void set_name(string_view name) = 0; 
};

class Simple : public Base{
  public:
    Simple(string_view name) : name_(name){} 
    string_view name() override {return name_;} 
    void set_name(string_view name) override {name_ = name;}

  private:
    string name_;
};

int main() {
    TP();

#if defined(WONT_COMPILE)
    int* a = static_cast<int*>(new char("Hello world"));
    long int* b = static_cast<long int*>(new long int(3));
#else
    auto carray = new char[12];
    std::vector<int> cvector = {1, 2, 3, 4, 5};
    Simple s("test1");
    
    for(auto& c : cvector)
    {
      cout << c << ", ";
    }
    cout << endl;
    delete[] carray;

#endif // WONT_COMPILE

    /**
     * Narrowing C++
     */
    int x = 3.14;   //Okay

#if defined(WONT_COMPILE)
    int y = {3.14}; // error
#endif

    // Copy list initialisation
    auto a22 = {11};      // initializer_list<int>
    auto b22 = {11, 22};  // initializer_list<int>

    // Direct list initialisation
    auto c22 {11}; //int 
#if defined(WONT_COMPILE)
    auto d22 {11, 22}; 
#endif


  std::unique_ptr<Simple> simple01{nullptr};
  simple01.reset(new Simple("Test1"));
  cout << "simple01->name() = " << simple01->name() << endl;

  std::unique_ptr<Simple> simple02{new Simple("Test2")};
  cout << "simple02->name() = " << simple02->name() << endl;

  auto simple03 = std::make_unique<Simple>("Test3");
  cout << "simple03->name() = " << simple03->name() << endl;

 
  // reset with no parameter - frees resource and set to nullptr
  simple02.reset();
  if(!simple02)
  {
    cout << "simple02 is a null pointer" << endl;
  }
  else
  {
    cout << "simple02 is not a null pointer" << endl;
  }

  // reset - frees resource and set to a new instance
  simple03.reset(new Simple("Test4"));
  cout << "simple03->name() = " << simple03->name() << endl;

  // C-style array
  auto carray2 = std::make_unique<int[]>(10);
 //cout << std::size(carray2.get()) << endl;

  std::unique_ptr<int, decltype(free)*> simple05(new int(25), free);
  cout << "simple05 = " << *simple05 << endl;

  /* shared_ptr examples ... */
  auto simple_shared33 = std::make_shared<Simple>("Test33");
  std::shared_ptr<int[]> carray77(new int[77]);
  for(int i = 0; i < 77; i++)
  {
    carray77[i] = i;
  }

  std::shared_ptr<Base> base = std::dynamic_pointer_cast<Base>(std::make_shared<Simple>("Test88"));
  auto base_elements = std::make_shared<Base[]>(new Base[]{"None"});



 
  
 
  return 0;
}
