struct NoThrowType {
    NoThrowType& operator=(const NoThrowType&) noexcept { return *this; }
};
struct MightThrowOnCopyAssign {
    MightThrowOnCopyAssign& operator=(const MightThrowOnCopyAssign&) noexcept(false) { return *this; }
};
struct MightThrowOnMoveAssign {
    MightThrowOnMoveAssign& operator=(MightThrowOnMoveAssign&&) noexcept(false) { return *this; }
};

static_assert(__is_nothrow_assignable(NoThrowType&, const NoThrowType&), "NoThrowType should be nothrow copy assignable");
static_assert(!__is_nothrow_assignable(MightThrowOnCopyAssign&, const MightThrowOnCopyAssign&), "MightThrowOnCopyAssign should not be nothrow copy assignable");
static_assert(!__is_nothrow_assignable(MightThrowOnMoveAssign&, MightThrowOnMoveAssign&&), "MightThrowOnMoveAssign should not be nothrow move assignable");
