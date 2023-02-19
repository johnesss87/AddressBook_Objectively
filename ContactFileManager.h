#ifndef CONTACTFILEMANAGER_H
#define CONTACTFILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

#include "Contact.h"
#include "SupportingMethods.h"

using namespace std;

class ContactFileManager {

    const string contactsFileName;
    bool isFileEmpty();
    string contactInfoSplitByVerticalLines (Contact contact);
    Contact downloadContactInfo(string contactInfoSplitByVerticalLines);
    int downloadUserIdfromInfoSplitByVerticalLines(string contactInfoSplitByVerticalLines);
    int downloadContactIdfromInfoSplitByVerticalLines(string contactInfoSplitByVerticalLines);
    int idLastContactFromFile;
    void setIdLastContactFromFile(int idLastContact);

public:
    ContactFileManager(string contactsFileName) : contactsFileName(contactsFileName){};
    void addContactToFile(Contact contact);
    vector <Contact> loadContactsFromFile(int idLoggedUser);
    int getIdLastContactFromFile();
};

#endif

