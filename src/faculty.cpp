#include <iostream>

#include "db/repo.h"
#include "model/employee.h"
#include "model/student.h"

using namespace std;

void facultyMod(int fId, RepoGroup& rg) {
    auto rpFaculty = rg.facultyRepo;

    Faculty* f = nullptr;
    for (Faculty& faculty : rpFaculty.getData()) {
        if (faculty.getId() == fId) {
            f = new Faculty(faculty);
            break;
        }
    }

    if (f == nullptr) {
        cout << "Faculty with ID " << fId << " not found." << endl;
        return;
    }

    cout << "Logged in as Faculty: " << f->getName() << endl;

    cout << "Faculty functionalities:" << endl;
    cout << "1. View all students" << endl;
    cout << "2. Add/Update grade for a student" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "List of all students:" << endl;
            for (const Student& student : rg.studentRepo.getData()) {
                cout << "ID: " << student.getId() << ", Name: " << student.getName() << endl;
            }
            break;
        }
        case 2: {
            cout << "Enter student ID: " << endl;
            int sId;
            cin >> sId;
            cout << "Enter course code: " << endl;
            string courseCode;
            cin >> courseCode;
            cout << "Enter grade: " << endl;
            string grade;
            cin >> grade;

            // see if grade exists
            bool gradeExists = false;
            for (Grade& g : rg.gradeRepo.getData()) {
                if (g.getStudentId() == sId && g.getCourseCode() == courseCode) {
                    g = Grade(courseCode, grade, sId);
                    gradeExists = true;
                    break;
                }
            }

            if (!gradeExists) {
                cout << "Adding new grade for student ID " << sId << " and course " << courseCode << endl;
                rg.gradeRepo.add(Grade(courseCode, grade, sId));
            } else {
                cout << "Grade updated successfully!" << endl;
            }

            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}