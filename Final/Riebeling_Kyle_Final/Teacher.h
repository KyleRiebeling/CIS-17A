/* 
 * File:   Teacher.h
 * Author: Kyle
 * Created on January 31, 2024, 1:34 PM
 * Description: 
 */

#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"
#include "Experience.h"
using namespace std;

//Templated to allow for either phone num or email for contact info
template <class T>
class Teacher: public Person{
private:
    string subject = "-1";
    T contact;
    int classNum;
    Experience exp;

public:
    
    void setSubject(string s){subject = s;}
    string getSubject(){return subject;}
    
    void setContact(T c) {contact = c;}
    T getContact(){return contact;}
    
    void setClassNum(int n){classNum = n;}
    int getClassNum(){return classNum;}
    
    void setExp(Experience e){exp = e;}
    Experience getExp(){return exp;}
    
    virtual void classInfo(){
        cout << this->getfirstName() << " " << this->getlastName() 
            << " is a person and a teacher" << endl;
    }
    virtual void quickPrint(){
        if (subject != "-1"){
            classInfo();
            cout << subject << " " << contact << " " << classNum << " ";
            cout << exp.getLevel() << " " << exp.getFocus() << " " <<
                    exp.getTotalYears()  << " " << exp.getCurrYears() << endl;
        }
        else {cout << "No teacher saved" << endl;}
    }
  
    
    friend ostream& operator<<(ostream& os, Teacher& tea){
        tea.classInfo();
        os << "Name: " << tea.getfirstName()  << " " << tea.getlastName() << endl;
        os << "Age:  " << tea.getAge() << endl;
        
        os << setw(25) << left << "Subject taught: " << tea.subject << endl;
        os << setw(25) << left << "Contact information: " << tea.contact << endl;
        os << setw(25) << left << "Classroom number: " << tea.classNum << endl;
        os << tea.exp;
        
        return os;
    }
       
    friend istream& operator>>(istream& is, Teacher& tea){
        //Variables to use for function calls to parent class setters and 
        //input validation for template types
        string s;
        int n;

        bool inputValid = false;
    
        cout << "Enter the teachers first name: ";
        cin >> s;
        s[0] = toupper(s[0]);
        tea.setfirstName(s);

        cout << "Enter the teachers last name: ";
        cin >> s;
        s[0] = toupper(s[0]);
        tea.setlastName(s);
    
        cout << "Enter the teachers age: ";
        cin >> n;
        tea.setAge(n);
    
        //If a char is entered
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw string("Age must be a number, not a character");
        }
        //If a negative number is entered
        if (n < 0) throw string("Age cannot be negative");
    
        cout << "Enter the teachers main teaching subject: ";
        is >> tea.subject;
    
        cout << "Enter the teachers contact information: ";
        is >> tea.contact;
        
        //Exceptions for phone numbers
        if (typeid(T) == typeid(long long)){
            //If a char is entered
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw string("Phone number must be a number, not a character");
            }
        }
    
        cout << "Enter the teachers classroom number: ";
        is >> tea.classNum;
        
        //If a char is entered
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw string("Class number must be a number, not a character");
            }
            //If a negative number is entered
            if (tea.classNum < 0){ 
                throw string("Class number cannon be negative");}
    
    
        //Loop to handle inputting the experience data
        while (!inputValid) {
            //Try inputting experience data
                try {
                    cin >> tea.exp;
                    inputValid = true;
                } catch (string e) {
                    cout << e << ". Try Again." << endl;
                }
        }
        return is;
    }
};


#endif /* TEACHER_H */

