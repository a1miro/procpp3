#include<iostream>
#include<vector>

using std::cout;
using std::endl;

class Widget {
    public:
        using DataType = std::vector<double>;

         DataType& data() & { 
            cout << "data() &" << endl;
            return values_; 
        }

        DataType data() && {
            cout << "data() &&" << endl;
            return std::move(values_);
        }

    private:
        DataType values_={0};

};

Widget makeWidget() {
    return Widget();
}


int main(int argc, char** argv) {

    Widget w;
    auto val1 = w.data();
    auto val2 = makeWidget().data();
    

    return 0;
}
