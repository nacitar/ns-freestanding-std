struct StandardLayoutType {
    int a;
    double b;
};

struct NonStandardLayoutType {
    int a;
private:
    double b;
};

static_assert(__is_standard_layout(StandardLayoutType), "StandardLayoutType should be standard layout");
static_assert(!__is_standard_layout(NonStandardLayoutType), "NonStandardLayoutType should not be standard layout");
