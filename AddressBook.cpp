#include "AddressBook.h"

AddressBook::AddressBook()
{
    usersFileName = "Users.txt";
}

void AddressBook::userRegistration() {

    User user = introduceNewUserInfo();

    users.push_back(user);
    addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User AddressBook::introduceNewUserInfo() {

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

int AddressBook::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool AddressBook::loginExistance(string login) {

    for (int i=0; i < users.size(); i++) {
        if (users[i].getLogin() == login)
            return true;
    }
    return false;
}

void AddressBook::showWholeUsers()
{

    for (int i=0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void AddressBook::addUserToFile(User user)
{
    fstream textFile;
    string lineWithUserInfo = "";
    textFile.open(usersFileName.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserInfo = userInfoSplitByVerticalLines(user);

        if (isFileEmpty(textFile) == true)
        {
            textFile << lineWithUserInfo;
        }
        else
        {
            textFile << endl << lineWithUserInfo ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << usersFileName << " i zapisac w nim danych." << endl;
    textFile.close();
}

string AddressBook::userInfoSplitByVerticalLines(User user)
{
    string lineWithUserInfo = "";

    lineWithUserInfo += convertIntToString(user.getId())+ '|';
    lineWithUserInfo += user.getLogin() + '|';
    lineWithUserInfo += user.getPassword() + '|';

    return lineWithUserInfo;
}

string AddressBook::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

bool AddressBook::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}





