#include "ContactFileManager.h"

void ContactFileManager::addContactToFile(Contact contact) {
    string lineWithContactInfo = "";
    fstream textFile;
    textFile.open(contactsFileName.c_str(), ios::out | ios::app);

    if (textFile.good() == true) {
        lineWithContactInfo = contactInfoSplitByVerticalLines(contact);

        if (isFileEmpty() == true) {
            textFile << lineWithContactInfo;
        } else {
            textFile << endl << lineWithContactInfo ;
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    textFile.close();
}

bool ContactFileManager::isFileEmpty() {

    fstream textFile;
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string ContactFileManager::contactInfoSplitByVerticalLines(Contact contact) {

    string lineWithContactInfo = "";

    lineWithContactInfo += SupportingMethods::convertIntToString(contact.getIdContact())+ '|';
    lineWithContactInfo += SupportingMethods::convertIntToString(contact.getIdUser())+ '|';
    lineWithContactInfo += contact.getName() + '|';
    lineWithContactInfo += contact.getSurname() + '|';
    lineWithContactInfo += contact.getPhoneNumber() + '|';
    lineWithContactInfo += contact.getEmail() + '|';
    lineWithContactInfo += contact.getAddress() + '|';

    return lineWithContactInfo;
}
