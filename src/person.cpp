#include "person.h"

using namespace std;

Person::Person(int id, const string name){
    this->id = id;
    this->name = name;
}

int Person::getId() const {
    return id;
}

void Person::setId(int id){
    this->id = id;
}

string Person::getName() const {
    return name;
}

void Person::setName(const string name){
    this->name = name;
}
