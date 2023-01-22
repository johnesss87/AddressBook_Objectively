#include <iostream>

#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook addressBook("Users.txt");
    addressBook.userRegistration();
    addressBook.userRegistration();
    addressBook.userLogIn();
    addressBook.passwordChange();
    addressBook.showWholeUsers();

    return 0;
}
