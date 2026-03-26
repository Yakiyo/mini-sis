#include "user.h"

#include <string>

using namespace std;

int User::getId() const {
    return id;
}

string User::getName() const {
    return name;
}