/* 
 * File:   Person.h
 * Author: Kyle
 * Created on January 30, 2024, 10:39 AM
 * Description: A simple person class that hold the name and age of a person
 *              that is meant to be inherited by other classes. Overloads input
 *              and output operators for simpler code in main.
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    int age;
    
public:

    void setfirstName(string s){firstName = s;}
    string getfirstName(){return firstName;}
    
    void setlastName(string s){lastName = s;}
    string getlastName(){return lastName;}
    
    void setAge(int a){age = a;}
    int getAge(){return age;}
    
    //Displays what type of class each person is
    virtual void classInfo() = 0;
    //Shorter unformatted print that only shows info relevant to top most class
    virtual void quickPrint() = 0;
    
    friend ostream& operator<<(ostream& os, Person& per);
    friend istream& operator>>(istream& is, Person& per);
};

ostream& operator<<(ostream &os, Person& per){
    os << "Name: " << per.firstName  << " " << per.lastName <<"\nAge:  " << per.age << endl;
    per.classInfo();
    return os;
}

istream& operator>>(istream& is, Person& per){
    cout << "Enter the persons first name: ";
    is >> per.firstName;
    per.firstName[0] = toupper(per.firstName[0]);
    
    cout << "Enter the persons last name: ";
    is >> per.lastName;
    per.lastName[0] = toupper(per.lastName[0]);
    
    cout << "Enter the persons age: ";
    is >> per.age;
    
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Age must be a number, not a character");
    }
    //If a negative number is entered
    if (per.age < 0) throw string("Age cannot be negative");
    
    
    return is;
}

#endif /* PERSON_H */

