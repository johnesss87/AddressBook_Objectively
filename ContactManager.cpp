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
