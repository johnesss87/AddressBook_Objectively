#include "SupportingMethods.h"

string SupportingMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string SupportingMethods::loadLine(){
    string input = "";
    getline(cin, input);
    return input;
}

