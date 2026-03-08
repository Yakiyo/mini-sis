#pragma once

#include <string>
#include <vector>

using namespace std;

template <typename T>
class DBRepo {
    private:
    string filename;
    vector<T> data;

    public:
    DBRepo(const string& filename);
    vector<T> load();
    void save();
    vector<T> getData() const;
    void addData(const T& item);
};