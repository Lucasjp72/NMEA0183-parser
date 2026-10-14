#include "split.hpp"
#include <vector>
#include <string>
#include "validate.hpp"
using namespace std;

vector<string> splitFields(const string& sentence) {
    vector<string> fields;
    string currentField;

    size_t firstComma = sentence.find(',');
    if (firstComma == string::npos) { //if no comma is found then sentence is invalid and return empty set of fields
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
