#include "UserFileManager.h"

UserFileManager::UserFileManager() {
    usersFileName = "Users.txt";
}

void UserFileManager::addUserToFile(User user) {
    string lineWithUserInfo = "";
    textFile.open(usersFileName.c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithUserInfo = userInfoSplitByVerticalLines(user);

        if (isFileEmpty() == true) {
            textFile << lineWithUserInfo;
        } else {
            textFile << endl << lineWithUserInfo ;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << usersFileName << " i zapisac w nim danych." << endl;
    textFile.close();
}

bool UserFileManager::isFileEmpty() {
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string UserFileManager::userInfoSplitByVerticalLines(User user) {
    string lineWithUserInfo = "";
    lineWithUserInfo += SupportingMethods::convertIntToString(user.getId())+ '|';
    lineWithUserInfo += user.getLogin() + '|';
    lineWithUserInfo += user.getPassword() + '|';

    return lineWithUserInfo;
}
