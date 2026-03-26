#include <vector>
#include <string>
#include <sstream>

#include "serde.h"

using namespace std;

// default implementation of deserialize, which throws an error if not overridden by the derived class
template <typename T>
T Serde<T>::deserialize(const string& data) {
    throw runtime_error("Deserialize method not implemented for this type");
}

vector<string> strsplit(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}