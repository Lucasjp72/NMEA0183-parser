#pragma once
#include <string>
using namespace std;
//returns true of the two hex digits after '*' match the computed checksum
bool validateChecksum(const string& sentence);