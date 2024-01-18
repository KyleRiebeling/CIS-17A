#include "Odometer.h"
#include <iostream>
using namespace std;

int Odometer::getMileage(){
    return currMileage;
}

//Drives one mile if there is fuel, if there is no fuel returns false
bool Odometer::incMileage(){
    //If there is gas, drive one mile
    if (gauge.getGallons() > 0){
        currMileage++;
        milesSinceUpdate++;
    }
    //If no gas retun false
    else return false;

    //If you have driven 32 miles, take away one gallon and reset counter
    if (milesSinceUpdate > 31){
        gauge.decFuel();
        milesSinceUpdate = 0;
    }
    //If odometer passes limit, reset to 0
    if (currMileage >= 1000000){
        currMileage = 0;
    }
    return true;
}

//Helper function to add fuel to the tank, retuns true once the tank is full
bool Odometer::addFuel(){
    gauge.incFuel();
    return (gauge.getGallons() >= 22) ? true : false;
}

//Helper to print gallons and mileage
void Odometer::printStats(){
    cout << "Mileage: " << currMileage << " Gallons left: " << gauge.getGallons() << endl;
}