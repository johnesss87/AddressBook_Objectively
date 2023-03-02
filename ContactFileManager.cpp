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

vector <Contact> ContactFileManager::loadContactsFromFile(int idLoggedUser) {
    Contact contact;
    vector <Contact> contacts;
    int idLastContact = 0;
    string contactInfoSplitByVerticalLines = "";
    string infoLastContactInFile = "";
    fstream textFile;

    textFile.open(contactsFileName.c_str(), ios::in);

    if (textFile.good() == true) {

        while (getline(textFile, contactInfoSplitByVerticalLines)) {

            if(idLoggedUser == downloadUserIdfromInfoSplitByVerticalLines(contactInfoSplitByVerticalLines)) {
                contact = downloadContactInfo(contactInfoSplitByVerticalLines);
                contacts.push_back(contact);
            }
        }
        infoLastContactInFile = contactInfoSplitByVerticalLines;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    textFile.close();

    if (infoLastContactInFile != "") {
        idLastContact = downloadContactIdfromInfoSplitByVerticalLines(infoLastContactInFile);
    } else {
        idLastContact = 0;
    }
    setIdLastContactFromFile(idLastContact);
    return contacts;
}

Contact ContactFileManager::downloadContactInfo(string contactInfoSplitByVerticalLines) {
    Contact contact;
    string lineWithContactInfo = "";
    int singleContactDataNumber = 1;

    for (int charPosition = 0; charPosition < (int)contactInfoSplitByVerticalLines.length(); charPosition++) {

        if (contactInfoSplitByVerticalLines[charPosition] != '|') {

            lineWithContactInfo += contactInfoSplitByVerticalLines[charPosition];
        } else {

            switch(singleContactDataNumber) {
            case 1:
                contact.setIdContact(atoi(lineWithContactInfo.c_str()));
                break;
            case 2:
                contact.setIdUser(atoi(lineWithContactInfo.c_str()));
                break;
            case 3:
                contact.setName(lineWithContactInfo);
                break;
            case 4:
                contact.setSurname(lineWithContactInfo);
                break;
            case 5:
                contact.setPhoneNumber(lineWithContactInfo);
                break;
            case 6:
                contact.setEmail(lineWithContactInfo);
                break;
            case 7:
                contact.setAddress(lineWithContactInfo);
                break;
            }
            lineWithContactInfo = "";
            singleContactDataNumber++;
        }
    }
    return contact;
}

void ContactFileManager::setIdLastContactFromFile(int idLastContact) {
    idLastContactFromFile = idLastContact;
}

int ContactFileManager::getIdLastContactFromFile() {
    return idLastContactFromFile;
}

int ContactFileManager::downloadUserIdfromInfoSplitByVerticalLines(string contactInfoSplitByVerticalLines) {

    int idUserStartingPosition = contactInfoSplitByVerticalLines.find_first_of('|') + 1;
    int idUser = SupportingMethods::convertStringToInt(SupportingMethods::downloadNumber(contactInfoSplitByVerticalLines, idUserStartingPosition));
    return idUser;
}

int ContactFileManager::downloadContactIdfromInfoSplitByVerticalLines(string contactInfoSplitByVerticalLines) {

    int idContactStartingPosition = 0;
    int idLastContactFromFile = SupportingMethods::convertStringToInt(SupportingMethods::downloadNumber(contactInfoSplitByVerticalLines,idContactStartingPosition));
    return idLastContactFromFile;
}






