#include<iostream>
#include<sstream>



int main() {
    using namespace std;
    ostringstream oss;
    istringstream iss;
    string token;
    char buff [255];
#if 0
    while(cin) {
        cin >> token;
        if (token == "done") {
            break;
        }
        oss << token << "\t";
    }

    streambuf* buf_cout = cout.rdbuf();
    streambuf* buf_oss = oss.rdbuf();

    // Redirect cout to oss 
    cout.rdbuf(buf_oss);

    cout << "This line written to oss" << endl;

    // Redirect cout back to screen
    cout.rdbuf(buf_cout);

    cout << "This line written to screen" << endl;

    cout << "oss: " << oss.str(); 
#endif

    while(cin && !cin.fail()){
       oss << cin.get();
    }

    cout << oss.str();

        return 0;
}
