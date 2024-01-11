#include <iostream>
#include <iomanip>
using namespace std;

/*
  Array Element Shifter
  By: Kyle Riebeling
  On: 1/11/2024
  Description: This program uses a function to shift an arrays
  elements over one to the left and set the new first element
  to 0.0. The function recieves an array and returns the new
  bigger array, rather than modifying the original array. Main
  contains sample input to prove the function works.
*/

float* ArrayElementShifter(float* arr, int size){
    //Declare and Initialize first element to 0.0
    float* newArr = new float[size + 1];
    newArr[0] = 0.0;

    //Copy the old array to the rest of the new array
    for (int i = 1; i <= size; i++){
        newArr[i] = arr[i-1];
    }

    return newArr;
}

int main(){
    const int START_SIZE = 5;
    float* arr = new float[START_SIZE];

    //Fill and print original array
    cout << "Original Array: ";
    for (int i = 0; i < START_SIZE; i++){
        arr[i] = 1 + i;
        cout << fixed << setprecision(1) << arr[i] << " ";
    }
    cout << endl;

    arr = ArrayElementShifter(arr, START_SIZE);

    //Print after calling shifter
    cout << "After Shifting: ";
    for (int i = 0; i < START_SIZE + 1; i++){
        cout << fixed << setprecision(1) << arr[i] << " ";
    }
    cout << endl;


    return 0;
}