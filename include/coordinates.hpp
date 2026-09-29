#pragma once
#include <string>
#include <cstdint>

double nmeaCoordToDecimal(const std::string& raw, char hemisphere, int degreeDigits);