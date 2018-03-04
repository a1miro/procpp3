#include <iostream>
#include <typeinfo>

# if 0
template <typename T>
void f(T param) {
    using namespace std;

    cout << "type: " << typeid(param).name() << endl;
    param();
}
#endif

template <typename T>
void f(T& param) {
    using namespace std;

    cout << "type: " << typeid(param).name() << endl;
    param();
}

void somefunc() {
    using namespace std;

    cout << "somefunc call" << endl;
}

int main(int argc, char **argv) {

    f(somefunc);

    return 0;
}
