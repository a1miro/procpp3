#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Figure
{
    public:
        //Public static variables
        static const int MAX_VERTEXES = 6;
        static const int TOTAL_ANGELS = 360.0f;
        static const std::vector<std::string> FIGURES_NAMES;
        const static float pi; 


        // Public interface 
        Figure(const std::vector<float>& angels);

        Figure(const Figure&);
        Figure& operator=(const Figure&);

        virtual draw() = 0;


    private:
        // Private interface
        void copy_from(const Figure& fg);



    private:
        // Instance variables
        std::vector<float> angels_;
        std::string name_;
};

const std::vector<std::string> Figure::FIGURES_NAMES = {
    "Zero",
    "Point",
    "Section",
    "Triangle",
    "Quadrangle",
    "Pentagon",
    "Hexagon"
};

const float Figure::pi = 3.14f;


Figure::Figure(const std::vector<float>& angels) :
    angels_(angels), name_(FIGURES_NAMES[angels.size()])
{

}

void Figure::copy_from(const Figure& fg)
{
    angels_ = fg.angels_;
    name_   = fg.name_;
}



Figure::Figure(const Figure& fg)
{
    copy_from(fg);

}

Figure& Figure::operator=(const Figure& fg)
{
    copy_from(fg);

    return *this;
}


class Zero : public Figure
{
    public:
        //Public interface
        Zero() : Figure (std::vector<float> zero) {;}
}






int main()
{


    return 0;
}
