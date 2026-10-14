#include "coordinates.hpp"
#include <string>
#include <cmath>
using namespace std;

double nmeaCoordToDecimal(const string& raw, char hemisphere, int degreeDigits){
    double degrees = stod(raw.substr(0, degreeDigits)); //extracts the degrees part
    double minutes = stod(raw.substr(degreeDigits)); //extracts the minutes part
    double decimal = degrees + minutes / 60.0; //converts to fractional degree 
    if (hemisphere == 'S' || hemisphere == 'W') { //based on direction flips the sign
        decimal = -decimal;
    }
    return decimal; //returns the final decimal coordinate


}