#include <iostream>
#include <cstddef>

using namespace std;

constexpr int getSize() {return 32;}

class Rect
{
  public:
    constexpr Rect(size_t width, size_t height):
      width_(width), 
      height_(height) {}

    constexpr size_t getArea() const { return width_ * height_;}
    void setArea(size_t width, size_t height) {width_=width; height_=height;}

  private:
    size_t width_, height_;
};


int main() {

  int a[getSize() + 1] = {};
  cout << "a[1] = " << a[1] << endl;

  constexpr Rect r(8,2);
  int mArray[r.getArea()] = {};
  cout << "mArray[1] = " << mArray[1] << endl;

  //r.setArea(5,5); //won't compile
  return 0;
}
