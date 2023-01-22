#include "UserManager.h"

void UserManager::userRegistration() {

    User user = introduceNewUserInfo();

    users.push_back(user);
    userFileManager.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::introduceNewUserInfo() {

    User user;

    user.setId(getNewUserId());

    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (loginExistance(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::loginExistance(string login) {

    for (int i=0; i < users.size(); i++) {
        if (users[i].getLogin() == login)
            return true;
    }
    return false;
}

void UserManager::showWholeUsers() {

    for (int i=0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserManager::loadUsersFromFile() {
    userFileManager.loadUsersFromFile(users);
}
