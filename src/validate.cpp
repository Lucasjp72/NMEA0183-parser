#include "validate.hpp"
#include "checksum.hpp"
#include <iostream>

bool validateChecksum(const std::string& sentence){
    int correctChecksum;
    int computedChecksum;
    for (size_t i = 0; i < sentence.size(); ++i) {
        if (sentence[i] == '*'){ //find the position of '*'
            if (i + 3 != sentence.size()){ //make sure there are exactly two hex digits after '*'
                break;
            }
            correctChecksum = std::stoi(sentence.substr(i + 1, 2), nullptr, 16); //turn the two hex digits after '*' into an integer
            computedChecksum = computeChecksum(sentence.substr(0, i));
            break;
        }
    }
    std::cout << "star index: " << sentence.find('*') << ", sentence length: " << sentence.size() << "\n";
    std::cout << "correctChecksum: " << std::hex << correctChecksum << "\n";
    std::cout << "computedChecksum: " << std::hex << computedChecksum << "\n";
    return correctChecksum == computedChecksum; //compare it to the computed checksum
    
}