#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include <conio.h>

#include "User.h"
#include "UserManager.h"
#include "ContactManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;
    char choice;

public:
    AddressBook(string usersFileName) : userManager(usersFileName) {
        userManager.loadUsersFromFile();
        };
    void chooseOptionFromMainMenu();
    void chooseOptionFromUserMenu();
};

#endif
