#ifndef USERFILEMANAGER_H
#define USERFILEMANAGER_H

#include <vector>

#include "User.h"
#include "SupportingMethods.h"

class UserFileManager {

    const string USERS_FILE_NAME;
    string userInfoSplitByVerticalLines (User user);
    User downloadUserInfo(string userInfoSplitByVerticalLines);

public:
    UserFileManager(string usersFileName) : USERS_FILE_NAME(usersFileName){};
    bool addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
};

#endif

