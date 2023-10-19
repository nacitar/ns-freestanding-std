struct TrivialClass {
    int member;
};
struct NonTrivialClass {
    NonTrivialClass() : member(42) {} // User-defined default constructor
    int member;
};

static_assert(__is_trivial(TrivialClass), "TrivialClass should be trivial");
static_assert(!__is_trivial(NonTrivialClass), "NonTrivialClass should not be trivial");
