#include <iostream>

#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook addressBook("Users.txt");
    addressBook.chooseOptionFromMainMenu();
//  addressBook.showWholeUsers();

    return 0;
}
