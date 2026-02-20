#include "db.h"

#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DB {
   private:
    static const string _file;
    static bool initialized;
    static DB instance;
    sqlite3* db;

   public:
    DB();
    static DB& getInstance();
    void open();
    void close();
};

DB::DB() {
    // empty constructor
}

DB& DB::getInstance() {
    if (!initialized) {
        instance = DB();
        initialized = true;
    }
    return instance;
}

void DB::open() {
    int exit = 0;
    exit = sqlite3_open(_file.c_str(), &db);

    if (exit) {
        cerr << "Error open DB " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    cout << "Opened Database Successfully!" << std::endl;
}

void DB::close() {
    sqlite3_close(db);
    cout << "Closed Database Successfully!" << std::endl;
}


const string DB::_file = "sis.db";
bool DB::initialized = false;