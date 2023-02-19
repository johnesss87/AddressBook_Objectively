#include "SupportingMethods.h"

string SupportingMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportingMethods::convertStringToInt (string number) {

    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string SupportingMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

char SupportingMethods::loadChar() {
    string input = "";
    char character = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string SupportingMethods::changeFirstLetterToUppercaseAndRestToLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string SupportingMethods::downloadNumber(string text, int charPosition) {
    string number = "";
    while(isdigit(text[charPosition]) == true) {

        number += text[charPosition];
        charPosition ++;
    }
    return number;
}
