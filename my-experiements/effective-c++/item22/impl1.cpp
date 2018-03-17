#include<iostream>

#include"widget.h"
#include"impl.h"

using std::cout;
using std::endl;

void Widget::Impl::background() {
    cout <<"impl1:" << __FUNCTION__ << endl;
}

void Widget::Impl::foreground() {
    cout <<"impl1:" << __FUNCTION__ << endl;
}
