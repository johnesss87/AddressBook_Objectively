#include "ContactManager.h"

void ContactManager::enterNewContact() {

    system("cls");

    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    Contact contact = introduceNewContactInfo();

    contacts.push_back(contact);
    if (contactFileManager.addContactToFile(contact)) {
        cout << endl << "Adresat zostal pomyslnie dodany." << endl;
    } else {
        cout << "Blad. Nie udalo sie dodac adresata do pliku." << endl;
    }
    system("pause");
}

Contact ContactManager::introduceNewContactInfo() {

    Contact contact;

    string name, surname, phoneNumber, email, address;

    contact.setIdUser(ID_LOGGED_USER);
    contact.setIdContact(contactFileManager.getIdLastContact() + 1);

    cout << "Podaj imie: ";
    name = SupportingMethods::loadLine();
    name = SupportingMethods::changeFirstLetterToUppercaseAndRestToLowercase(name);
    contact.setName(name);

    cout << "Podaj nazwisko: ";
    surname = SupportingMethods::loadLine();
    surname = SupportingMethods::changeFirstLetterToUppercaseAndRestToLowercase(surname);
    contact.setSurname(surname);


    cout << "Podaj numer telefonu: ";
    phoneNumber = SupportingMethods::loadLine();
    contact.setPhoneNumber(phoneNumber);

    cout << "Podaj email: ";
    email = SupportingMethods::loadLine();
    contact.setEmail(email);

    cout << "Podaj adres: ";
    address = SupportingMethods::loadLine();
    contact.setAddress(address);

    return contact;
}

void ContactManager::showWholeContacts() {

    system("cls");

    if (!contacts.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Contact> :: iterator itr = contacts.begin(); itr != contacts.end(); itr++) {
            showContactInfo(*itr);
        }
        cout << endl;
    }

    else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void ContactManager::showContactInfo(Contact contact) {

    cout << endl << "Contact ID:         " << contact.getIdContact() << endl;
    cout << "Imie:               " << contact.getName() << endl;
    cout << "Nazwisko:           " << contact.getSurname() << endl;
    cout << "Numer telefonu:     " << contact.getPhoneNumber() << endl;
    cout << "Email:              " << contact.getEmail() << endl;
    cout << "Adres:              " << contact.getAddress() << endl;
}

void ContactManager::numberOfSearchedContacts(int contactNumbers) {
    if (contactNumbers == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << contactNumbers << endl << endl;
}

void ContactManager::searchByName() {
    string searchedName = "";
    int contactNumbers = 0;

    system("cls");
    if (!contacts.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        searchedName = SupportingMethods::loadLine();
        searchedName = SupportingMethods::changeFirstLetterToUppercaseAndRestToLowercase(searchedName);

        for (vector <Contact>::iterator  itr = contacts.begin(); itr != contacts.end(); itr++) {
            if (itr -> getName() == searchedName) {
                showContactInfo(*itr);
                contactNumbers++;
            }
        }
        numberOfSearchedContacts(contactNumbers);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void ContactManager::searchBySurname() {
    string searchedSurname;
    int contactNumbers = 0;

    system("cls");
    if (!contacts.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        searchedSurname = SupportingMethods::loadLine();
        searchedSurname = SupportingMethods::changeFirstLetterToUppercaseAndRestToLowercase(searchedSurname);

        for (vector <Contact>::iterator itr = contacts.begin(); itr != contacts.end(); itr++) {
            if (itr -> getSurname() == searchedSurname) {
                showContactInfo(*itr);
                contactNumbers++;
            }
        }
        numberOfSearchedContacts(contactNumbers);
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

int ContactManager::enterIdContact() {
    int idSelectedContact = 0;
    cout << "Podaj numer ID Adresata: ";
    idSelectedContact  = SupportingMethods::loadInteger();
    return idSelectedContact;
}

void ContactManager::deleteContactFromAddressBook() {
    int idContactNumberToDelete = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idContactNumberToDelete = enterIdContact();

    char choice;
    bool ifContactExist = false;

    for (vector <Contact>::iterator itr = contacts.begin(); itr != contacts.end(); itr++) {
        if (itr -> getIdContact() == idContactNumberToDelete) {
            ifContactExist = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            choice = SupportingMethods::loadChar();
            if (choice == 't') {
                if (itr -> getIdContact() == contactFileManager.getIdLastContact()) {
                    contactFileManager.removeContactFromFile(idContactNumberToDelete, true);
                } else {
                    contactFileManager.removeContactFromFile(idContactNumberToDelete, false);
                }
                contacts.erase(itr);
                --itr;
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (ifContactExist == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

char ContactManager::selectOptionFromEditMenu() {
    char choice;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    choice = SupportingMethods::loadChar();

    return choice;
}

void ContactManager::editContact() {
    system("cls");
    int idContactNumberToEdit = 0;
    int contactLinePointer = 0;
    string name, surname, phoneNumber, email, address;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idContactNumberToEdit = enterIdContact();

    char choice;
    bool ifContactExist = false;

    for (int i = 0; i < (int)contacts.size(); i++) {
        if (contacts[i].getIdContact() == idContactNumberToEdit) {
            contactLinePointer = i;
            ifContactExist = true;

            while(choice != '6') {

                choice = selectOptionFromEditMenu();

                switch (choice) {
                case '1':
                    cout << "Podaj nowe imie: ";
                    name = SupportingMethods::loadLine();
                    name = SupportingMethods::changeFirstLetterToUppercaseAndRestToLowercase(name);
                    contacts[i].setName(name);
                    break;
                case '2':
                    cout << "Podaj nowe nazwisko: ";
                    surname = SupportingMethods::loadLine();
                    surname = SupportingMethods::changeFirstLetterToUppercaseAndRestToLowercase(surname);
                    contacts[i].setSurname(surname);
                    break;
                case '3':
                    cout << "Podaj nowy numer telefonu: ";
                    phoneNumber = SupportingMethods::loadLine();
                    phoneNumber = SupportingMethods::changeFirstLetterToUppercaseAndRestToLowercase(phoneNumber);
                    contacts[i].setPhoneNumber(phoneNumber);
                    break;
                case '4':
                    cout << "Podaj nowy email: ";
                    email = SupportingMethods::loadLine();
                    contacts[i].setEmail(email);
                    break;
                case '5':
                    cout << "Podaj nowy adres zamieszkania: ";
                    address = SupportingMethods::loadLine();
                    contacts[i].setAddress(address);
                    break;
                case '6':
                    cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                    break;
                }
                contactFileManager.makeChangeInFile(contacts, contactLinePointer);
            }
        }
    }

    if (ifContactExist == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}
