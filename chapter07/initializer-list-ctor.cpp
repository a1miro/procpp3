#include<iostream>
#include<initializer_list>
#include<vector>

using namespace std;
#if 0
class EvenSequence
{
    public:
        EvenSequence(initializer_list <double> args)
        {
            if (args.size() % 2 != 0) {
                throw invalid_argument("initializer_list should "
                        "contain even number of elements.");
            }
            mSequence.reserve(args.size());
#if 0

            for (auto value : args) {
                mSequence.push_back(value);
            }
#endif
            mSequence.insert(cend(mSequence), cbegin(args), cend(args));
        }
        void dump() const
        {
            for (auto value : mSequence) {
                cout << value << ", ";
            }
            cout << endl;
        }

    private:
        std::vector<double> mSequence;
};




int main()
{
    EvenSequence p1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    p1.dump();

    try {
        EvenSequence p2 = {1.0, 2.0, 3.0};

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}
#endif

class System
{
    public:
        System()=delete;
        System(const System&) = delete;
        System operator=(const System&) = delete;

        System(initializer_list <string> args)
        {
            args_.reserve(args.size());
            args_.insert(cend(args_), cbegin(args), cend(args));
        }

        void dump() const
        {
            cout << "args:" ;
            for (auto arg : args_)
            {
                cout << arg << " ";

            }
            cout << endl;

        }

    private:
        static const int SYSTEM_INIT_VALUE=0; 
        static const std::string SYSTEM_DEFAULT_NAME;
        static int svariable;

        int count_      = SYSTEM_INIT_VALUE;
        std::string name_ = SYSTEM_DEFAULT_NAME; 
        std::vector<string> args_;
};

const std::string System::SYSTEM_DEFAULT_NAME = "zero"; 
int System::svariable = 0; 


int main()
{
    System s = {"bla1", "bla2", "bla3"};
    s.dump();
    return 0;
}
