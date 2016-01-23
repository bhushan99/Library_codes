// Library code
// takes lo, hi, P() such that:
// P(lo) is true
// P(hi) is false
// If P(x) is true and (x > y) then P(y) is true
// If P(x) is false and (x < y) then P(y) is false
// returns the maximum x such that P(x) is true

template<class D> D BinarySearch(D lo, D hi, std::function<bool(D)> P) {
    while (lo + 1 < hi) {
        D ha = lo + (hi - lo) / 2;
        if (P(ha)) {
            lo = ha;
        } else {
            hi = ha;
        }
    }
    return lo;
}

bool possibleHeight(long h);

// Calling: BinarySearch<long>(0, 32622777, possibleHeight);