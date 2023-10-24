struct MyType {
    MyType(int, double) {}
};

struct NonConstructibleType {
    private:
    NonConstructibleType() {}
};

static_assert(__is_constructible(MyType, int, double), "MyType should be constructible with int and double");
static_assert(!__is_constructible(NonConstructibleType), "NonConstructibleType should not be default-constructible");
