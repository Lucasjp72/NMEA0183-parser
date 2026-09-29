#include "coordinates.hpp"
#include <string>
#include <cmath>

double nmeaCoordToDecimal(const std::string& raw, char hemisphere, int degreeDigits){
    double degrees = std::stod(raw.substr(0, degreeDigits)); //extracts the degrees part
    double minutes = std::stod(raw.substr(degreeDigits)); //extracts the minutes part
    double decimal = degrees + minutes / 60.0; //converts to fractional degree 
    if (hemisphere == 'S' || hemisphere == 'W') { //based on direction flips the sign
        decimal = -decimal;
    }
    return decimal; //returns the final decimal coordinate


}