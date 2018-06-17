#include<iostream>
#include<memory>



int main() {
    using namespace std;

    const size_t ints_num = 10, floats_num = ints_num;

    auto ints = make_unique<int[]>(ints_num);
    auto floats = make_unique<float[]>(floats_num);

    for (int i = 0; i < ints_num; i++) 
    {
        ints[i] = i;
        floats[i] = ints[i] * 0.1;
    }

    cout << "ints:" << endl;
    for (int i = 0; i < ints_num; i++) 
    {
        cout << ints[i] << ", ";
    }
    cout << endl;

    cout << "floats:" << endl;
    for (int i = 0; i < ints_num; i++) 
    {
        cout << floats[i] << ", ";
    }
    cout << endl;






    

    return 0;
}
