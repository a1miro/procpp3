#include<iostream>
#include<string>
#include<memory>

using std::cout;
using std::endl;

void f(int a) {
    cout << "f(int)" << endl;
}

void f(bool a) {
    cout << "f(bool)" << endl;
}

void f(void* p) {
    cout << "f(void*)" << endl;
};

class Widget {
    public:
        Widget(const char* name): _name(name) {
            cout << "Widget ctor" << endl;
        }
        virtual ~Widget() {
            cout << "Widget dtor" << endl;
        }

        std::string& name() { return _name;}

    private:
        std::string _name;
};


int f1(std::shared_ptr<Widget> spw) {
    cout << "f1 call" << endl;
    cout << "widget name: " << spw->name() << endl;
    return 1;
};

double f2(std::unique_ptr<Widget> upw) {
    cout << "f2 call" << endl;
    cout << "widget name: " << upw->name() << endl;
};

bool f3(Widget* pw) {
    cout << "f3 call" << endl;
    if (pw == nullptr) {
        cout << "pw is nullptr" << endl;
        return false;
    }

    cout << "widget name: " << pw->name() << endl;
    return true; 
};

template <typename FuncType, typename PtrType>
decltype(auto) fcall(FuncType func, PtrType ptr) {
    return func(ptr);
}



int main(int argc, char** argv) {
    
    //f(NULL);    // error - ambigues call
    f(nullptr); // fine

    auto sp = std::make_shared<Widget>("Shared Pointer");
    //auto up = std::make_unique<Widget>("Unique Pointer");
    std::unique_ptr<Widget> up = std::make_unique<Widget>("Unique Pointer");
    auto p = new Widget("Plain Pointer");

    cout << "returned value: " << fcall(f1, sp) << endl;
    //cout << "returned value: " << fcall(f2, up) << endl;
    cout << "returned value: " << fcall(f3, p) << endl;
    cout << "returned value: " << fcall(f3, nullptr) << endl;
   

    return 0;
}
