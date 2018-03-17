#include <iostream>
#include "widget.h"
#include "impl.h"


Widget::Widget() : impl_(std::make_unique<Impl>()) {;}
Widget::~Widget() = default;

Widget::Widget(Widget&& rhs) = default;
Widget& Widget::operator=(Widget&& rhs) = default;

Widget::Widget(const Widget& rhs) : impl_(std::make_unique<Impl>(*rhs.impl_)) {}
Widget& Widget::operator=(const Widget& rhs) {
    *impl_ = *rhs.impl_;
    return *this;
}

void Widget::background() {
    impl_->background();
}

void Widget::foreground() {
    impl_->foreground();
}



