#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>
using namespace std;

/*
  PersonData Class
  By: Kyle Riebeling
  On: 1/25/2024
  Description: Simple class that hold relevent data for each person
  and has public getters and setter for all variables
*/

class PersonData {
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zipCode; //Zipcode is a string to account for zip codes starting with 0
    long long phoneNum;

public:

    void setFirstName();
    string getFirstName();

    void setLastName();
    string getLastName();

    void setAddress();
    string getAddress();

    void setCity();
    string getCity();

    void setState();
    string getState();

    void setZipCode();
    string getZipCode();

    void setPhoneNum();
    long long getPhoneNum();

};


#endif