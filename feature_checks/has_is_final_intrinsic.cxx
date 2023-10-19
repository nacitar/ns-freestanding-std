struct RegularType {
    virtual void foo() {}
};

struct FinalType final {
    virtual void foo() {}
};

static_assert(!__is_final(RegularType), "RegularType should not be final");
static_assert(__is_final(FinalType), "FinalType should be final");
