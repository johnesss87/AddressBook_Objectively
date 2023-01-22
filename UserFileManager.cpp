#include "UserFileManager.h"


void UserFileManager::addUserToFile(User user) {
    string lineWithUserInfo = "";
    fstream textFile;
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
    fstream textFile;
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

vector <User> UserFileManager::loadUsersFromFile()
{
    User user;
    vector <User> users;
    string userInfoSplitByVerticalLines = "";
    fstream textFile;

    textFile.open(usersFileName.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, userInfoSplitByVerticalLines))
        {
            user = downloadUserInfo(userInfoSplitByVerticalLines);
            users.push_back(user);
        }
        textFile.close();
    }
    return users;
}

User UserFileManager::downloadUserInfo(string userInfoSplitByVerticalLines)
{
    User user;
    string lineWithUserInfo = "";
    int singleUserDataNumber = 1;

    for (int charPosition = 0; charPosition < userInfoSplitByVerticalLines.length(); charPosition++)
    {
        if (userInfoSplitByVerticalLines[charPosition] != '|')
        {
            lineWithUserInfo += userInfoSplitByVerticalLines[charPosition];
        }
        else
        {
            switch(singleUserDataNumber)
            {
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
