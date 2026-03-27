#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "../error/error.h"
#include "../model/employee.h"
#include "../model/student.h"

using namespace std;

// A generic repository class for managing data of type T
// Any class T must implement the Serde interface
template <typename T>
class Repo {
   private:
    string filename;
    vector<T> data;

   public:
    Repo(const string& filename) : filename(filename), data(vector<T>()) {
        // load content from file when the repository is created
        load();
    }

    void save() {
        ofstream file(filename);

        if (!file.is_open()) {
            throw FileExcept(filename);
        }

        for (const T& item : data) {
            file << item.serialize() << endl;
        }
    }

    vector<T> load() {
        // clear the current data before loading new data
        this->data.clear();

        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Failed to open file: " << filename << endl;
            throw FileExcept(filename);
        }

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                T item = T::deserialize(line);
                this->data.push_back(item);
            }
        }

        return this->data;
    }

    void add(const T& item) {
        this->data.push_back(item);
    }

    vector<T> getData() const {
        return this->data;
    }

    ~Repo() {
        // save the current data to file when the repository is destroyed
        save();
    }
};

class RepoGroup {
   public:
    Repo<Admin> adminRepo;
    Repo<Faculty> facultyRepo;
    Repo<Student> studentRepo;

    RepoGroup(Repo<Admin>& adminRepo, Repo<Faculty>& facultyRepo, Repo<Student>& studentRepo)
        : adminRepo(adminRepo), facultyRepo(facultyRepo), studentRepo(studentRepo) {}
};
