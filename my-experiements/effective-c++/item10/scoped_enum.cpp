#include<iostream>
#include<tuple>
#include<type_traits>


using std::cout;
using std::endl;

enum class InfoFields {
    NAME=0,
    EMAIL,
    REPUTATION,
};

using UserInfo = std::tuple<std::string, // Name
                            std::string, // Email
                            std::size_t>;// Reputation

template <typename E>
constexpr auto 
    toUType(E e) noexcept {
        return static_cast<std::underlying_type_t<E>>(e);
}



int main(int argc, char** argv) {

    UserInfo uInfo0 = std::make_tuple("User0", "user0@email.com", 0);
    UserInfo uInfo1{"User1", "user1@email.com", 1};

    cout << "uInfo0[NAME] = ";
    cout << std::get<static_cast<std::size_t>(InfoFields::NAME)>(uInfo0);
    cout << endl;

    cout << "uInfo1[NAME] = ";
    //cout << std::get<toInt(UserInfo::NAME)>(uInfo1);
    cout << endl;


    cout << "uInfo1[REPUTATION] = ";
    //cout << std::get<toInt(UserInfo::REPUTATION)>(uInfo1);
    cout << endl;


    cout << "INT(REPUTATION) = " << toUType(UserInfo::REPUTATION)>(uInfo1);
    cout << endl;

    return 0;
}


