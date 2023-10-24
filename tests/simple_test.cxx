static_assert(1 == 1);
//##include <stdio.h>
//#include <utility>

#include <ns/std/cstddef>
#include <ns/std/cstdlib>
#include <ns/std/concepts>

//NS_STD::ptrdiff_t xyz;


// is_pointer
struct A
{
    int m;
    void f() {}
};

int A::*mem_data_ptr = &A::m;     // a pointer to member data
void (A::*mem_fun_ptr)() = &A::f; // a pointer to member function

static_assert(
       ! NS_STD::is_pointer_v<A>    // same thing as above, but in C++17!
    && ! NS_STD::is_pointer<A>()    // same as above, using inherited operator bool
    && ! NS_STD::is_pointer<A>{}    // ditto
    && ! NS_STD::is_pointer<A>()()  // same as above, using inherited operator()
    && ! NS_STD::is_pointer<A>{}()  // ditto
    &&   NS_STD::is_pointer_v<A*>
    &&   NS_STD::is_pointer_v<A const* volatile>
    && ! NS_STD::is_pointer_v<A&>
    && ! NS_STD::is_pointer_v<decltype(mem_data_ptr)>
    && ! NS_STD::is_pointer_v<decltype(mem_fun_ptr)>
    &&   NS_STD::is_pointer_v<void*>
    && ! NS_STD::is_pointer_v<int>
    &&   NS_STD::is_pointer_v<int*>
    &&   NS_STD::is_pointer_v<int**>
    && ! NS_STD::is_pointer_v<int[10]>
    && ! NS_STD::is_pointer_v<NS_STD::nullptr_t>
    &&   NS_STD::is_pointer_v<void (*)()>
);


// is_array
// TODO
// #include <ns/std/array>
static_assert(
       ! NS_STD::is_array_v<A>
    &&   NS_STD::is_array_v<A[]>
    &&   NS_STD::is_array_v<A[3]>
    && ! NS_STD::is_array_v<float>
    && ! NS_STD::is_array_v<int>
    &&   NS_STD::is_array_v<int[]>
    &&   NS_STD::is_array_v<int[3]>
//    &&   NS_STD::is_array_v<NS_STD::array<int, 3>>
);

// Test cases
struct Foo {
    int data_member;
    void member_function() {}
};

static_assert(NS_STD::is_member_object_pointer_v<int Foo::*>, "Should be true for member object pointers");
static_assert(!NS_STD::is_member_object_pointer_v<void (Foo::*)()>, "Should be false for member function pointers");
static_assert(!NS_STD::is_member_object_pointer_v<int>, "Should be false for non-member types");


static_assert(NS_STD::is_const<const int>::value, "const int should be const");
static_assert(!NS_STD::is_const<int>::value, "int should not be const");

static_assert(NS_STD::is_volatile<volatile int>::value, "volatile int should be volatile");
static_assert(!NS_STD::is_volatile<int>::value, "int should not be volatile");

static_assert(NS_STD::is_bounded_array<int[5]>::value, "int[5] should be a bounded array");
static_assert(!NS_STD::is_bounded_array<int[]>::value, "int[] should not be a bounded array");
static_assert(!NS_STD::is_bounded_array<int>::value, "int should not be a bounded array");
static_assert(!NS_STD::is_bounded_array<Foo>::value, "Foo should not be a bounded array");

static_assert(NS_STD::is_unbounded_array<int[]>::value, "int[] should be an unbounded array");
static_assert(!NS_STD::is_unbounded_array<int[5]>::value, "int[5] should not be an unbounded array");
static_assert(!NS_STD::is_unbounded_array<int>::value, "int should not be an unbounded array");

struct DefaultConstructibleType {
};

struct NonDefaultConstructibleType {
    private:
    NonDefaultConstructibleType() {}
};

static_assert(NS_STD::is_default_constructible<DefaultConstructibleType>::value, "DefaultConstructibleType should be default constructible");
static_assert(!NS_STD::is_default_constructible<NonDefaultConstructibleType>::value, "NonDefaultConstructibleType should not be default constructible");
