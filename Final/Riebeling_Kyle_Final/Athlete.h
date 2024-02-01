/* 
 * File:   Athlete.h
 * Author: Kyle
 * Created on January 31, 2024, 3:21 PM
 * Description: 
 */

#ifndef ATHLETE_H
#define ATHLETE_H

#include "Student.h"
using namespace std;

class Athlete: public Student{
private:
    int jerseyNum = -1;
    string sport;
    string position;
    bool scholarship;
    
public:
    
    void setJerseyNum(int n){jerseyNum = n;}
    int getJerseyNum(){return jerseyNum;}
    
    void setSport(string s){sport = s;}
    string getSport(){return sport;}
    
    void setPosition(string p){position = p;}
    string getPosition(){return position;}
    
    void setScholarship(bool ans){scholarship = ans;}
    bool getScholarship(){return scholarship;}
    
    virtual void classInfo(){
        cout << this->getfirstName() << " " << this->getlastName() 
            << " is a person, student, and athlete." << endl;
    }
    
    virtual void quickPrint(){
        if (jerseyNum != -1){
            classInfo();
            cout << sport << " " << position << " " << jerseyNum << " ";

            if (scholarship)cout << " is on a scholarship.";
            else cout << " is not on a scholarship."; 
            cout << endl;
        }
        else {cout << "No athlete saved." << endl;}
    }
    
    friend ostream& operator<<(ostream& os, Athlete& ath);
    friend istream& operator>>(istream& is, Athlete& ath);
};

ostream& operator<<(ostream& os, Athlete& ath){
    ath.classInfo();
    os << setw(17) << left << "Name: " << ath.getfirstName()  << " " << ath.getlastName() << endl;
    os << setw(17) << left << "Age:  " << ath.getAge() << endl;
    os << setw(17) << left << "Current Year: " << ath.getcurrYear() << endl;
    os << setw(17) << left << "Graduation Year: " << ath.getGradYear() << endl;
    os << setw(17) << left << "GPA: " << ath.getGPA() << endl;
    os << setw(17) << left << "Classes: ";
    
    string* s = ath.getClasses();
    os << s[0];
    
    int i = 1;
    while (s[i] != "done"){
        cout << ", " << s[i];
        i++;
    }
    cout << endl;

    os << setw(17) << left << "Sport played: " << ath.sport << endl;
    os << setw(17) << left << "Position played: " << ath.position << endl;
    os << setw(17) << left << "Jersey number: " << ath.jerseyNum << endl;
    os << setw(17) << left << "On scholarship: ";
    if (ath.scholarship)cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return os;
}

istream& operator>>(istream& is, Athlete& ath){

    //Variables to use for function calls to parent class setters
    string s;
    int n;
    float g;
    
    cout << "Enter the athletes first name: ";
    cin >> s;
    s[0] = toupper(s[0]);
    ath.setfirstName(s);
    
    
    cout << "Enter the athletes last name: ";
    cin >> s;
    s[0] = toupper(s[0]);
    ath.setlastName(s);
    
    
    cout << "Enter the athletes age: ";
    cin >> n;
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Age must be a number, not a character");
    }
    //If a negative number is entered
    if (n < 0) throw string("Age cannot be negative");
    ath.setAge(n); 
    
    
    cout << "Enter the athletes GPA: ";
    is >> g;
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("GPA must be a number, not a character");
    }
    //If a negative number is entered
    if (g < 0) throw string("GPA cannot be negative");
    //If a large number is entered
    if (g > 5.0) throw string("GPA cannot be greater than 5.0");
    ath.setGPA(g);
    
    
    cout << "Enter the athletes expected graduation year: ";
    is >> n;
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Grad year must be a number, not a character");
    }
    //If a negative number is entered
    if (n < 0) throw string("Grad year cannot be negative");
    ath.setGradYear(n);
    
    
    cout << "Enter the athletes current year: " << endl;
    cout << "1. Freshman\n";
    cout << "2. Sophomore\n";
    cout << "3. Junior\n";
    cout << "4. Senior\n";        
    is >> n;
    
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Current year input failed.");
    }
    //If a negative number is entered
    if (n < 0) throw string("Current year cannot be negative");
    //If a large number is entered
    if (n > 4) throw string("Current year cannot be greater than 4");
    ath.setcurrYear(n);
    
    
    cout << "How many classes is the athlete taking? ";
    is >> n;
    //If a negative number is entered
    if (n < 0) throw string("Number of classes cannot be negative");
    string* cl = new string[n+1];
    for (int i = 0; i < n; i++){
        cout << "Enter class " << i+1 << " name: ";
        is >> cl[i];
    }
    cl[n] = "done";
    ath.setClasses(cl);
    
    //NEW STUFF
    cout << "What sport does the athlete play? ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is, ath.sport);
    
    cout << "What position does the athlete play? ";
    getline(is, ath.position);
    
    cout << "Enter the athletes jersey number: ";
    is >> ath.jerseyNum;
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Jersey number must be a number, not a character");
    }
    //If a negative number is entered
    if (ath.jerseyNum < 0) throw string("Jersey number cannot be negative");
    
    cout << "Is the athlete on a scholarship? (1 for yes or 0 for no) ";
    is >> ath.scholarship;
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Please enter only 1 or 0 for scholarship status");
    }
    
    return is;
}


#endif /* ATHLETE_H */

