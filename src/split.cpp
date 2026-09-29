#include "split.hpp"
#include <vector>
#include <string>
#include "validate.hpp"

std::vector<std::string> splitFields(const std::string& sentence) {
    std::vector<std::string> fields;
    std::string currentField;

    size_t firstComma = sentence.find(',');
    if (firstComma == std::string::npos) {
        return {};
    }

    for (size_t i = firstComma + 1; i < sentence.size(); ++i) {
        char c = sentence[i];
        if (c == '*') {
            fields.push_back(currentField);
            currentField.clear();
            break;
        }
        if (c == ',') {
            fields.push_back(currentField);
            currentField.clear();
            continue;
        }
        currentField += c;
    }

    return fields;
}
