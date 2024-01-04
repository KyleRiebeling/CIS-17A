#include <iostream>
using namespace std;

/*
  Cooking Ingredients Calculator
  By: Kyle Riebeling
  On: 1/4/2024
  Description: Calculates how much of each ingredient is needed
  for the amount of cookies the user wants to make. Baseline 
  recipe is based on 48 cookies.
  */

int main(){

    float sugarPerCookie = 1.5 / 48;
    float butterPerCookie = 1.0 / 48;
    float flourPerCookie = 2.75 / 48;
    int cookiesToMake;

    cout << "How many cookies do you plan on making? " << endl;
    cin >> cookiesToMake;

    cout << "You will need " << sugarPerCookie * cookiesToMake <<
        " cups of sugar." << endl;

    cout << "You will need " << butterPerCookie * cookiesToMake <<
        " cups of butter." << endl;

    cout << "You will need " << flourPerCookie * cookiesToMake <<
        " cups of flour." << endl;

    return 0;
}