#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "ContactFileManager.h"

class ContactManager {

    const int ID_LOGGED_USER;
    vector <Contact> contacts;
    Contact introduceNewContactInfo();
    int getNewContactId();
    void showContactInfo(Contact contact);
    void numberOfSearchedContacts(int contactNumbers);
    int enterIdContact();
    char selectOptionFromEditMenu();
    ContactFileManager contactFileManager;

public:
    ContactManager(string contactsFileName, int idLoggedUser)
        : ID_LOGGED_USER(idLoggedUser), contactFileManager(contactsFileName) {
            contacts = contactFileManager.loadContactsFromFile(ID_LOGGED_USER);
        };
    void enterNewContact();
    void showWholeContacts();
    void searchByName();
    void searchBySurname();
    void deleteContactFromAddressBook();
    void editContact();
};

#endif
