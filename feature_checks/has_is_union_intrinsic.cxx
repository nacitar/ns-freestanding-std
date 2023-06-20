union Union { };
class Class { };
static_assert(__is_union(Union), "__is_union() gave a false negative.");
static_assert(!__is_union(Class), "__is_union() gave a false positive.");
