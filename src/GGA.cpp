#include "GGA.hpp"
#include "split.hpp"
#include "validate.hpp"
#include "coordinates.hpp"
#include <iostream>
using namespace std;

bool parseGGA(const string& sentence, GGAdata& out) { //gathers each field from split algorithm and organizes it
    cout << "sentence: [" << sentence << "]\n";
    cout << "checksum valid? " << validateChecksum(sentence) << "\n";

    if (!validateChecksum(sentence)) { //if checksum is invalid, return false
        return false;
    }
    auto fields = splitFields(sentence);
    cout << "field count: " << fields.size() << "\n";
    
    if (fields.size() != 14) { // GGA sentences should have 14 fields
        return false;
    }

    out.utcTime = fields[0];
    out.NS = fields[2];
    out.EW = fields[4];

    out.latitude = nmeaCoordToDecimal(fields[1], out.NS[0], 2); //converts raw latitude to decimal
    out.longitude = nmeaCoordToDecimal(fields[3], out.EW[0], 3); // //converts raw longitude to decimal
    out.fixQuality = stoi(fields[5]); //conversion then inserts it into fields list
    out.satellites = stoi(fields[6]); //converts then inserts into fields list
    out.hdop = stod(fields[7]);
    out.altitudeRaw = fields[8];
    out.altitudeMeters = stod(fields[8]);
    out.geoidSeparationRaw = fields[10];
    out.geoidSeparationMeters = stod(fields[10]);
    out.ageOfDGPS = fields[12].empty() ? 0.0 : stod(fields[12]); //if index 12 is empty set the age to 0.0 if not convert it to a double and insert it into the fields list
    out.DGPSstationID = fields[13];

    return true; //return true if parsing was successful
}