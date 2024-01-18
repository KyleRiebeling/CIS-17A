/*
Simulate filling the car up with fuel, 
and then run a loop that increments the 
odometer until the car runs out of fuel. 
During each loop iteration, print the car’s 
current mileage and amount of fuel.
*/

#include "Odometer.cpp"
#include <iostream>
using namespace std;

int main(){
    Odometer myCar;

    //Simulates filing up the tank
    while (!myCar.addFuel()){
        //Fuel is added in the statement check
    }
    
    //Print stats, then drive one mile if possible
    do{
        myCar.printStats();
    }while(myCar.incMileage());

    return 0;

}