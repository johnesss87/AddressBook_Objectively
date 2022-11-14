#ifndef USERFILEMANAGER_H
#define USERFILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "SupportingMethods.h"

using namespace std;

class UserFileManager {

    string usersFileName;
    bool isFileEmpty();
    string userInfoSplitByVerticalLines (User user);
    fstream textFile;

public:
    UserFileManager();
    void addUserToFile(User user);

};

#endif

