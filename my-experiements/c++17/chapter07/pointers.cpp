#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <memory>
#include <iterator>
#include <set>

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

class Simple : public Base, public std::enable_shared_from_this<Simple> {
  public:
    Simple(string_view name) : name_(name){}
    string_view name() override {return name_;}
    void set_name(string_view name) override {name_ = name;}

    std::shared_ptr<Simple> shared() {
      return shared_from_this();
    }



  private:
    string name_;
};

class Foo {
  public:
    Foo(int value): value_(value) {}
    int value_;
};

std::unique_ptr<Simple> create_simple(string_view name)
{
  return std::make_unique<Simple>(name);
}

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
  cout << "carray2: ";
  for (int i=0; i < 10; ++i)
  {
    cout << carray2[i]  << ", ";
  }
  cout << endl;


  std::unique_ptr<int[]> carray3(new int[10]);
  cout << "carray3: ";
  for (int i=0; i < 10; ++i)
  {
    cout << carray3[i]  << ", ";
  }
  cout << endl;

  std::unique_ptr<int, decltype(free)*> simple05((int*)malloc(sizeof(int)), free);
  cout << "simple05 = " << *simple05 << endl;

  /* shared_ptr examples ... */
  auto simple_shared33 = std::make_shared<Simple>("Test33");
  std::shared_ptr<int[]> carray77(new int[77]);
  for(int i = 0; i < 77; i++)
  {
    carray77[i] = i;
  }

  std::shared_ptr<Base> base = std::dynamic_pointer_cast<Base>(std::make_shared<Simple>("Test88"));
  //auto base_elements = std::make_shared<Base[]>(new Base[]{"None"});

  // Aliasing shared pointer
  auto foo = std::make_shared<Foo>(45);
  auto aliasing = std::shared_ptr<int>(foo, &foo->value_);
  std::cout << std::boolalpha << "foo.owner_before(aliasing): " << foo.owner_before(aliasing) << std::endl;
  std::cout << std::boolalpha << "aliasing.foo.owner_before(foo): " << aliasing.owner_before(foo) << std::endl;

  int * p = new int (10);

  std::shared_ptr<int> a (new int (20));
  std::shared_ptr<int> b (a, p);  // alias constructor

  std::cout << "comparing a and b...\n" << std::boolalpha;
  std::cout << "value-based: " << ( !(a<b) && !(b<a) ) << '\n';
  std::cout << "owner-based: " << ( !a.owner_before(b) && !b.owner_before(a) ) << '\n';

  int * q = new int (10);

  std::shared_ptr<int> g (new int (20));
  std::shared_ptr<int> h (g, q);  // alias constructor: co-owns a, points to p

  // standard set container: cannot contain duplicates.
  std::set < std::shared_ptr<int> > value_based;  // uses std::less
  std::set < std::shared_ptr<int>, std::owner_less<std::shared_ptr<int>> > owner_based;

  value_based.insert (g);
  value_based.insert (h);  // ok, different value

  owner_based.insert (g);
  owner_based.insert (h);  // overwrites (same owned pointer)

  std::cout << "value_based.size() is " << value_based.size() << '\n';
  std::cout << "owner_based.size() is " << owner_based.size() << '\n';


  // weak_ptr examples
  auto simple21 = std::shared_ptr<Simple>(new Simple("Simple21"));
  std::weak_ptr<Simple> weak_simple21(simple21);

  if (weak_simple21.lock())
  {
    std::cout << "simple21 is still alive" << std::endl;
  }

  // Now let's reset simple21
  simple21.reset();

  // Check that the lock method returnsl nullptr
  if (!weak_simple21.lock())
  {
    std::cout << "simaple21 has been freed!" << std::endl;
  }

 // Move semantics for unique_ptr, shared_ptr and weak_ptr
  std::unique_ptr<Simple> simple22 = create_simple("Simple22");
  auto simple23 = create_simple("Simple23");

  //// enable_shared_from_this example
  auto simple24 = std::make_shared<Simple>("Simple24");
  auto simple24_1 = simple24->shared();

  if (simple24.get() == simple24_1.get())
  {
    cout << "simple24_1 points to the same address as simple24" << endl;
  }

  return 0;
}
