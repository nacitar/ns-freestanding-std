struct TrivialType {};
struct NonTrivialCopyAssign {
    NonTrivialCopyAssign& operator=(const NonTrivialCopyAssign&) { return *this; }
};
struct NonTrivialMoveAssign {
    NonTrivialMoveAssign& operator=(NonTrivialMoveAssign&&) { return *this; }
};

static_assert(__is_trivially_assignable(TrivialType&, TrivialType), "TrivialType should be trivially copy assignable");
static_assert(!__is_trivially_assignable(NonTrivialCopyAssign&, const NonTrivialCopyAssign&), "NonTrivialCopyAssign should not be trivially copy assignable");
static_assert(!__is_trivially_assignable(NonTrivialMoveAssign&, NonTrivialMoveAssign&&), "NonTrivialMoveAssign should not be trivially move assignable");
