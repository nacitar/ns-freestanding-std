struct TrivialType {};
struct NonTrivialType {
    NonTrivialType() {}
};

struct NonTrivialCopy {
    NonTrivialCopy(const NonTrivialCopy&) {}
};
struct NonTrivialMove {
    NonTrivialMove(NonTrivialMove&&) {}
};

static_assert(__is_trivially_constructible(TrivialType), "TrivialType should be trivially constructible");
static_assert(!__is_trivially_constructible(NonTrivialType), "NonTrivialType should not be trivially constructible");

static_assert(__is_trivially_constructible(TrivialType), "TrivialType should be trivially default constructible");
static_assert(!__is_trivially_constructible(NonTrivialCopy, const NonTrivialCopy&), "NonTrivialCopy should not be trivially copy constructible");
static_assert(!__is_trivially_constructible(NonTrivialMove, NonTrivialMove&&), "NonTrivialMove should not be trivially move constructible");
