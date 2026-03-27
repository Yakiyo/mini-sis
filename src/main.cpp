#include <iostream>

#include "admin.h"
#include "faculty.h"
#include "student.h"
#include "faculty.h"
#include "db/repo.h"
#include "error/error.h"
#include "model/employee.h"
#include "model/student.h"

using namespace std;

int main() {
    cout << "Welcome to the University Management System!" << endl;

    try {
        cout << "Loading data..." << endl;

        RepoGroup rg("admin.txt", "faculty.txt", "student.txt", "grade.txt", "wallet.txt");

        cout << "Data loaded successfully!" << endl;
        cout << "Login to system: " << endl;
        cout << "1. Admin" << endl;
        cout << "2. Faculty" << endl;
        cout << "3. Student" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Provide ID: " << endl;
                int id;
                cin >> id;
                adminMod(id, rg);
                break;
            }
            case 2: {
                cout << "Faculty login selected." << endl;
                // Implement faculty login and functionalities here
                cout << "Provide ID: " << endl;
                int id;
                cin >> id;
                facultyMod(id, rg);
                break;
            }
            case 3: {
                cout << "Student login selected." << endl;
                // Implement student login and functionalities here
                cout << "Provide ID: " << endl;
                int id;
                cin >> id;
                studentMod(id, rg);
                break;
            }
            default:
                cout << "Invalid choice. Exiting..." << endl;
                return 0;
        }
    } catch (const FileExcept& e) {
        cerr << "File error: " << e.what() << endl;
    } catch (const DsrlzExcept& e) {
        cerr << "Error deserializing data: " << e.what() << endl;
    } catch (const TransactionExcept& e) {
        cerr << "Transaction error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}