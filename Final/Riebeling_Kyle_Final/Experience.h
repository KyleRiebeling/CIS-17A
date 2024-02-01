/* 
 * File:   Experience.h
 * Author: Kyle
 * Created on January 31, 2024, 1:46 PM
 * Description: 
 */

#ifndef EXPERIENCE_H
#define EXPERIENCE_H

using namespace std;



class Experience{
private:
    string degreeFocus;
    string degreeLevel;
    int totalYears;
    int currSchool;
    
public:
    
    void setFocus(string f){degreeFocus = f;}
    string getFocus(){return degreeFocus;}
    
    void setLevel(string t){degreeLevel = t;}
    string getLevel(){return degreeLevel;}
    
    void setTotalYears(int y){totalYears = y;}
    int getTotalYears(){return totalYears;}
    
    void setCurrYears(int y){currSchool = y;}
    int getCurrYears(){return currSchool;}
    
    friend ostream& operator<<(ostream& os, Experience& exp);
    friend istream& operator>>(istream& is, Experience& exp);
};

ostream& operator<<(ostream& os, Experience& exp){
    os << setw(25) << left << "Degree: " << exp.degreeLevel << " in " << exp.degreeFocus << endl;
    os << setw(25) << left << "Total years teaching: " << exp.totalYears << endl;
    os << setw(25) << left << "Years at current school: " << exp.currSchool << endl;
    return os;
}

istream& operator>>(istream& is, Experience& exp){
    cout << "Enter the teachers degree level: ";
    is >> exp.degreeLevel;
        
    cout << "Enter the teachers degree focus: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is,exp.degreeFocus);
        
    cout << "Enter total years they have been teaching: ";
    is >> exp.totalYears;
        
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Total experience must be a number, not a character");
    }
    //If a negative number is entered
    if (exp.totalYears < 0) throw string("Total experience cannot be negative");
        
    cout << "Enter the amount of years at this school: ";
    is >> exp.currSchool;
        
    //If a char is entered
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw string("Years at current school must be a number, not a character");
    }
    //If a negative number is entered
    if (exp.currSchool < 0) throw string("Years at current school cannot be negative");
    
    return is;    
}

#endif /* EXPERIENCE_H */

