#pragma once
#include <string>

//returns true of the two hex digits after '*' match the computed checksum
bool validateChecksum(const std::string& sentence);