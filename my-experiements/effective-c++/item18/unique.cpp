#include<iostream>
#include<memory>


int main() {

    using std::cout;
    using std::endl;
    using std::unique_ptr;

    // Creating std::unique_ptr<T[]>
    unique_ptr<int[]> array(new int[10]);
    auto array1 = std::make_unique<int[]>(10);

    auto pa = new int[4]{1, 2, 3, 4};
    unique_ptr<int[]>a(pa);

    // Not compiled: auto array2 = std::make_unique<int[3]>(new int[3]{0,1,2});
    unique_ptr<int[]>a1(new int[3]{1,2,3});

    int x[] = {3,8,7};
    int x1[]{3,8,7};

    for (const auto item :x) {
        cout << item << ", ";
    }
    cout << endl;

    return 0;
}
