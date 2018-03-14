#include<iostream>

template<typename C, typename V>
void findAndInsert(C& container,
        const V& targetVal,
        const V& insertVal)
{
    using std::cbegin;
    using std::cend;

    //in container, find first occurrence
    //of targetVal, 
    auto it = std::find(cbegin(container),
            cend(container),
            targetVal);

    //insert insertValthere
    container.insert(it, insertVal);
}

int main() {

    return 0;
}
