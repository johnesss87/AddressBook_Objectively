#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;

class SupportingMethods {

public:
    static string convertIntToString (int number);
    static string loadLine();
    static char loadChar();
    static string changeFirstLetterToUppercaseAndRestToLowercase(string text);
};

#endif
