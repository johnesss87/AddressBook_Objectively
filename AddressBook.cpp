#include "AddressBook.h"

void AddressBook::chooseOptionFromMainMenu() {

    while (true) {
        if (userManager.idLoggedUser == 0) {
            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";


            choice = getch();

//          choice = SupportingMethods::loadChar();

            switch (choice) {
            case '1':
                userManager.userRegistration();
                break;
            case '2':
                userManager.userLogIn();
                chooseOptionFromUserMenu();
                break;
            case '9':
                cout << endl << "Good Bye" << endl;
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}

void AddressBook::chooseOptionFromUserMenu() {

    ContactManager contactManager;

    while (userManager.idLoggedUser != 0) {

        system("cls");
        cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Dodaj adresata" << endl;
        cout << "2. Wyszukaj po imieniu" << endl;
        cout << "3. Wyszukaj po nazwisku" << endl;
        cout << "4. Wyswietl adresatow" << endl;
        cout << "5. Usun adresata" << endl;
        cout << "6. Edytuj adresata" << endl;
        cout << "---------------------------" << endl;
        cout << "7. Zmien haslo" << endl;
        cout << "8. Wyloguj sie" << endl;
        cout << "---------------------------" << endl;
        cout << "Twoj wybor: ";

        choice = getch();

        switch (choice) {
        case '1':
            contactManager.enterNewContact(userManager.idLoggedUser);
            cout << endl << "wyszedlem" << endl;
            break;
        case '2':
//               wyszukajAdresatowPoImieniu(adresaci);
            break;
        case '3':
//               wyszukajAdresatowPoNazwisku(adresaci);
            break;
        case '4':
            contactManager.showWholeContacts();
            break;
        case '5':
//                idUsunietegoAdresata = usunAdresata(adresaci);
//                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
            break;
        case '6':
//                edytujAdresata(adresaci);
            break;
        case '7':
            userManager.passwordChange();
            break;
        case '8':
            userManager.idLoggedUser = 0;
            cout << endl << "Uzytkownik zostal wylogowany!" << endl << endl;
            system("pause");
//              adresaci.clear();
            break;
        default:
            cout << "Nie ma takiej opcji w menu!!!" << endl << endl;
            system("pause");
            break;
        }
    }
}

void AddressBook::showWholeUsers() {
    userManager.showWholeUsers();
}





