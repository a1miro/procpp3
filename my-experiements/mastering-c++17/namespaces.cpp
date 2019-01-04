#include <iostream>
#include <cstdint>
using std::cout;
using std::endl;

namespace one::object {
    uint64_t id;

} //one::object

int main(int argc, char** argv) {

    cout << "Using C++17 namespaces" << endl;

    one::object::id = 3;

    using one::object::id;

    cout << "one::object::id = " <<  id << endl;

    return 0;
}
