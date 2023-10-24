struct AssignableType {
    AssignableType& operator=(const AssignableType&) { return *this; }
};

struct NonAssignableType {
    NonAssignableType& operator=(const NonAssignableType&) = delete;
};

static_assert(__is_assignable(AssignableType, AssignableType), "AssignableType should be assignable");
static_assert(!__is_assignable(NonAssignableType, NonAssignableType), "NonAssignableType should not be assignable");

