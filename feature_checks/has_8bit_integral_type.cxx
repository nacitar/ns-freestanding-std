#include <feature_check_common.hxx>
static_assert(
    AnyStandardIntegralTypeOfBitSize<8>(),
    "None of the integral types is exactly 8 bits."
);
