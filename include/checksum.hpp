#pragma once //compiles once
#include <cstdint>
#include <string>

using namespace std;

//computes the XOR checksum of an NMEA sentence
//the sentence should be a full raw sentence with the $ and the *hh checksum

uint8_t computeChecksum(const string& sentence);
