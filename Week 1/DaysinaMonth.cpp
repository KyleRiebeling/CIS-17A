#include <iostream>
using namespace std;

/*
  Days in a Month Calculator
  By: Kyle Riebeling
  On: 1/4/2024
  Description: Takes in user input for a month and a year and 
  calculates how many days are in that month, taking into 
  account leap years.
*/

int main(){

    int month;
    int year;
    //Array with ammount of days in each month in a normal year
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};


    cout << "Enter the month in number form (1-12): ";
    cin >> month;

    cout << "Enter the year: ";
    cin >> year;

    //Only check for leap year if Feb is chosen
    if (month == 2){
        //Leap year case 1
        if (year % 100 == 0 && year % 400 == 0){
            //Update february for leap year
            days[1] = 29;
        }
        //Leap year case 2
        else if(year % 100 != 0 && year % 4 == 0){
            //Update february for leap year
            days[1] = 29;
        }
    }
    
    cout << days[month - 1] << " days." << endl;

    return 0;
}