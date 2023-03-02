#include "AddressBook.h"

void AddressBook::userRegistration() {
    userManager.userRegistration();
}

void AddressBook::userLogIn() {
    userManager.userLogIn();
}

int AddressBook::idLoggedUser() {
    return userManager.getIdLoggedUser();
}

void AddressBook::UserLogOut() {
    userManager.setIdLoggedUser(0);
    contactManager.contactsVectorCleanUp();
}

void AddressBook::showWholeUsers() {
    userManager.showWholeUsers();
}

void AddressBook::loadContactsFromFile() {
    contactManager.loadContactsFromFile(userManager.getIdLoggedUser());
}

void AddressBook::enterNewContact() {
    contactManager.enterNewContact(userManager.getIdLoggedUser());
}

void AddressBook::showWholeContacts() {
    contactManager.showWholeContacts();
}

void AddressBook::passwordChange() {
    userManager.passwordChange();
}



