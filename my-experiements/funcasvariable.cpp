#include <iostream>
#include <cstddef>

using namespace std;

inline void print(size_t c) {cout << "count = " << c << endl;}
class Count {

    public:
        explicit Count(size_t c): count_(c) {}

        size_t count() const { return count_;}

        void set_count(size_t c) { count_ = c; print(count);}

    private:
        size_t count_;
};


int main() {

    Count c(3);

    return 0;
}
