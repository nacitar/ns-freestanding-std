struct NoPadding {
    char a;
    char b;
};

struct AlmostCertainlyWithPadding {
    char a;
    double b;
};

static_assert(__has_unique_object_representations(NoPadding), "NoPadding should have unique object representations.");
// TODO: how likely is this to not work?
static_assert(!__has_unique_object_representations(AlmostCertainlyWithPadding), "AlmostCertainlyWithPadding should not have unique object representations.");
