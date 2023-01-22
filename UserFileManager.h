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

    const string usersFileName;
    bool isFileEmpty();
    string userInfoSplitByVerticalLines (User user);
    User downloadUserInfo(string userInfoSplitByVerticalLines);

public:
    UserFileManager(string USERSFILENAME) : usersFileName(USERSFILENAME){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif

