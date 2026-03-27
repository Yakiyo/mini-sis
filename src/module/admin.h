// #include <string>
// #include <vector>
// #include "../model/employee.h"

// using namespace std;

// class AdminMod {
//     private:
//     int id;
//     Admin ad;

//     public:
//     AdminMod(int id, const Admin& ad) : id(id), ad(ad) {}
// };

#pragma once

#include "../db/repo.h"

void adminMod(int adminId, RepoGroup& rg);