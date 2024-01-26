#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "Persondata.h"
using namespace std;

/*
  CustomerData Class
  By: Kyle Riebeling
  On: 1/25/2024
  Description: A class the inherits from PersonData class. It adds
  specific varibales relevant to just customers. It includes a constructor
  and setters and getters for the new variables.
*/

class CustomerData : public PersonData{
private:
    static int lastCustNum;
    long int customerNumber;
    bool mailingList;

public:
    CustomerData();

    long int getCustomerNumber(); //Setter not needed as number is given in constructor

    void setMailingList();
    bool getMailingList();

};


#endif