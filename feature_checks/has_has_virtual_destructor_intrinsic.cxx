class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

class NonVirtualDestructor {
public:
    ~NonVirtualDestructor() {}
};

static_assert(__has_virtual_destructor(Base), "Base should have a virtual destructor.");
static_assert(__has_virtual_destructor(Derived), "Derived should have a virtual destructor.");
static_assert(!__has_virtual_destructor(NonVirtualDestructor), "NonVirtualDestructor should not have a virtual destructor.");
static_assert(!__has_virtual_destructor(int), "int should not have a virtual destructor.");
