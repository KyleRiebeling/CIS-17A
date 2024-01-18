/*
This class will simulate the car’s odometer. Its responsibilities are:

– To know the car’s current mileage.

– To report the car’s current mileage.

– To be able to increment the current mileage by 1 mile.
The maximum mileage the odometer can store is 999,999 miles.
When this amount is exceeded, the odometer resets the current 
mileage to 0.

– To be able to work with a FuelGauge object. It should decrease 
the FuelGauge object’s current amount of fuel by 1 gallon for 
every 32 miles traveled. (The car’s fuel economy is 32 miles 
per gallon.)
*/

#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.cpp"
 
class Odometer {
private:
    int currMileage = 0;
    int milesSinceUpdate = 0;
    FuelGauge gauge;

public:
    int getMileage();

    bool incMileage();

    bool addFuel();
    
    void printStats();
};
#endif
