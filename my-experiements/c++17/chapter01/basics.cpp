#include<iostream>
#include<tuple>
#include<string>
#include<cstdint>

// enables s-suffix for std::string literals  
using namespace std::string_literals; 

namespace procpp4::chapter1 {
    using std::cout;
    using std::endl;

    // Literals
    auto decimal_literal = 123;
    auto octal_literal = 0173;
    auto hex_literal = 0x7B;
    auto bin_literal = 0b11001010;
    auto floating_literal = 3.14f;
    auto double_literal = 3.14;
    
    // Character literals  
    auto c0 =   'A'; // char  
    auto c1 = u8'A'; // char  
    auto c2 =  L'A'; // wchar_t  
    auto c3 =  u'A'; // char16_t  
    auto c4 =  U'A'; // char32_t  
    
    // String literals  
    auto s0 =   "hello"; // const char*  
    auto s1 = u8"hello"; // const char*, encoded as UTF-8  
    auto s2 =  L"hello"; // const wchar_t*  
    auto s3 =  u"hello"; // const char16_t*, encoded as UTF-16  
    auto s4 =  U"hello"; // const char32_t*, encoded as UTF-32  
    
   // Raw string literals containing unescaped \ and "  
   auto R0 =   R"("Hello \ world")"; // const char*  
   auto R1 = u8R"("Hello \ world")"; // const char*, encoded as UTF-8  
   auto R2 =  LR"("Hello \ world")"; // const wchar_t*  
   auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16  
   auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32  



   // Combining string literals with standard s-suffix  
   auto S0 =   "hello"s; // std::string  
   auto S1 = u8"hello"s; // std::string  
   auto S2 =  L"hello"s; // std::wstring  
   auto S3 =  u"hello"s; // std::u16string  
   auto S4 =  U"hello"s; // std::u32string  

    // Combining raw string literals with standard s-suffix  
    auto S5 =   R"("Hello \ world")"s; // std::string from a raw const char*  
    auto S6 = u8R"("Hello \ world")"s; // std::string from a raw const char*, encoded as UTF-8  
    auto S7 =  LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*  
    auto S8 =  uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16  
    auto S9 =  UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32  

    std::tuple literals(
            decimal_literal, 
            octal_literal,
            hex_literal,
            bin_literal,
            floating_literal,
            double_literal,
            c0,c1,c2,c3,c4,
            s0,s1,s2,s3,s4,
            R0,R1,R2,R3,R4,
            S0, S1, S2, S3, S4,
            S5, S6, S7, S8, S9
            );

    enum class literal_id {
        decimal_literal = 0, 
        octal_literal,
        hex_literal,
        bin_literal,
        floating_literal,
        double_literal,
        c0,c1,c2,c3,c4,
        s0,s1,s2,s3,s4,
        R0,R1,R2,R3,R4,
        S0, S1, S2, S3, S4,
        S5, S6, S7, S8, S9
    };

    // Types
    uint8_t ui8;
    int8_t  i8;
    uint16_t ui16;
    int16_t i16;
    uint32_t ui32;
    int32_t  i32;
    uint64_t ui64;
    int64_t   i64;



int32_t get_id() { return 1; }

enum class color 
{
    BLACK = 0,
    RED,
    GREEN,
    BLUE,
    WHITE = 255,
    MAX
};


color my_favorite_colors[3] = {color::BLACK, color::RED, color::WHITE};


// This function returns the value of my_favorite_colors[c] but not the object itself!!!!
auto get_my_favorite_color1(int c) { return my_favorite_colors[c]; }
// to solve this problem and get the original object, use decltype(auto) 
decltype(auto) get_my_favorite_color2(int c) { return my_favorite_colors[c]; }

void print_color(color c) {
    cout << "Entering function " << __func__ << endl;
    
    switch(c) 
    {
        case color::BLACK:
            cout << "BLACK" << endl;
            break;
        case color::WHITE:
            cout << "WHITE" << endl;
            break;
        case color::GREEN:
            cout << "GREEN" << endl;
            break;
        case color::RED:
            cout << "RED" << endl;
            break;
        case color::BLUE:
            cout << "BLUE" << endl;
            break;
        default:
            cout << "Unknown color code!" << endl;
            break;
    }


    cout << "Leaving function " << __func__ << endl;
}

} // namespace procpp4::chapter1 


int main(int argc, char** argv) 
{

    //using std::tuple_size;
    using std::cout;
    using std::endl;
    using std::get;

    using namespace procpp4::chapter1;
    cout << get<10>(literals) << endl;
    cout << get<static_cast<int>(literal_id::c1)>(literals) << endl;
    cout << get<static_cast<int>(literal_id::s2)>(literals) << endl;
    cout << get<static_cast<int>(literal_id::R3)>(literals) << endl;
    //cout << get<static_cast<int>(literal_id::S4)>(literals) << endl;
    cout << get<static_cast<int>(literal_id::S6)>(literals) << endl;

    // if with initializer section
    if ( int32_t id = get_id() ; id == 1) 
    {
        cout << "id = " << id << endl;
    }

    // switch with no fallthrough
    color c = color::GREEN;
    switch(c) 
    {
        case color::BLACK:
        case color::WHITE:
            cout << "Do nothing if this BLACK or WHITE" << endl;
            break;
        case color::GREEN:
            cout << "GREEN" << endl;
            break;
        case color::RED:
            cout << "RED" << endl;
            break;
        case color::BLUE:
            cout << "BLUE" << endl;
            break;
        default:
            cout << "Unknown color code!" << endl;
            break;
    }

    // C++17 switch with fallthrough attribute
    c = color::BLACK;
    switch(c) 
    {
        case color::BLACK:
            [[fallthrough]]
        case color::WHITE:
            cout << "Do nothing if this BLACK or WHITE" << endl;
            break;
        case color::GREEN:
            cout << "GREEN" << endl;
            break;
        case color::RED:
            cout << "RED" << endl;
            break;
        case color::BLUE:
            cout << "BLUE" << endl;
            break;
        default:
            cout << "Unknown color code!" << endl;
            break;
    }

    // C++17 case with initializer and the range
    switch(c = color::GREEN; c) 
    {
        case color::BLACK:
            [[fallthrough]]
        case color::WHITE:
                cout << "Do nothing if this BLACK or WHITE" << endl;
                break;
        case color::RED...color::BLUE:
                cout << "RED,GREEN OR BLUE" << endl;
                break;
        default:
                cout << "Unknown color code!" << endl;
                break;
    }

    
    //COMPILER ERROR! get_my_favorite_color1(1) = color::BLACK; 
    //This one fine, func2 usses decltype(auto)
    get_my_favorite_color2(1) = color::BLACK; 
    print_color(get_my_favorite_color2(1));

    return 0;
}
