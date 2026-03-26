#include<iostream>
#include "db/repo.h"
#include "model/employee.h"
#include "model/student.h"
#include "error/error.h"

using namespace std;

int main() {
    cout << "Welcome to the University Management System!" << endl;
    
    try {
        cout << "Loading data..." << endl;
        Repo<Admin> adminRepo("admins.txt");
        // Repo<Faculty> facultyRepo("faculty.txt");
        // Repo<Student> studentRepo("students.txt");

        cout << "Data loaded successfully!" << endl;
    } catch (const FileExcept& e) {
        cerr << "File error: " << e.what() << endl;
    } catch (const DsrlzExcept& e) {
        cerr << "Error deserializing data: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}