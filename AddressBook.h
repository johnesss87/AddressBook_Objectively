#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"

using namespace std;

class AddressBook

{
    int idLoggedUser;
    int idLastContact;
    int idRemovedContact;

    vector <User> users;

   User introduceNewUserInfo();
   int getNewUserId();
   bool loginExistance(string login);

public:
    void userRegistration();
    void showWholeUsers();
};
