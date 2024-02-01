/* 
 * File:   SchoolPersonTester.cpp
 * Author: Kyle
 * Created on January 30, 2024, 10:38 AM
 * Description: 
 */

#include "Athlete.h"
#include "Teacher.h"
using namespace std;

int main() {
    //Empty objects to fill
    Student s;
    Teacher<long long> t2;
    Teacher<string> t1;
    Athlete a;
      
    //Loop variables
    int menuChoice = 0;
    bool inputValid = false;

    cout << "Welcome to the school directory editor!" << endl;
    
    //Menu loop
    while (menuChoice != 6) {

        cout << endl;
        cout << "Please choose what data you would like to input." << endl << endl;
        cout << "1. Student" << endl;
        cout << "2. Teacher with email contact" << endl;
        cout << "3. Teacher with phone contact" << endl;
        cout << "4. Student Athlete" << endl;
        cout << "5. Quick summary of all people currently saved in objects" << endl;
        cout << "6. Exit" << endl;
        cin >> menuChoice;

        if (cin.fail() || menuChoice > 6 || menuChoice < 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menuChoice = 7;
            cout << "Please choose an option from the menu." << endl << endl;
        }
        
        cout << endl;
        
        //Switch to start input for menu choice
        switch (menuChoice) {
            case 1:
                while (!inputValid) {
                    //Try inputting student data
                    try {
                        cin >> s;
                        inputValid = true;
                    } catch (string e) {
                        cout << e << ". Try Again." << endl;
                    }
                }
                cout << endl << "Student just entered" << endl;
                cout << "--------------------" << endl;
                cout << s << endl;
                break;

            case 2:
                while (!inputValid) {
                    //Try inputting teacher data with email
                    try {
                        cin >> t1;
                        inputValid = true;
                    } catch (string e) {
                        cout << e << ". Try Again." << endl;
                    }
                }
                cout << endl << "Teacher just entered" << endl;
                cout << "--------------------" << endl;
                cout << t1 << endl;
                break;

            case 3:
                while (!inputValid) {
                    //Try inputting teacher data with phone number
                    try {
                        cin >> t2;
                        inputValid = true;
                    } catch (string e) {
                        cout << e << ". Try Again." << endl;
                    }
                }
                cout << endl << "Teacher just entered" << endl;
                cout << "--------------------" << endl;
                cout << t2 << endl;
                break;
                
            case 4:
                while (!inputValid) {
                    //Try inputting student athlete data
                    try {
                        cin >> a;
                        inputValid = true;
                    } catch (string e) {
                        cout << e << ". Try Again." << endl;
                    }
                }
                cout << endl << "Athlete just entered" << endl;
                cout << "--------------------" << endl;
                cout << a << endl;
                break;
                
            case 5:
                s.quickPrint();
                t1.quickPrint();
                t2.quickPrint();
                a.quickPrint();
                cout << endl;
                break;

        };

        inputValid = false;
    }



    return 0;
}

