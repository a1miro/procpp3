#include <memory>
#include "Grid.h"
using namespace std;

int main() {
  Grid<int> myIntGrid;

  Grid<double> myDoubleGrid(11, 11);
  
  myIntGrid.at(0,0) = 10;
  [[maybe_unused]] int x = myIntGrid.at(0, 0).value_or(0);

  Grid<int> grid2(myIntGrid); // Copy constructor
  Grid<int> anotherIntGrid;   
  anotherIntGrid = grid2;     // Assignment operator

  return 0;
}
