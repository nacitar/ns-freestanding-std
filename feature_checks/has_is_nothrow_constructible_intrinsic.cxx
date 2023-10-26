struct NoThrowType {};
struct MightThrowOnCopy {
    MightThrowOnCopy(const MightThrowOnCopy&) noexcept(false) {}
};
struct MightThrowOnMove {
    MightThrowOnMove(MightThrowOnMove&&) noexcept(false) {}
};

static_assert(__is_nothrow_constructible(NoThrowType), "NoThrowType should be nothrow default constructible");
static_assert(!__is_nothrow_constructible(MightThrowOnCopy, const MightThrowOnCopy&), "MightThrowOnCopy should not be nothrow copy constructible");
static_assert(!__is_nothrow_constructible(MightThrowOnMove, MightThrowOnMove&&), "MightThrowOnMove should not be nothrow move constructible");
