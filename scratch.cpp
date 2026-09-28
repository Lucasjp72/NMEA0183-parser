#include <iostream>
#include "checksum.hpp"

int main() {
    std::string s = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    std::cout << std::hex << static_cast<int>(computeChecksum(s)) << "\n";
}