#include "CustomerData.h"
#include <iostream>
using namespace std;

/*
  CustomerData tester
  By: Kyle Riebeling
  On: 1/25/2024
  Description: Tester file to see if CustomerData class works as intended
*/

int main(){

    CustomerData cust;

    //Fill Customer data
    cust.setFirstName();
    cust.setLastName();
    cust.setAddress();
    cust.setCity();
    cust.setState();
    cust.setZipCode();
    cust.setPhoneNum();
    cust.setMailingList();

    //Print customer data
    cout << "New Customer Data" << endl;
    cout << "_________________" << endl;
    cout << "Name: " << cust.getFirstName() << " " << cust.getLastName() << endl;

    cout << "Full Address: " << cust.getAddress() << ", " << cust.getCity() <<
            " " << cust.getState() << " " << cust.getZipCode() << endl;

    cout << "Phone Number: " << cust.getPhoneNum() << endl;

    string s = (cust.getMailingList()) ? "Yes" : "No";
    cout << "Mailing list: " << s << endl;

}
