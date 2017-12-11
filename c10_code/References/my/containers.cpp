#include<iostream>

#include<array>
#include<vector>
#include<map>

#include <cstdlib>
#include <time.h>

#include <sys/timeb.h>

static int const NUMBER_ITERATIONS = 10000; 

enum class Index {

    Ind0 = 0,
    Ind1, 
    Ind2, 
    Ind3, 
    Ind4, 
    Ind5, 
    Ind6, 
    Ind7, 
    Ind8, 
    Ind9,
    IndLast
};

int getMilliCount(){
    timeb tb;
    ftime(&tb);
    int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
    return nCount;
}

int getMilliSpan(int nTimeStart){
    int nSpan = getMilliCount() - nTimeStart;
    if(nSpan < 0)
        nSpan += 0x100000 * 1000;
    return nSpan;
}

long int test_carray(int* const a) {
    int index;
    int res;


    // Initialise random seed
    srand(time(NULL));

    // start timer
    int start = getMilliCount();

    for (int iter = 0; iter < NUMBER_ITERATIONS; ++iter)
    {
        index = rand() % 10;
        res = a[index];
    }

    // stop  timer

    return getMilliSpan(start);
}


long int test_array(std::array<int,10>& a) {
    int index;
    int res;


    // Initialise random seed
    srand(time(NULL));

    // start timer
    int start = getMilliCount();

    for (int iter = 0; iter < NUMBER_ITERATIONS; ++iter)
    {
        index = rand() % 10;
        res = a[index];
    }


    return getMilliSpan(start);
}


long int test_vector(std::vector<int>& a) {
    int index;
    int res;


    // Initialise random seed
    srand(time(NULL));

    // start timer
    int start = getMilliCount();

    for (int iter = 0; iter < NUMBER_ITERATIONS; ++iter)
    {
        index = rand() % 10;
        res = a[index];
    }

    return getMilliSpan(start);
}

long int test_map(std::map<int, int>& a) {
    int index;
    int res;


    // Initialise random seed
    srand(time(NULL));

    // start timer
    int start = getMilliCount();

    for (int iter = 0; iter < NUMBER_ITERATIONS; ++iter)
    {
        index = rand() % 10;
        res = a[index];
    }

    return getMilliSpan(start);
}


int main() {
    using namespace std;

    int a0[10] = {0,1,2,3,4,5,6,7,8,9};
    array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9}; 
    vector<int> a2({0,1,2,3,4,5,6,7,8,9}); 
    map<int, int> a3 = { 
        {0, 0},
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5},
        {6, 6},
        {7, 7},
        {8, 8},
        {9, 9},
    };

    cout << "Test carray took: " << test_carray(a0) << endl;
    cout << "Test array  took: " << test_array(a1) << endl;
    cout << "Test vector took: " << test_vector(a2) << endl;
    cout << "Test map    took: " << test_map(a3) << endl;

    return 0;

}
