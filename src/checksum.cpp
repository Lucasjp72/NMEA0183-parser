#include "checksum.hpp"
using namespace std;

uint8_t computeChecksum(const string& sentence) {
    uint8_t checksum = 0;
    for(size_t i = 0; i < sentence.size(); ++i) {
        if(sentence[i] == '$') {  // find the position right after '$' character
            continue; // skip the '$' character
        }
        if(sentence[i] == '*') {  // loop through the characters until you hit '*'
            break; // stop at the '*' character: end of NMEA sentence
        }
        checksum ^= static_cast<uint8_t>(sentence[i]); // XOR each character into the checksum
    }
   
    
    return checksum; //return if the sentence is valid or not based on the checksum

}