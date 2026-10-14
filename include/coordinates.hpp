#pragma once
#include <string>
#include <cstdint>
 using namespace std;
 //computes (calibrates) the raw coords from the NMEA sentence to decimal degrees
double nmeaCoordToDecimal(const string& raw, char hemisphere, int degreeDigits);