#include <feature_check_common.hxx>
static_assert(
    AnyStandardIntegralTypeOfBitSize<64>(),
    "None of the integral types is exactly 64 bits."
);
