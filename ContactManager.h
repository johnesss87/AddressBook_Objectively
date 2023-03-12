#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "ContactFileManager.h"

class ContactManager {

    const int ID_LOGGED_USER;
    vector <Contact> contacts;
    Contact introduceNewContactInfo();
    int getNewContactId();
    void showContactInfo(Contact contact);
    ContactFileManager contactFileManager;

public:
    ContactManager(string contactsFileName, int idLoggedUser)
        : contactFileManager(contactsFileName), ID_LOGGED_USER(idLoggedUser) {
            contacts = contactFileManager.loadContactsFromFile(ID_LOGGED_USER);
        };
    void enterNewContact();
    void showWholeContacts();
};

#endif


