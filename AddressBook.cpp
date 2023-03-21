#include "AddressBook.h"

void AddressBook::userRegistration() {
    userManager.userRegistration();
}

void AddressBook::userLogIn() {
    userManager.userLogIn();
    if (userManager.checkUserLoggedIn()) {
        contactManager = new ContactManager(CONTACTS_FILE_NAME,userManager.getIdLoggedUser());
    }
}

int AddressBook::idLoggedUser() {
    return userManager.getIdLoggedUser();
}

void AddressBook::UserLogOut() {
    userManager.userLogOut();
    delete contactManager;
    contactManager = NULL;
}

void AddressBook::showWholeUsers() {
    userManager.showWholeUsers();
}

void AddressBook::enterNewContact() {
    if (userManager.checkUserLoggedIn()) {
        contactManager->enterNewContact();
    } else {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void AddressBook::showWholeContacts() {
    contactManager->showWholeContacts();
}

void AddressBook::searchByName() {
    contactManager->searchByName();
}

void AddressBook::searchBySurname() {
    contactManager->searchBySurname();
}

void AddressBook::deleteContactFromAddressBook() {
    contactManager->deleteContactFromAddressBook();
}

void AddressBook::editContact() {
    contactManager->editContact();
}

void AddressBook::passwordChange() {
    userManager.passwordChange();
}
