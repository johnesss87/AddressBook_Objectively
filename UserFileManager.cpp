#include "UserFileManager.h"

bool UserFileManager::addUserToFile(User user) {
    string lineWithUserInfo = "";
    fstream textFile;
    textFile.open(USERS_FILE_NAME.c_str(), ios::app);

    if (textFile.good()) {
        lineWithUserInfo = userInfoSplitByVerticalLines(user);

        if (SupportingMethods::isFileEmpty(textFile)) {
            textFile << lineWithUserInfo;
        } else {
            textFile << endl << lineWithUserInfo ;
        }
        textFile.close();
        return true;
    }
    return false;
}

string UserFileManager::userInfoSplitByVerticalLines(User user) {
    string lineWithUserInfo = "";
    lineWithUserInfo += SupportingMethods::convertIntToString(user.getId())+ '|';
    lineWithUserInfo += user.getLogin() + '|';
    lineWithUserInfo += user.getPassword() + '|';

    return lineWithUserInfo;
}

vector <User> UserFileManager::loadUsersFromFile() {
    User user;
    vector <User> users;
    string userInfoSplitByVerticalLines = "";
    fstream textFile;

    textFile.open(USERS_FILE_NAME.c_str(), ios::in);

    if (textFile.good()) {
        while (getline(textFile, userInfoSplitByVerticalLines)) {
            user = downloadUserInfo(userInfoSplitByVerticalLines);
            users.push_back(user);
        }
        textFile.close();
    }
    return users;
}

User UserFileManager::downloadUserInfo(string userInfoSplitByVerticalLines) {
    User user;
    string lineWithUserInfo = "";
    int singleUserDataNumber = 1;

    for (int charPosition = 0; charPosition < (int)userInfoSplitByVerticalLines.length(); charPosition++) {
        if (userInfoSplitByVerticalLines[charPosition] != '|') {
            lineWithUserInfo += userInfoSplitByVerticalLines[charPosition];
        } else {
            switch(singleUserDataNumber) {
            case 1:
                user.setId(atoi(lineWithUserInfo.c_str()));
                break;
            case 2:
                user.setLogin(lineWithUserInfo);
                break;
            case 3:
                user.setPassword(lineWithUserInfo);
                break;
            }
            lineWithUserInfo = "";
            singleUserDataNumber++;
        }
    }
    return user;
}

void UserFileManager::saveAllUsersToFile(vector <User> users) {

    string lineWithUserInfo = "";
    fstream textFile;

    vector <User>::iterator itrEnd = --users.end();

    textFile.open(USERS_FILE_NAME.c_str(), ios::out);

    if (textFile.good()) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            lineWithUserInfo = userInfoSplitByVerticalLines(*itr);

            if (itr == itrEnd) {
                textFile << lineWithUserInfo;
            } else {
                textFile << lineWithUserInfo << endl;
            }
            lineWithUserInfo = "";
        }
    } else {
        cout << "Nie mozna otworzyc pliku " << USERS_FILE_NAME << endl;
    }
    textFile.close();
}
