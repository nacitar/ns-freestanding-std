class Class { };
// TODO: better check
static_assert(__has_trivial_destructor(Class), "__has_trivial_destructor() doesn't seem to be working properly.");
