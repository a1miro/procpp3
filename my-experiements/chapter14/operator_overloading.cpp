#include<iostream>
#include<cstdint>

#include<random>
#include<memory>
#include<ctime>

using namespace std;

class One {
    public:

       friend ostream& operator<<(ostream& stream, const One& obj) {
            stream << (obj.negative_ ? "-" : "+"); 
            stream << "object(" << obj.name_ << ", ";
            stream << obj.id_ << "), ";
            stream << "count_ = " << obj.count_ << endl;
            return stream;
        }

        One(const string& name):
            id_((uint64_t)rand()), 
            name_(name),
            negative_(false),
            count_(0)
    {}
        One(const char* name):
            id_((uint64_t)rand()), 
            name_(name),
            negative_(false),
            count_(0)
    {}

        One(const One& obj) : 
            id_(obj.id_), 
            name_(obj.name_),
            negative_(false),
            count_(0)
    {}
        One& operator=(const One& obj) {
            id_         = obj.id_; 
            name_       = obj.name_;
            negative_   = obj.negative_;
            count_      = obj.count_;
        }

        One(One&& obj) : 
            id_(move(obj.id_)), 
            name_(move(obj.name_)),
            negative_(move(obj.negative_)),
            count_(move(obj.count_))
    {}
        One& operator=(One&& obj){
            id_ = move(obj.id_);
            name_ = move(obj.name_); 
            negative_ = move(obj.negative_);
            count_ = move(obj.count_);
        }


        uint64_t getId() const {return id_;}


        bool operator==(const One& rhs) const {
            return id_ == rhs.id_;
        }


        bool operator<(const One& rhs) const {
            return id_ < rhs.id_;
        }

        bool operator>(const One& rhs) const {
            return id_ > rhs.id_;
        }

        bool operator<=(const One& rhs) const {
            return id_ <= rhs.id_;
        }

        bool operator>=(const One& rhs) const {
            return id_ >= rhs.id_;
        }

        bool operator!=(const One& rhs) const {
            return id_ != rhs.id_;
        }


        // Unary minus operator
        One operator-() {
            One obj(*this);
            obj.negative_ = negative_ ? false : true;
            return obj;
        }

        // Unary plus operator
         One operator+() {
            One obj(*this);
            obj.negative_ = negative_ ? true : false;
            return obj;
        }

        // Prefix ++ and -- operators
        One& operator++() {
            ++count_;
            return *this;
        }

        One& operator--() {
            if (count_ > 0) {
                --count_;
            }
            return *this;
        }

        // Postfix operators ++ and --
        One operator++(int) {
            One old(*this);
            count_++;
            return old;
        }

        One operator--(int) {
            One old(*this);
            if (count_ > 0) {
                count_--;
            }
            return old;
        }






    private:
        uint64_t id_;
        string name_;
        bool negative_=false;
        uint32_t count_;
};

int main() {
    using namespace std;

    srand(time(NULL));

    shared_ptr<One> one = make_shared<One>("one");
    shared_ptr<One> two = make_shared<One>("two");
    
    // copyt ctor
    shared_ptr<One> two_copy = make_shared<One>(*two);

    // move ctor
    shared_ptr<One> three = make_shared<One>(One("three"));
    
    cout << *two_copy << endl;
    cout << *three << endl;

    cout << "one = " << one->getId() << endl;
    cout << "two = " << two->getId() << endl;

    cout << "creating negative four" << endl;
    shared_ptr<One> four = make_shared<One>(-One("four"));
    cout << *four << endl;

    cout << "applying unary + to four" << endl;
    *four = +(*four);
    cout << *four << endl;

    cout << "change the sign again to + for four" << endl;
    *four = -(*four);
    cout << *four << endl;

    cout << "increment counter for object four" << endl;
    ++(*four);
    cout << *four << endl;

    cout << "decrement counter for object four" << endl;
    --(*four);
    cout << *four << endl;

    cout << "increment counter for object four" << endl;
    (*four)++;
    cout << *four << endl;

    cout << "decrement counter for object four" << endl;
    (*four)--;
    cout << *four << endl;

    cout << "Is one bigger than two? " << ((*one > *two) ? "Yes": "No") << endl;



    return 0;
}
