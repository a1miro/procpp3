struct Widget::Impl {
    Impl() = default;
    Impl(const Impl& rhs) = default;
    Impl& operator=(const Impl& rhs) = default;
    void background();
    void foreground();
};


