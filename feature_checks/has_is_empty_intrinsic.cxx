struct EmptyType {};

struct NonEmptyType {
    int data;
};

static_assert(__is_empty(EmptyType), "EmptyType should be empty");
static_assert(!__is_empty(NonEmptyType), "NonEmptyType should not be empty");
