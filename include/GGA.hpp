#pragma once
#include <string>
#include <cstdint>

struct GGAdata {
    std::string utcTime; //raw string hhmmss.ss (temporary)
    double latitude; //decimal degrees - already converted
    double longitude; //decimal degrees - already converted
    int fixQuality;
    int satellites;
    double hdop;
    double altitudeMeters;
};


//Parses a GGA sentence into a GGAdata struct
//Returns true on success, false if the sentence is malformed or fails checksum.

bool parseGGA(const std::string& sentence, GGAdata& out);
