struct NonPolymorphicType {
    void foo();
};

struct PolymorphicType {
    virtual void foo() {}
};

static_assert(!__is_polymorphic(NonPolymorphicType), "NonPolymorphicType should not be polymorphic");
static_assert(__is_polymorphic(PolymorphicType), "PolymorphicType should be polymorphic");
