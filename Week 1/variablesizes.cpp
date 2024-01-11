#include <iostream>
using namespace std;

/*
  Variable Sizes
  By: Kyle Riebeling
  On: 1/4/2024
  Description: Prints out the sizes of different data types to the
  console.
*/

int main(){

    char a;
    unsigned short int b;
    int c;
    long d;
    float e;
    double f;
    float* arr = new float[5];

    cout << "Size of a char in bytes: " << sizeof(a) << endl;
    cout << "Size of an unsigned short int in bytes: " << sizeof(b) << endl;
    cout << "Size of an int in bytes: " << sizeof(c) << endl;
    cout << "Size of a long in bytes: " << sizeof(d) << endl;
    cout << "Size of a float in bytes: " << sizeof(e) << endl;
    cout << "Size of a double in bytes: " << sizeof(f) << endl;

    return 0;
}