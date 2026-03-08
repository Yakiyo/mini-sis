#include <string>

using namespace std;

class Serialize {
   public:
    virtual string serialize() const = 0;
};

template <typename T>
class Deserialize {
   public:
    static T deserialize(const string& str) {
        throw runtime_error("Deserialize not implemented for this type");
    }
};