#ifndef CONTACTFILEMANAGER_H
#define CONTACTFILEMANAGER_H

#include <vector>

#include "Contact.h"
#include "SupportingMethods.h"

class ContactFileManager {

    const string CONTACTS_FILE_NAME;
    string contactInfoSplitByVerticalLines (Contact contact);
    Contact downloadContactInfo(string contactInfoSplitByVerticalLines);
    int downloadUserIdfromInfoSplitByVerticalLines(string contactInfoSplitByVerticalLines);
    int downloadContactIdfromInfoSplitByVerticalLines(string contactInfoSplitByVerticalLines);
    int idLastContact;

public:
    ContactFileManager(string contactsFileName) : CONTACTS_FILE_NAME(contactsFileName){
        idLastContact = 0;
    };
    bool addContactToFile(Contact contact);
    vector <Contact> loadContactsFromFile(int idLoggedUser);
    int getIdLastContact();
};

#endif

