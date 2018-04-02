#include<iostream>
#include<vector>
#include<stdexcept>



int main() {
    using namespace std;
    vector<string> weekdays{"Mon", "Tue", "Thu", "Fri"};

    for(auto iter = cbegin(weekdays); iter != cend(weekdays); ++iter) {
        cout << *iter << endl;
    }

    cout << "strvector[3]=" << weekdays.at(3) << endl;

#if 0
    try {
        cout << weekdays.at(15) << endl;
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }
#endif

    // Example of emplace
    weekdays.emplace(weekdays.begin()+2, "Wed");
    cout << "vector after emplace:"<< endl;
    for (auto& d: weekdays) {
        cout << d << ", ";
    }
    cout << endl;
    
    

    return 0;
}
