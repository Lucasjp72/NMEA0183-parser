#include "validate.hpp"
#include "checksum.hpp"

bool validateChecksum(const std::string& sentence){
    int correctChecksum;
    int computedChecksum;

    size_t starLocation = sentence.find('*'); //find the position of '*'
    if (starLocation == std::string::npos){
        return false;
    } 
    if (starLocation + 3 != sentence.size()){ //make sure there are exactly two hex digits after '*'
        return false;
    }
    correctChecksum = std::stoi(sentence.substr(starLocation + 1, 2), nullptr, 16); //collect the checksum from the sentence
    computedChecksum = computeChecksum(sentence.substr(0, starLocation)); //compute the checksum of the sentence without the '*' and the two hex digits
    

    return correctChecksum == computedChecksum; //compare it to the computed checksum
    
}