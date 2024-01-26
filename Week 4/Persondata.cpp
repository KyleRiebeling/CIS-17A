#include "Persondata.h"
#include <iostream>
using namespace std;

/*
  PersonData Class Implementation
  By: Kyle Riebeling
  On: 1/25/2024
  Description: Simple implemetation of the setters and getters
  from the PersonData class. Some have validation loops in the
  setters.
*/

void PersonData::setFirstName() {
    string n;
    cout << "Enter first name: ";
    getline(cin, n);

    firstName = n;
}
string PersonData::getFirstName() {
    return firstName;
}

void PersonData::setLastName() {
    string n;
    cout << "Enter last name: ";
    getline(cin, n);

    lastName = n;
}
string PersonData::getLastName() {
    return lastName;
}

void PersonData::setAddress() {
    string add;
    cout << "Enter address (numbers and full street name): ";
    cin.clear();
    getline(cin, add);

    //Validation loop that makes sure the first char is a number
    while (!isdigit(add[0])) {
        cout << "Please enter address starting with the numbers" <<
            ", followed by the street name. Try again: ";
        getline(cin, add);
    }

    address = add;
}
string PersonData::getAddress() {
    return address;
}

void PersonData::setCity() {
    string c;
    cout << "Enter city name: ";
    cin >> c;
    cin.clear();

    city = c;
}
string PersonData::getCity() {
    return city;
}

void PersonData::setState() {
    string s;
    cout << "Enter state abbreviation: ";
    cin >> s;
    cin.clear();

    //Iput validation that makes sure it is only 2 chars and both are alphabetic
    while (s.size() != 2 || !isalpha(s[0]) || !isalpha(s[1])) {
        cout << "Only enter the abbreviation of your state. Try again: ";
        cin >> s;
    }

    //Make sure it is capitalized
    s[0] = toupper(s[0]);
    s[1] = toupper(s[1]);

    state = s;
}
string PersonData::getState() {
    return state;
}

void PersonData::setZipCode() {
    string z;
    cout << "Enter the first 5 digits of the zip code: ";
    cin >> z;
    cin.clear();

    // Validation loop that makes sure the input is only 5 characters
    // and all the characters are numbers
    while (z.size() != 5 || !isdigit(z[0]) || !isdigit(z[1]) || !isdigit(z[2])
        || !isdigit(z[3]) || !isdigit(z[4])) {

        cout << "Only enter the first 5 digits of your zip code. Try again: ";
        cin >> z;
    }

    zipCode = z;
}
string PersonData::getZipCode() {
    return zipCode;
}

void PersonData::setPhoneNum() {
    long long n;
    cout << "Enter phone number with area code and no spaces (10 digits): ";
    cin >> n;
    cin.clear();

    //Input validation for number longer or shorter than 10 digits
    while (n >= 10000000000 || n <= 999999999) {
        cout << "Please enter only the 10 digit phone number. Try again: ";
        cin >> n;
    }

    phoneNum = n;

}
long long PersonData::getPhoneNum() {
    return phoneNum;
}




