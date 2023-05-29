template <typename... Ts>
struct TypeList {};

using StandardIntegralTypeList = TypeList<char, short, int, long, long long>;

constexpr int kBitsInChar = []() {
    unsigned char value = static_cast<unsigned char>(~0U);
    int bits = 0;
    while (value) {
        value >>= 1;
        ++bits;
    }
    return bits;
}();

template <unsigned int number_of_bits, typename... Ts>
constexpr bool AnyTypeOfBitSize() {
    return (... || (sizeof(Ts) * kBitsInChar == number_of_bits));
}

template<unsigned int number_of_bits, typename... Ts>
constexpr bool AnyTypeOfBitSize(TypeList<Ts...>) {
    return AnyTypeOfBitSize<number_of_bits, Ts...>();
}

template<unsigned int number_of_bits>
constexpr bool AnyStandardIntegralTypeOfBitSize() {
    return AnyTypeOfBitSize<number_of_bits>(StandardIntegralTypeList{});
}
