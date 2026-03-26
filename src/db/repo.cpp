#include "repo.h"

#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
Repo<T>::Repo(const string& filename) : filename(filename) {
    // load content from file when the repository is created
    load();
}

template <typename T>
void Repo<T>::save() {
    ofstream file(filename);

    if (!file.is_open()) {
        throw FileExcept(filename);
    }

    for (const T& item : data) {
        file << item.serialize() << endl;
    }
}

template <typename T>
vector<T> Repo<T>::load() {
    // clear the current data before loading new data
    this->data.clear();

    ifstream file(filename);
    if (!file.is_open()) {
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

template <typename T>
void Repo<T>::add(const T& item) {
    this->data.push_back(item);
}

template <typename T>
Repo<T>::~Repo() {
    // save the current data to file when the repository is destroyed
    save();
}
