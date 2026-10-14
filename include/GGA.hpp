#pragma once
#include <string>
#include <cstdint>
using namespace std;
    
struct GGAdata { //list of each field in a GGA sentence (ordered)
    string utcTime; //raw string hhmmss.ss (temporary)
    double latitude; //decimal degrees - already converted
    double longitude; //decimal degrees - already converted
    int fixQuality; 
    int satellites;
    double hdop;
    double altitudeMeters;
    string altitudeRaw;
    double geoidSeparationMeters;
    string geoidSeparationRaw;
    double ageOfDGPS;
    string DGPSstationID;
    string NS;
    string EW;
    
};


//parses a GGA sentence into a GGAdata struct
//returns true on success
//returns false if the sentence is malformed or fails checksum.

bool parseGGA(const string& sentence, GGAdata& out);
