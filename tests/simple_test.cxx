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
       ! std::is_pointer_v<A>    // same thing as above, but in C++17!
    && ! std::is_pointer<A>()    // same as above, using inherited operator bool
    && ! std::is_pointer<A>{}    // ditto
    && ! std::is_pointer<A>()()  // same as above, using inherited operator()
    && ! std::is_pointer<A>{}()  // ditto
    &&   std::is_pointer_v<A*>
    &&   std::is_pointer_v<A const* volatile>
    && ! std::is_pointer_v<A&>
    && ! std::is_pointer_v<decltype(mem_data_ptr)>
    && ! std::is_pointer_v<decltype(mem_fun_ptr)>
    &&   std::is_pointer_v<void*>
    && ! std::is_pointer_v<int>
    &&   std::is_pointer_v<int*>
    &&   std::is_pointer_v<int**>
    && ! std::is_pointer_v<int[10]>
    && ! std::is_pointer_v<std::nullptr_t>
    &&   std::is_pointer_v<void (*)()>
);


// is_array
// TODO
// #include <ns/std/array>
static_assert(
       ! std::is_array_v<A>
    &&   std::is_array_v<A[]>
    &&   std::is_array_v<A[3]>
    && ! std::is_array_v<float>
    && ! std::is_array_v<int>
    &&   std::is_array_v<int[]>
    &&   std::is_array_v<int[3]>
//    &&   std::is_array_v<std::array<int, 3>>
);
