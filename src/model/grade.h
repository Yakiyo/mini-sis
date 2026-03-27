#include <string>
#include <vector>

#include "../interface/serde.h"

using namespace std;

class Grade : public Serde<Grade> {
   private:
    string courseCode;
    string grade;
    int studentId;

   public:
    Grade(string courseCode, string grade, int studentId);

    string serialize() const override;
    static Grade deserialize(const string& data);

    int getStudentId() const;
    string getCourseCode() const;
    string getGrade() const;
};