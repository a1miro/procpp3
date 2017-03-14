#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

class EvenSequence
{
    public:
        EvenSequence(std::initializer_list<double> args)
        {
            if (args.size() % 2 != 0) {
                throw std::invalid_argument("initializer_list should "
                        "contain even number of elements.");
            }
            mSequence.reserve(args.size());

            for (auto value : args) {
                mSequence.push_back(value);
            }
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

        static const int kInt1 = 1; //Ok
        //static const std::string kStr = "test"; //Error
        //static int sInt2 = 2;                   //Error
        const int kInt3 = 3;
};




int main()
{
    std::vector<std::string> myvec={"String1", "String2", "String3"};
    return 0;
}

