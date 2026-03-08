#include "db.h"

#include <fstream>
#include <sstream>

template <typename T>
DBRepo<T>::DBRepo(const string& filename) {
    this->filename = filename;
    this->data = {};
}

template <typename T>
vector<T> DBRepo<T>::load() {
    this->data.clear();

    ifstream file(this->filename);
    if (!file.is_open()) {
        // TODO: file error
        throw runtime_error("Could not open file: " + this->filename);
    }
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            T item = T::deserialize(line);
            this->data.push_back(item);
        }
    }
}

template <typename T>
void DBRepo<T>::save() {
    ofstream file(this->filename);
    if (!file.is_open()) {
        // TODO: file error
        throw runtime_error("Could not open file: " + this->filename);
    }
    for (const T& item : this->data) {
        file << item.serialize() << endl;
    }
}

template <typename T>
vector<T> DBRepo<T>::getData() const {
    return this->data;
}

template <typename T>
void DBRepo<T>::addData(const T& item) {
    this->data.push_back(item);
}