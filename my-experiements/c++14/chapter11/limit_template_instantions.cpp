#include<string>
#include"Array.h"

using std::string;

using IntArray =  Array<int>;

// Array class specialisation for strings
template <>
class Array<string> {

    public:
        Array(std::initializer_list<string> l) {
            array_.insert(array_.end(), l.begin(), l.end());
        }

        virtual void print()  {
            for (auto v: array_) {
                cout << v << ", "; 
            }
            cout << endl;
        }

    private:
        vector<string> array_;
};


using StringArray = Array<string>;

int main() {

    IntArray iarray{1,2,3,4,5};
    StringArray weekend_days{"Mon", "Tue", "Wed", "Thu", "Fri"};

    iarray.print();
    weekend_days.print();

    SafeArray<double> darray{0.1,0.2,0.3,0.4,0.5};
    darray.print();
    cout << "darray[3]=" << darray[3] << endl;
    try
    {
        cout << "darray[10" << darray[10] << endl;
    }
    catch(...) {
        cout << "Exception!!!!, index is out range" << endl;
    }

    string message("Hello world");
    cout << echo(message) << endl;
    cout << echo("What's surprise!") << endl;
    cout << echo(std::string("It should be rvalue")) << endl;

    return 0;
}
