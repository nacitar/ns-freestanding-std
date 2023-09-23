// This header exists to resolve a circular dependency in the library.
//
// <concepts> builds upon <type_traits>, <type_traits> needs <cstddef> for
// size_t, and <cstddef> defines the "byte" type with a constraint.
//
// [support.types.byteops]/17.2.5 (C++20):
// - Constraints: is_integral_v<IntType> is true.
//
// In order to implement this constraint <cstddef> would circularly need
// <type_traits> or <concepts>.  In the interest of better error messages, the
// concept "integral" was chosen instead of "is_integral_v" as the standard
// itself mentions.  The minimum components necessary to define "integral" have
// been pulled out of their appropriate headers and placed here in order to
// resolve the circular dependency.
#ifndef NS_STD_NS_STD_DETAIL__CORE_HXX_
#define NS_STD_NS_STD_DETAIL__CORE_HXX_

namespace NS_STD {

//// <type_traits>
// [meta.help]/20.15.4 (C++20): defines integral_constant
template<class T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant<T, v>;
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};
// [meta.type.synop]/20.15.3 (C++20):
// - defines bool_constant, true_type, false_type
template <bool B>
using bool_constant = integral_constant<bool, B>;
using true_type = bool_constant<true>;
using false_type = bool_constant<false>;
// [meta.unary.cat]/20.15.5.2 (C++20):
// - is_integral: T is an integral type (6.8.2)
// [basic.fundamental]/6.8.2 (C++20): integral types
template <class T>
struct is_integral : false_type {};
template <> struct is_integral<bool> : true_type {};
template <> struct is_integral<char> : true_type {};
template <> struct is_integral<signed char> : true_type {};
template <> struct is_integral<unsigned char> : true_type {};
#ifdef __cpp_char8_t
template <> struct is_integral<char8_t> : true_type {};
#endif
#ifdef __cpp_unicode_characters
template <> struct is_integral<char16_t> : true_type {};
template <> struct is_integral<char32_t> : true_type {};
#endif
template <> struct is_integral<wchar_t> : true_type {};
template <> struct is_integral<short> : true_type {};
template <> struct is_integral<unsigned short> : true_type {};
template <> struct is_integral<int> : true_type {};
template <> struct is_integral<unsigned int> : true_type {};
template <> struct is_integral<long> : true_type {};
template <> struct is_integral<unsigned long> : true_type {};
template <> struct is_integral<long long> : true_type {};
template <> struct is_integral<unsigned long long> : true_type {};
// [meta.type.synop]/20.15.3 (C++20): defines is_integral_v
template <class T>
constexpr bool is_integral_v = is_integral<T>::value;

//// <concepts>
// [concepts.arithmetic]/18.4.7 (C++20): defines integral
template<class T>
concept integral = is_integral_v<T>;

}  // namespace NS_STD

#endif  // NS_STD_NS_STD_DETAIL__CORE_HXX_
