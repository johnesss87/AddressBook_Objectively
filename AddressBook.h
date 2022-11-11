#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"

using namespace std;

class AddressBook

{
    int idLoggedUser;
    int idLastContact;
    int idRemovedContact;

    string usersFileName;

    vector <User> users;

   User introduceNewUserInfo();
   int getNewUserId();
   bool loginExistance(string login);
   void addUserToFile(User user);
   string userInfoSplitByVerticalLines (User user);
   string convertIntToString (int number);
   bool isFileEmpty(fstream &textFile);

public:
    AddressBook();
    void userRegistration();
    void showWholeUsers();
};
