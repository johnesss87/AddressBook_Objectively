#include "Contact.h"

void Contact::setIdContact(int newIdContact) {
    if (newIdContact >= 0)
        idContact = newIdContact;
}

void Contact::setIdUser(int newIdUser) {
    if (newIdUser >= 0)
        idUser = newIdUser;
}

void Contact::setName(string newName) {
    name = newName;
}

void Contact::setSurname(string newSurname) {
    surname = newSurname;
}

void Contact::setPhoneNumber(string newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Contact::setEmail(string newEmail) {
    email = newEmail;
}

void Contact::setAddress(string newAddress) {
    address = newAddress;
}

int Contact::getIdContact() {
    return idContact;
}

int Contact::getIdUser() {
    return idUser;
}

string Contact::getName() {
    return name;
}

string Contact::getSurname() {
    return surname;
}

string Contact::getPhoneNumber() {
    return phoneNumber;
}

string Contact::getEmail() {
    return email;
}

string Contact::getAddress() {
    return address;
}
