#include <cassert>
#include <cmath>
#include "GGA.hpp"

bool approxEqual(double a, double b, double epsilon = 0.0001) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    GGAdata data;
    bool ok = parseGGA("$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47", data);

    assert(ok == true);
    assert(data.utcTime == "123519");
    assert(approxEqual(data.latitude, 48.1173));
    assert(approxEqual(data.longitude, 11.5167));
    assert(data.fixQuality == 1);
    assert(data.satellites == 8);
    assert(approxEqual(data.hdop, 0.9));
    assert(approxEqual(data.altitudeMeters, 545.4));
    assert(approxEqual(data.ageOfDGPS, 0.0));

    // Bad checksum should fail cleanly
    GGAdata bad;
    assert(parseGGA("$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*48", bad) == false);
}