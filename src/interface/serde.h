#pragma once

#include <string>
#include <vector>

using namespace std;

// Serialization and Deserialization interface
//
// Classes that inherit from Serde must implement the serialize() method to convert an object to a string.
// They can also implement the static deserialize() method to create an object from a string.
template <typename T>
class Serde {
   public:
    virtual string serialize() const = 0;
    static virtual T deserialize(const string& data);
};

// Utility function to split a string by a delimiter
//
// Useful for taking a line from a file and splitting it to use in deserialization.
vector<string> strsplit(const string& str, char delimiter);