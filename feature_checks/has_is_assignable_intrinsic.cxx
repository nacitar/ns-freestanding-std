struct AssignableType {
    AssignableType& operator=(const AssignableType&) { return *this; }
};
struct NonAssignableType {
    NonAssignableType& operator=(const NonAssignableType&) = delete;
};

struct CopyAssignableType {
    CopyAssignableType& operator=(const CopyAssignableType&) { return *this; }
};
struct NonCopyAssignableType {
    NonCopyAssignableType& operator=(const NonCopyAssignableType&) = delete;
};

struct MoveAssignableType {
    MoveAssignableType& operator=(MoveAssignableType&&) { return *this; }
};
struct NonMoveAssignableType {
    NonMoveAssignableType& operator=(NonMoveAssignableType&&) = delete;
};

static_assert(__is_assignable(AssignableType, AssignableType), "AssignableType should be assignable");
static_assert(!__is_assignable(NonAssignableType, NonAssignableType), "NonAssignableType should not be assignable");

static_assert(__is_assignable(CopyAssignableType&, const CopyAssignableType&), "CopyAssignableType should be copy assignable");
static_assert(!__is_assignable(NonCopyAssignableType&, const NonCopyAssignableType&), "NonCopyAssignableType should not be copy assignable");

static_assert(__is_assignable(MoveAssignableType&, MoveAssignableType&&), "MoveAssignableType should be move assignable");
static_assert(!__is_assignable(NonMoveAssignableType&, NonMoveAssignableType&&), "NonMoveAssignableType should not be move assignable");
