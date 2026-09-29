#include "GGA.hpp"
#include "split.hpp"
#include "validate.hpp"
#include "coordinates.hpp"
#include <iostream>

bool parseGGA(const std::string& sentence, GGAdata& out) { //gathers each field from split algorithm and organizes it
    std::cout << "sentence: [" << sentence << "]\n";
    std::cout << "checksum valid? " << validateChecksum(sentence) << "\n";

    if (!validateChecksum(sentence)) { //if checksum is invalid, return false
        return false;
    }
    auto fields = splitFields(sentence);
    std::cout << "field count: " << fields.size() << "\n";
    
    if (fields.size() != 14) { // GGA sentences should have 14 fields
        return false;
    }

    out.utcTime = fields[0];
    out.NS = fields[2];
    out.EW = fields[4];

    out.latitude = nmeaCoordToDecimal(fields[1], out.NS[0], 2); //converts raw latitude to decimal
    out.longitude = nmeaCoordToDecimal(fields[3], out.EW[0], 3); // //converts raw longitude to decimal
    out.fixQuality = std::stoi(fields[5]); 
    out.satellites = std::stoi(fields[6]);
    out.hdop = std::stod(fields[7]);
    out.altitudeRaw = fields[8];
    out.altitudeMeters = std::stod(fields[8]);
    out.geoidSeparationRaw = fields[10];
    out.geoidSeparationMeters = std::stod(fields[10]);
    out.ageOfDGPS = fields[12].empty() ? 0.0 : std::stod(fields[12]);
    out.DGPSstationID = fields[13];

    return true; //return true if parsing was successful
}