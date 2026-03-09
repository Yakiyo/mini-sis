#include <string>

#include "person.h"
#include "serde.h"

class Employee : public Person, public Serialize, public Deserialize<Employee> {
   private:
    Designation designation;

   public:
    Employee(const int id, const string& name, Designation designation);
    virtual Designation getdesignation() const;
    virtual void setdesignation(Designation designation);
    virtual string type() const = 0;
    virtual string serialize() const = 0;
    static Employee deserialize(const string& str);
};

enum class Designation {
    Faculty,
    Admin,
    Staff
};

string designationStr(Designation desig);
Designation StrtoDesignation(const string& str);