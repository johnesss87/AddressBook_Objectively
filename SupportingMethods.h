#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class SupportingMethods {

public:
    static string convertIntToString (int number);
    static int convertStringToInt (string number);
    static string loadLine();
    static char loadChar();
    static string changeFirstLetterToUppercaseAndRestToLowercase(string text);
    static string downloadNumber (string text, int charPosition);
    static bool isFileEmpty(fstream &textFile);
};

#endif
