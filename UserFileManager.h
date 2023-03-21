#ifndef USERFILEMANAGER_H
#define USERFILEMANAGER_H

#include <vector>

#include "TextFileManager.h"
#include "User.h"
#include "SupportingMethods.h"

class UserFileManager :public TextFileManager {

    string userInfoSplitByVerticalLines (User user);
    User downloadUserInfo(string userInfoSplitByVerticalLines);

public:
    UserFileManager(string usersFileName) : TextFileManager(usersFileName){};
    bool addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
};

#endif
