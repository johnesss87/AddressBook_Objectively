#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include <conio.h>

#include "UserManager.h"
#include "ContactManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;
    ContactManager contactManager;

public:
    AddressBook(string usersFileName, string contactsFileName) : userManager(usersFileName), contactManager(contactsFileName)  {
        userManager.loadUsersFromFile();
        };
    int idLoggedUser();
    void userRegistration();
    void userLogIn();
    void UserLogOut();
    void showWholeUsers();
    void loadContactsFromFile();
    void enterNewContact();
    void showWholeContacts();
    void passwordChange();
};

#endif
