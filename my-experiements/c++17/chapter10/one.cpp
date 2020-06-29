#include "one.h"

struct one::data
{
  int64_t id = 0x0;

};

uint64_t one::id() const 
{
  return data_->id; 
}

int main()
{
  return 0;
}
