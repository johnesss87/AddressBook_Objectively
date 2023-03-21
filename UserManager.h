#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "UserFileManager.h"

class UserManager {

    vector <User> users;
    User introduceNewUserInfo();
    int getNewUserId();
    bool loginExistance(string login);
    UserFileManager userFileManager;
    int idLoggedUser;

public:
    UserManager(string usersFileName) : userFileManager(usersFileName) {
        idLoggedUser = 0;
        users = userFileManager.loadUsersFromFile();
    };
    int getIdLoggedUser();
    void userRegistration();
    void userLogIn();
    void passwordChange();
    void showWholeUsers();
    bool checkUserLoggedIn();
    void userLogOut();
};

#endif

