#include <ns/std/type_traits>
 
class A {};
class B : A {};
class C : B {};
class D {};
union E {};
 
static_assert(NS_STD::is_base_of_v<A, A>     == true  &&
              NS_STD::is_base_of_v<A, B>     == true  &&
              NS_STD::is_base_of_v<A, C>     == true  &&
              NS_STD::is_base_of_v<A, D>     == false &&
              NS_STD::is_base_of_v<B, A>     == false &&
              NS_STD::is_base_of_v<E, E>     == false &&
              NS_STD::is_base_of_v<int, int> == false);
