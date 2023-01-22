#ifndef USERFILEMANAGER_H
#define USERFILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "SupportingMethods.h"

using namespace std;

class UserFileManager {

    string usersFileName;
    bool isFileEmpty();
    string userInfoSplitByVerticalLines (User user);
    fstream textFile;
    User downloadUserInfo(string userInfoSplitByVerticalLines);

public:
    UserFileManager();
    void addUserToFile(User user);
    void loadUsersFromFile(vector <User> &users);

};

#endif

