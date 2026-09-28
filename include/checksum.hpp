#pragma once
#include <cstdint>
#include <string>

//computes the XOR checksum of an NMEA setence string
//The sentence should be a full raw sentence, including the $ and the *hh checksum.

uint8_t computeChecksum(const std::string& sentence);
