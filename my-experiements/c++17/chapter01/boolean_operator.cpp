#include<iostream>

using namespace std;

template <typename T> 
class Pointer {
    public:
        explicit Pointer(T* ptr) : ptr_(ptr) {}
        virtual ~Pointer() { delete ptr_; ptr_ = nullptr;}

        Pointer(const Pointer& ) = delete;
        Pointer& operator=(const Pointer&) = delete;

        // Dereference operators implementation
        T& operator*() { return *ptr_;}
        const T& operator*() const { return *ptr_;}

        T* operator->() { return ptr_;}
        const T* operator->() const { return ptr_;}

        // Used in boolean expressions as well as pointer checks
        operator void* () const { return ptr_; }


    private:
        T* ptr_;
};

class Book {
    public:

        explicit Book(const char* title, const char* author)
            : 
                title_(title),
                author_(author)
            {}

        virtual ~Book() {}

        void print() {
            cout << "title: " << title_ << endl;
            cout << "author: " << author_ << endl;
        }


    private:
        const char* title_;
        const char* author_;
};





int main() {

    Pointer<Book> book(new Book("1984", "orwell"));
    if(book) { cout << "if(book)" << endl;}
    if(book == nullptr) { cout << "if(book == nullptr)" << endl;}
    if(!book) {cout << "if(!book)" << endl;}

    book->print();
    (*book).print();

    return 0;
}
