#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

class AddressBook

{
    int idLoggedUser;
    int idLastContact;
    int idRemovedContact;

    vector <User> users;

public:
    void userRegistration();
};
