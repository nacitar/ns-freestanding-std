#include <feature_check_common.hxx>
static_assert(
    AnyStandardIntegralTypeOfBitSize<16>(),
    "None of the integral types is exactly 16 bits."
);
