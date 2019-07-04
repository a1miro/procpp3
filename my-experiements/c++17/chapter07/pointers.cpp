#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

#define TP()    cout << __FILE__ << " : " << __FUNCTION__ << " : " << __LINE__ << endl
//#define WONT_COMPILE

int main() {
    TP();
#if defined(WONT_COMPILE)
    int* a = static_cast<int*>(new char("Hello world"));
    long int* b = static_cast<long int*>(new int(3));
#endif // WONT_COMPILE

    return 0;
}
