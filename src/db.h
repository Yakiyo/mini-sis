#pragma once

#include <string>
#include <vector>

using namespace std;

class DB {
   private:
    static const string STUDENTS;
    static const string COURSES;
    static const string INSTRUCTORS;
    static const string ENROLLMENTS;

   public:
    void initializeFiles();
};

const string DB::STUDENTS = "students.txt";
const string DB::COURSES = "courses.txt";
const string DB::INSTRUCTORS = "instructors.txt";
const string DB::ENROLLMENTS = "enrollments.txt";