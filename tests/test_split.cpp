#include <cassert>
#include <vector>
#include <string>
#include "split.hpp"

int main() {
    auto fields = splitFields("$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");

    assert(fields.size() == 14);
    assert(fields[0] == "123519");
    assert(fields[1] == "4807.038");
    assert(fields[2] == "N");
    assert(fields[12] == "");  // second-to-last field, empty
    assert(fields[13] == "");  // last field, empty

    auto noComma = splitFields("nocommahere");
    assert(noComma.empty());
}