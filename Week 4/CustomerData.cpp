#include "CustomerData.h"
#include <iostream>
using namespace std;

/*
  CustomerData implementation
  By: Kyle Riebeling
  On: 1/25/2024
  Description: Implements the contstructor and setter and getters
  for CustomerData class
*/

int CustomerData::lastCustNum = 0;

//Automatically increments counter for customer number
//and sets new number to new customer
CustomerData::CustomerData() {
    lastCustNum++;
    customerNumber = lastCustNum;
}

long int CustomerData::getCustomerNumber() {
    return customerNumber;
}

void CustomerData::setMailingList() {
    int ans;
    cout << "Would this customer like to enroll in mailing list?" << endl;
    cout << "Enter 1 for yes or 0 for no: ";
    cin.clear();
    cin >> ans;

    // Input validation that check if input is either 1 or 0
    while (ans < 0 || ans > 1) {
        cout << "Try again. Enter 1 to enroll in the mailing list or 0 to opt-out: ";
        cin >> ans;
    }

    mailingList = ans;
}
bool CustomerData::getMailingList() {
    return mailingList;
}

