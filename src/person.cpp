#include "person.h"

Person::Person(int id, const std::string& name) : id(id), name(name) {}

int Person::getId() const {
    return id;
}

std::string Person::getName() const {
    return name;
}

std::string Person::type() const {
    return "Person";
}