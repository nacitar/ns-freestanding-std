class Base { };
class Derived : Base { };
static_assert(__is_base_of(Base, Derived), "__is_base_of() doesn't seem to be working properly.");
