#include <iostream>
#include <string>
#include <vector>
#include "admin.h"
#include "../db/repo.h"

using namespace std;

void adminMod(int adminId, RepoGroup& rg) {
    auto rpAdmin = rg.adminRepo;

    Admin *a = nullptr;
    for (Admin& ad : rpAdmin.getData()) {
        if (ad.getId() == adminId) {
            a = &ad;
            break;
        }
    }

    if (!a) {
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
        case 2:
            // cout << "List of all employees:" << endl;
            // for (const Faculty& faculty : rg.facultyRepo.getData()) {
            //     cout << "ID: " << faculty.getId() << ", Name: " << faculty.getName() << endl;
            // }
            allEmployees(rg.facultyRepo, rg.adminRepo);
            break;
        case 3:
            // cout << "Enter new student details:" << endl;
            // string name;
            // int id;
            // cin >> name >> id;
            // Student newStudent(name, id);
            // rg.studentRepo.add(newStudent);
            // cout << "New student added successfully!" << endl;
            // break;
        default:
            cout << "Invalid choice." << endl;
    }
}

void allEmployees(Repo<Faculty> frp, Repo<Admin> arp) {
    vector<Employee*> employees;

    for (Faculty& faculty : frp.getData()) {
        Employee* emp = &faculty;
        employees.push_back(emp);
    }

    for (Admin& admin : arp.getData()) {
        Employee* emp = &admin;
        employees.push_back(emp);
    }
}