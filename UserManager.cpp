#include "UserManager.h"

void UserManager::setIdLoggedUser(int newIdLoggedUser) {
    if (newIdLoggedUser >= 0)
        idLoggedUser = newIdLoggedUser;
}

int UserManager::getIdLoggedUser() {
    return idLoggedUser;
}

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

    for (int i=0; i < (int)users.size(); i++) {
        if (users[i].getLogin() == login)
            return true;
    }
    return false;
}

void UserManager::showWholeUsers() {

    for (int i=0; i < (int)users.size(); i++) {

        cout << endl << "ID Uzytkownika:     " << users[i].getId() << endl;
        cout << "Login:              " << users[i].getLogin() << endl;
        cout << "Haslo:              " << users[i].getPassword() << endl;
    }
    system("pause");
}

void UserManager::loadUsersFromFile() {
    users = userFileManager.loadUsersFromFile();
}

void UserManager::userLogIn() {

    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = SupportingMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int attempts = 3; attempts > 0; attempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
                password = SupportingMethods::loadLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idLoggedUser = itr -> getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo. Zostaniesz cofniety do glownego menu." << endl;
            system("pause");
            idLoggedUser = 0;
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem. Zostaniesz cofniety do glownego menu." << endl << endl;
    system("pause");
    idLoggedUser = 0;
    return;
}

void UserManager::passwordChange() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SupportingMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == idLoggedUser) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    userFileManager.saveAllUsersToFile(users);
}
