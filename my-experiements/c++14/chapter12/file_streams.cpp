#include<iostream>
#include<fstream>
#include<ios>




int main() {
    using namespace std;

    string filename;

    cout << "Enter filename:";
    cin >> filename;

    ofstream output(filename, ios_base::trunc);
    if(!output) {
        cout << "Error! I could not open file " << filename << endl;
        return -1;
    }

    // 1. Output the string "12345"
    output << "12345";

    // 2. Verify that the marker is at position 5
    ios_base::streampos cursor = output.tellp();
    if (cursor != 5) {
        cout << "Error! Not at position 5!" << endl;
    }

    // 3. Move to position 2 in the stream
    output.seekp(2, ios_base::beg);

    //4. Output  0 in a position 2 and close the stream
    output << "0";
    output.close();

    //5. Open an input stream on filename
    ifstream input(filename);
    if (!input) {
        cout << "Error! Could not open " << filename << endl;
    }
    //6. Read written value back 
    int val;
    input >> val;

    //7. Check the value
    if (val != 12045) {
        cout << "Error! Value is wrong." << endl;
        cout << "Expected " << 12045 << " got " << val << endl;
        return -1;
    }

    cout << "Successfully read out value " << val << endl;

    return 0;
}
