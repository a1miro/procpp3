#include<iostream>
#include<string>

class SpreadsheetCell
{
    public:
        SpreadsheetCell()=delete;
        SpreadsheetCell(const SpreadsheetCell&) = delete;
        SpreadsheetCell(const std::string& initValue);
        void print();
    private:
        double mValue;
        std::string mString;
};

SpreadsheetCell::SpreadsheetCell(const std::string& initValue):
    mValue(stod(initValue)), mString(initValue) {
            }

void SpreadsheetCell::print()
{
    using namespace std;
    cout << "mValue = " << mValue << endl;
    cout << "mString = " << mString << endl;
}



int main()
{
    using namespace std;

    cout << "++" << __FUNCTION__ << endl;

    try {
    std::string value_str("1.25");
    SpreadsheetCell cell(value_str);
    cell.print();
    //SpreadsheetCell cell2(cell); //Compiler error, copy-ctor deleted!
    }
    catch ( ...)
    {
        cout << "exception is caught!" << endl;
    }

    cout << "--" << __FUNCTION__ << endl;
    return 0;
}
