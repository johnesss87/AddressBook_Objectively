#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

using namespace std;

class Contact {

    int idContact;
    int idUser;
    string name;
    string surname;
    string phoneNumber;
    string email;
    string address;

public:

    void setIdContact(int newIdContact);
    void setIdUser(int newIdUser);
    void setName(string newName);
    void setSurname(string newSurname);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setAddress(string newAddress);


    int getIdContact();
    int getIdUser();
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
};

#endif
