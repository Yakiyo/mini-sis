#include <string>
#include <vector>
#include "error/error.h"

using namespace std;

// A generic repository class for managing data of type T
// Any class T must implement the Serde interface
template <typename T>
class Repo {
    private:
    string filename;
    vector<T> data;

    public:
    Repo(const string& filename);

    void save();
    vector<T> load();
    void add(const T& item);

    ~Repo();
};