#include "model/student.h"

#include <string>
#include <vector>

#include "db/repo.h"
#include "model/employee.h"
#include "model/grade.h"
#include "model/wallet.h"

using namespace std;

void studentMod(int sId, RepoGroup& rg) {
    auto rpStudent = rg.studentRepo;

    Student* s = nullptr;
    for (Student& student : rpStudent.getData()) {
        if (student.getId() == sId) {
            s = new Student(student);
            break;
        }
    }

    if (s == nullptr) {
        cout << "Student with ID " << sId << " not found." << endl;
        return;
    }

    cout << "Logged in as Student: " << s->getName() << endl;

    cout << "Student functionalities:" << endl;
    cout << "1. View grades" << endl;
    cout << "2. View wallet balance" << endl;
    cout << "3. Add money to wallet" << endl;
    cout << "4. Withdraw from wallet" << endl;

    Wallet* wallet = nullptr;
    for (Wallet& w : rg.walletRepo.getData()) {
        if (w.getStudentId() == sId) {
            wallet = &w;
            break;
        }
    }

    int choice;
    cin >> choice;

    if (wallet == nullptr) {
        cout << "Initializing wallet for student ID " << sId << " with balance 0.0 tk" << endl;
        rg.walletRepo.add(Wallet(sId, 0.0));
        wallet = &rg.walletRepo.getData().back();  // get the reference to the newly added wallet
    }

    switch (choice) {
        case 1: {
            cout << "Grades for student ID " << sId << ":" << endl;
            for (const Grade& grade : rg.gradeRepo.getData()) {
                if (grade.getStudentId() == sId) {
                    cout << "Course: " << grade.getCourseCode() << ", Grade: " << grade.getGrade() << endl;
                }
            }
            break;
        }
        case 2: {
            cout << "Wallet balance for student ID " << sId << ": $" << wallet->getBalance() << endl;
            break;
        }
        case 3: {
            cout << "Enter amount to add to wallet: ";
            double amount;
            cin >> amount;
            wallet->addMoney(amount);
            cout << "Amount added successfully." << endl;
            break;
        }
        case 4: {
            cout << "Enter amount to withdraw from wallet: ";
            double amount;
            cin >> amount;
            wallet->withdrawMoney(amount);
            cout << "Amount withdrawn successfully." << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}