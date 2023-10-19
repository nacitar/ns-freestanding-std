struct TriviallyCopyableType {
    int data;
};

struct NonTriviallyCopyableType {
    NonTriviallyCopyableType(const NonTriviallyCopyableType& other) : data(other.data) {}
    int data;
};

static_assert(__is_trivially_copyable(TriviallyCopyableType), "TriviallyCopyableType should be trivially copyable");
static_assert(!__is_trivially_copyable(NonTriviallyCopyableType), "NonTriviallyCopyableType should not be trivially copyable");
