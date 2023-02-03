#ifndef CONTACTFILEMANAGER_H
#define CONTACTFILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Contact.h"
#include "SupportingMethods.h"

using namespace std;

class ContactFileManager {

    const string contactsFileName = "AddressBook.txt";
    bool isFileEmpty();
    string contactInfoSplitByVerticalLines (Contact contact);

public:

    void addContactToFile(Contact contact);
};

#endif
