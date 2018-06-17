#include<iostream>
#include<vector>
#include<iterator>
#include<numeric>

int main() {
    using namespace std;

    vector<int> vc(10);

    // fill vc with 1,2,3,...10
    iota(begin(vc), end(vc), 1); 

    // print vc elements
    copy(cbegin(vc), cend(vc), ostream_iterator<int>(cout, ", "));

    vector<int> numbers(10,0);
    cout << "Ener numbers (Ctrl+D to terminate):" << endl;
    istream_iterator<int> numbersIter(cin);
    istream_iterator<int> numbersEnd;
    //copy(numbersIter,  numbersEnd, begin(numbers));
    copy(numbersIter, numbersEnd, begin(numbers));

    //print out numbers
    copy(cbegin(numbers), cend(numbers), ostream_iterator<int>(cout, ", "));

    // print numbers
    //copy(cbegin(numbers), cend(numbers), ostream_iterator<int>(cout, ", "));
    

    return 0;
}
