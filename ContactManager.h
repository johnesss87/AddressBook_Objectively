#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Contact.h"
#include "ContactFileManager.h"
#include "SupportingMethods.h"

using namespace std;

class ContactManager {

    vector <Contact> contacts;
    Contact introduceNewContactInfo(int idLoggedUser, int idLastContact);
    int getNewContactId();
    void showContactInfo(Contact contact);
    ContactFileManager contactFileManager;

public:
    ContactManager(string contactsFileName) : contactFileManager(contactsFileName) {};
    void enterNewContact(int idLoggedUser);
    void showWholeContacts();
    void loadContactsFromFile(int idLoggedUser);
};

#endif


