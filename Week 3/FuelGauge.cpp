#include "FuelGauge.h"
#include <iostream>
using namespace std;

int FuelGauge::getGallons(){
    return currGallons;
}

void FuelGauge::incFuel(){
    //If tank isnt full add gas, else say its full
    if (currGallons < 22)currGallons++;
    else cout << "Tank full!";
}

void FuelGauge::decFuel(){
    //If tank isnt empty, take away gas, else say tank is empty
    if (currGallons > 0) currGallons--;
    else cout << "Tank is empty!";
}

