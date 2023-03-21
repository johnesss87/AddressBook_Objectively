#ifndef CONTACTFILEMANAGER_H
#define CONTACTFILEMANAGER_H

#include <vector>

#include "TextFileManager.h"
#include "Contact.h"
#include "SupportingMethods.h"

class ContactFileManager :public TextFileManager
{
    string contactInfoSplitByVerticalLines (Contact contact);
    Contact downloadContactInfo(string contactInfoSplitByVerticalLines);
    int downloadUserIdfromInfoSplitByVerticalLines(string contactInfoSplitByVerticalLines);
    int downloadContactIdfromInfoSplitByVerticalLines(string contactInfoSplitByVerticalLines);
    int idLastContact;

public:
    ContactFileManager(string contactsFileName) : TextFileManager(contactsFileName){
        idLastContact = 0;
    };
    bool addContactToFile(Contact contact);
    vector <Contact> loadContactsFromFile(int idLoggedUser);
    int getIdLastContact();
    void removeContactFromFile(int idContactNumberToDelete, bool lastContactPointer);
    void makeChangeInFile (vector <Contact> contacts, int contactLinePointer);
};

#endif
