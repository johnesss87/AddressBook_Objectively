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

    Contact introduceNewContactInfo(int idLoggedUser);
    int getNewContactId();
    void showContactInfo(Contact contact);
    ContactFileManager contactFileManager;

public:

    void enterNewContact(int idLoggedUser);
    void showWholeContacts();

};

#endif


