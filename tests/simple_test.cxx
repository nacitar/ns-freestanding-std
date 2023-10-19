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


static_assert(std::is_const<const int>::value, "const int should be const");
static_assert(!std::is_const<int>::value, "int should not be const");

static_assert(std::is_volatile<volatile int>::value, "volatile int should be volatile");
static_assert(!std::is_volatile<int>::value, "int should not be volatile");
