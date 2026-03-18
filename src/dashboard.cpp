#include<dashboard.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<error.h>
#include<serde.h>
#include<display.h>
using namespace std;

// void Dashboard ::setStudent(const Student& stud){
//    this->stud = stud; 
// }

void Dashboard ::display() const{
   cout << "==================================================================" << endl;
   cout << setw(40);
   cout << right << "STUDENT DASHBOARD" << endl;
   cout << "==================================================================" << endl << endl;
   cout << "Student ID";
   cout << setw(20);
   cout << stud.getName();
   cout << setw(13);
   cout << "Department";
   cout << setw(23);
   cout << stud.getDept();
   cout << endl << endl;
   cout << "Name";
   cout << setw(26);
   cout << stud.getName();
   cout << setw(19);
   cout << "Current Semester";
   cout << setw(17);
   cout << stud.getSemester();  
}