#include "AddressBook.h"

int main() {

    char choice;
    AddressBook addressBook("Users.txt", "AddressBook.txt");

    while (true) {
        if (addressBook.idLoggedUser() == 0) {
            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "3. Wyswietl wszystkich uzytkownikow" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";

            choice = SupportingMethods::loadChar();

            switch (choice) {
            case '1':
                addressBook.userRegistration();
                break;
            case '2':
                addressBook.userLogIn();
                break;
            case '3':
                addressBook.showWholeUsers();
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
        } else {

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

            choice = SupportingMethods::loadChar();

            switch (choice) {
            case '1':
                addressBook.enterNewContact();
                break;
            case '2':
//               wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
//               wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                addressBook.showWholeContacts();
                break;
            case '5':
//                idUsunietegoAdresata = usunAdresata(adresaci);
//                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
//                edytujAdresata(adresaci);
                break;
            case '7':
                addressBook.passwordChange();
                break;
            case '8':
                addressBook.UserLogOut();
                cout << endl << "Uzytkownik zostal wylogowany!" << endl << endl;
                system("pause");
                break;
            default:
                cout << "Nie ma takiej opcji w menu!!!" << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
