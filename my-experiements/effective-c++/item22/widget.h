#include<iostream>
#include<memory>


class Widget {

    public:

        Widget();
        virtual ~Widget();

        // Copy ctor and assign operator
        Widget(const Widget& rhs);
        Widget& operator=(const Widget& rhs);

        // Move ctor and assign operator
        Widget(Widget&& rhs);
        Widget& operator=(Widget&& rhs);


        void background();
        void foreground();


    private:
        struct Impl;
        std::unique_ptr<Impl> impl_;
};
