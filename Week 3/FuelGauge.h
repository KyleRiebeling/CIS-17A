/*
This class will simulate a fuel gauge. Its responsibilities are:

– To know the car’s current amount of fuel, in gallons.

– To report the car’s current amount of fuel, in gallons.

– To be able to increment the amount of fuel by 1 gallon. 
This simulates putting fuel in the car. (The car can hold 
a maximum of 22 gallons.)

– To be able to decrement the amount of fuel by 1 gallon, 
if the amount of fuel is greater than 0 gallons. This simulates
burning fuel as the car runs.
*/
#ifndef FUELGAUGE_H
#define FUELGAUGE_H
 
class FuelGauge {
private:
    int currGallons = 0;

public:
    int getGallons();

    void incFuel();

    void decFuel();
};
#endif