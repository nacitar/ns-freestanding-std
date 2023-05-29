#include <feature_check_common.hxx>
static_assert(
    AnyStandardIntegralTypeOfBitSize<32>(),
    "None of the integral types is exactly 32 bits."
);
