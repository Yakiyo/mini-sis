#include "db/repo.h"
#include "model/employee.h"
#include "model/student.h"
#include <iostream>

using namespace std;

void adminMod(int adminId, RepoGroup& rg) {
    auto rpAdmin = rg.adminRepo;

    Admin* a = nullptr;
    for (Admin& ad : rpAdmin.getData()) {
        if (ad.getId() == adminId) {
            a = new Admin(ad);
            break;
        }
    }

    if (a == nullptr) {
        cout << "Admin with ID " << adminId << " not found." << endl;
        return;
    }

    cout << "Logged in as Admin: " << a->getName() << endl;

    cout << "Admin functionalities:" << endl;
    cout << "1. View all students" << endl;
    cout << "2. View all employees" << endl;
    cout << "3. Add new student" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "List of all students:" << endl;
            for (const Student& student : rg.studentRepo.getData()) {
                cout << "ID: " << student.getId() << ", Name: " << student.getName() << endl;
            }
            break;
        case 2: {
            vector<Employee*> employees;

            for (Faculty& faculty : rg.facultyRepo.getData()) {
                Employee* emp = &faculty;
                employees.push_back(emp);
            }

            for (Admin& admin : rg.adminRepo.getData()) {
                Employee* emp = &admin;
                employees.push_back(emp);
            }

            break;
        }
        case 3: {
            cout << "Enter new student details:" << endl;
            string name;
            int id, batch;
            string dept;

            cin.ignore();// consume the newline left by previous input
            cout << "Name: ";
            getline(cin, name); // consume the newline left by previous input
            cout << "ID: ";
            cin >> id;
            cout << "Department: ";
            cin >> dept;
            cout << "Batch: ";
            cin >> batch;

            Student newStudent(name, id, dept, batch);
            (rg.studentRepo).add(newStudent);
            cout << "New student added successfully!" << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }
}