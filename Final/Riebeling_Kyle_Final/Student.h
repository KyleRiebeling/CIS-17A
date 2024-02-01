/* 
 * File:   Student.h
 * Author: Kyle
 * Created on January 30, 2024, 11:41 AM
 * Description: A class that inherits person class that adds specifics for students
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
using namespace std;


class Student : public Person {
private:
    string* classes;
    int gradYear = -1;
    float gpa;
    int currYear;

public:

    void setClasses(string* s){classes = s;}
    string* getClasses(){return classes;}
    
    void setGradYear(int y){gradYear = y;}
    int getGradYear(){return gradYear;}
    
    void setGPA(float g){gpa = g;}
    float getGPA(){return gpa;}
    
    void setcurrYear(int t){currYear = t;}
    int getcurrYear(){return currYear;}
    
    virtual void classInfo(){
        cout << this->getfirstName() << " " << this->getlastName() 
            << " is a person and a student" << endl;
    }
    virtual void quickPrint(){
        if (gradYear != -1){
            classInfo();
            cout << currYear << " " << gradYear << " " << gpa << " [";
            cout << classes[0];
            int i = 1;
            while (classes[i] != "done"){
                cout << ", " << classes[i];
                i++;
            }   
            cout << "]" << endl;
        }
        else {cout << "No student saved." << endl;}
    }
    
    friend ostream& operator<<(ostream& os, Student& stu);
    friend istream& operator>>(istream& is, Student& stu);
};

ostream& operator<<(ostream &os, Student& stu){
    stu.classInfo();
    os << "Name: " << stu.getfirstName()  << " " << stu.getlastName() << endl;
    os << "Age:  " << stu.getAge() << endl;
    
    os << setw(17) << left << "Current Year: " << stu.currYear << endl;
    os << setw(17) << left << "Graduation Year: " << stu.gradYear << endl;
    os << setw(17) << left << "GPA: " << stu.gpa << endl;
    os << setw(17) << left << "Classes: ";
    int i = 1;
    os << stu.classes[0];
        while (stu.classes[i] != "done"){
            os << ", " << stu.classes[i];
            i++;
        }
    
    return os;
}

istream& operator>>(istream& is, Student& stu){
    //Variables to use for function calls to parent class setters
    string s;
    int n;
    
    cout << "Enter the students first name: ";
    cin >> s;
    s[0] = toupper(s[0]);
    stu.setfirstName(s);
    
    
    cout << "Enter the students last name: ";
    cin >> s;
    s[0] = toupper(s[0]);
    stu.setlastName(s);
    
    cout << "Enter the students age: ";
    cin >> n;
    stu.setAge(n);
    
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Age must be a number, not a character");
    }
    //If a negative number is entered
    if (n < 0) throw string("Age cannot be negative");
    
    
    cout << "Enter the students GPA: ";
    is >> stu.gpa;
    
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("GPA must be a number, not a character");
    }
    //If a negative number is entered
    if (stu.gpa < 0) throw string("GPA cannot be negative");
    //If a large number is entered
    if (stu.gpa > 5.0) throw string("GPA cannot be greater than 5.0");
    
    cout << "Enter the students expected graduation year: ";
    is >> stu.gradYear;
    
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Grad year must be a number, not a character");
    }
    //If a negative number is entered
    if (stu.gradYear < 0) throw string("Grad year cannot be negative");
    
    
    cout << "Enter the students current year: " << endl;
    cout << "1. Freshman\n";
    cout << "2. Sophomore\n";
    cout << "3. Junior\n";
    cout << "4. Senior\n";        
    is >> stu.currYear;
    
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Current year input failed.");
    }
    //If a negative number is entered
    if (stu.currYear < 0) throw string("Current year cannot be negative");
    //If a large number is entered
    if (stu.currYear > 4) throw string("Current year cannot be greater than 4");
    
    cout << "How many classes is the student taking? ";
    is >> n;
    
    //If a negative number is entered
    if (n < 0) throw string("Number of classes cannot be negative");
    
    stu.classes = new string[n+1];
    
    for (int i = 0; i < n; i++){
        cout << "Enter class " << i+1 << " name: ";
        is >> stu.classes[i];
    }
    stu.classes[n] = "done";
    
    return is;
}

#endif /* STUDENT_H */

