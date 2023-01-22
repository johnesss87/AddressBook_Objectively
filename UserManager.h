#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserFileManager.h"
#include "SupportingMethods.h"

using namespace std;

class UserManager {

    int idLoggedUser;
    vector <User> users;

    User introduceNewUserInfo();
    int getNewUserId();
    bool loginExistance(string login);
    UserFileManager userFileManager;

public:
    UserManager (string usersFileName) : userFileManager(usersFileName) {};
    void userRegistration();
    void userLogIn();
    void passwordChange();
    void showWholeUsers();
    void loadUsersFromFile();

};

#endif


