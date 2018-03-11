#include <iostream>
#include <vector>
#include <unordered_map>


int main(int argc, char** argv) {
    using std::unordered_map;
    using std::cout;
    using std::endl;

    int x1;  // potentially uninitialized
    //auto x2; // error! initializer required
    auto x3 = 0; // just fine

    std::vector<int> v{1,2,3,4,5};
    auto sz = v.size();

    unordered_map<std::string, int> m = {
        {"RED",     0},
        {"GREEN",   1},
        {"BLUE",    2}
    };

    for (auto& p : m) {
        cout << p.first << "=" << p.second << endl;
    }

    return 0;
}
