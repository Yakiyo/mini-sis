#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> strsplit(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string item;

    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}