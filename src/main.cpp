#include <iostream>

#include "db/repo.h"
#include "error/error.h"
#include "model/employee.h"
#include "model/student.h"

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
            int id;
            string dept;
            int batch;
            cin >> name >> id >> dept >> batch;
            Student newStudent(name, id, dept, batch);
            (rg.studentRepo).add(newStudent);
            cout << "New student added successfully!" << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }
}

int main() {
    cout << "Welcome to the University Management System!" << endl;

    try {
        cout << "Loading data..." << endl;
        Repo<Admin> adminRepo("admin.txt");
        Repo<Faculty> facultyRepo("faculty.txt");
        Repo<Student> studentRepo("student.txt");

        cout << adminRepo.getData()[0].getName();

        RepoGroup rg(adminRepo, facultyRepo, studentRepo);

        cout << "Data loaded successfully!" << endl;
        cout << "Login to system: " << endl;
        cout << "1. Admin" << endl;
        cout << "2. Faculty" << endl;
        cout << "3. Student" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Provide ID: " << endl;
                int id;
                cin >> id;
                adminMod(id, rg);
                break;
            case 2:
                cout << "Faculty login selected." << endl;
                // Implement faculty login and functionalities here
                break;
            case 3:
                cout << "Student login selected." << endl;
                // Implement student login and functionalities here
                break;
            default:
                cout << "Invalid choice. Exiting..." << endl;
                return 0;
        }
    } catch (const FileExcept& e) {
        cerr << "File error: " << e.what() << endl;
    } catch (const DsrlzExcept& e) {
        cerr << "Error deserializing data: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}