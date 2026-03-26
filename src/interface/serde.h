#pragma once

#include <string>
#include <vector>

using namespace std;

// Interface for serialization
//
// This is a pure abstract class. Inheriting classes must implement the serialize() method, which returns a string representation of the object.
class Srlz {
   public:
    virtual string serialize() const = 0;
};

// Interface for deserialization
//
// This is a template class. Inheriting classes must implement the static deserialize() method, 
// which takes a string representation of the object and returns an instance of the class.
template <typename T>
class Dsrlz {
   public:
    static virtual T deserialize(const string& data) {
        throw runtime_error("Deserialization not implemented");
    }
};

// Utility function to split a string by a delimiter
//
// Useful for taking a line from a file and splitting it to use in deserialization.
vector<string> strsplit(const string& str, char delimiter);