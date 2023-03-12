#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "UserManager.h"
#include "ContactManager.h"

class AddressBook {

    UserManager userManager;
    ContactManager *contactManager;
    const string CONTACTS_FILE_NAME;

public:
    AddressBook(string usersFileName, string contactsFileName)
        : userManager(usersFileName), CONTACTS_FILE_NAME(contactsFileName) {
        contactManager = NULL;
    };
    ~AddressBook() {
    delete contactManager;
    contactManager = NULL;
    };
    int idLoggedUser();
    void userRegistration();
    void userLogIn();
    void UserLogOut();
    void showWholeUsers();
    void enterNewContact();
    void showWholeContacts();
    void passwordChange();
};

#endif
