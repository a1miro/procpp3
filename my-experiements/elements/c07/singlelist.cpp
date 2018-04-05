#include<iostream>
#include<initializer_list>
#include<memory>

using namespace std;

template <typename T> 
struct ListNode {

    ListNode<T>() : 
        data(0), 
        next(nullptr) 
    {}

    ListNode<T>(T value) : 
        data(value), 
        next(nullptr) 
    {} 

    void insert_after(shared_ptr<ListNode<T>>& node, 
            shared_ptr<ListNode<T>>& newnode) {
        newnode->next = node->next;
        node->next = newnode;
    }

    shared_ptr<ListNode<T>> search(shared_ptr<ListNode<T>> list, 
            T&& value) {
        shared_ptr<ListNode<T>> cursor(list);
        while(cursor && cursor->data != value) {
           cursor = cursor->next; 
        }

        return cursor;
    }


    void delete_after(shared_ptr<ListNode<T>> node) {
       node->next = node->next->next; 
    }


        T data;
        shared_ptr<ListNode<T>> next;
};

template <typename T> 
void print(const shared_ptr<ListNode<T>>& list) {
    shared_ptr<ListNode<T>> cursor(list);
    while(cursor) {
        cout << cursor->data << ", " << endl;
        cursor = cursor->next;
    }
}


int main() {

    using IntList = ListNode<int>;
    //IntList list;
    shared_ptr<IntList> list = make_shared<IntList>(IntList(0));
    shared_ptr<IntList> node1 = make_shared<IntList>(IntList(1));
    shared_ptr<IntList> node2 = make_shared<IntList>(IntList(2));
    shared_ptr<IntList> node3 = make_shared<IntList>(IntList(3));

    list->insert_after(list, node1);
    list->insert_after(node1, node2);
    list->insert_after(node2, node3);

    print(list);



    


    return 0;
}
