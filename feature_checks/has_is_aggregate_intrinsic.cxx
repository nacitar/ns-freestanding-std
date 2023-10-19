struct AggregateType {
    int a;
    double b;
};

struct NonAggregateType {
    private:
        int a;
    public:
        NonAggregateType(int x) : a(x) {}
};

static_assert(__is_aggregate(AggregateType), "AggregateType should be an aggregate");
static_assert(!__is_aggregate(NonAggregateType), "NonAggregateType should not be an aggregate");
