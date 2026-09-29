#include <cassert>
#include <cmath>
#include "coordinates.hpp"

bool approxEqual(double a, double b, double epsilon = 0.0001) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    // Latitude: 4807.038 N -> 48 + 7.038/60 = 48.1173
    assert(approxEqual(nmeaCoordToDecimal("4807.038", 'N', 2), 48.1173));

    // Longitude: 01131.000 E -> 11 + 31.000/60 = 11.5167
    assert(approxEqual(nmeaCoordToDecimal("01131.000", 'E', 3), 11.5167));

    // Southern hemisphere should be negative
    assert(approxEqual(nmeaCoordToDecimal("4807.038", 'S', 2), -48.1173));

    // Western hemisphere should be negative
    assert(approxEqual(nmeaCoordToDecimal("01131.000", 'W', 3), -11.5167));
}