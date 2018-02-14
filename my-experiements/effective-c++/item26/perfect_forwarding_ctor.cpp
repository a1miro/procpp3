#include <iostream>
#include <type_traits>

using namespace std;

class Person {
    public:
        template < typename T,
                 typename = std::enable_if<!std::is_base_of<Person, std::decay_t<T>>::value &&
                     ! std::is_integral<std::remove_reference_t<T>>::value >>
                     explicit Person(T&& n) : name(std::forward<T>(n)) 
                     {
                         // assert that a std::string can be created from a T object
                         static_assert(
                                 std::is_constructible<std::string, T>::value,
                                 "Parameter n can't be used to construct std::string"
                                 );
                     }


    private:
        std::string name;
};


int main(int argc, char** argv) {

    //Person p (u"Andrei Mironenko");
    Person p("Andrei"); 
    


    return 0;
}
