#include<iostream>

#include"widget.h"
#include"impl.h"

using std::cout;
using std::endl;

void Widget::Impl::background() {
    cout <<"impl2:" << __FUNCTION__ << endl;
}

void Widget::Impl::foreground() {
    cout <<"impl2:" << __FUNCTION__ << endl;
}
