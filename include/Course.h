#ifndef COURSE_H
#define COURSE_H
#include "Assignment.h"

class Course
{
private:
    string name;
    string code;
    vector<Assignment*> assignments;
    vector<int> students; //ids
    string doctor;
    int total_assignments_grades;
    int total_solution_grades;
    int total_submitted=0;
    Course(string name, string , string );
    void updateName(string );
    void updateCode(string );
public:
    int assignments_num;
    Assignment* get_Assignment(int );
    void addAssignment(Assignment* );
    string getName();
    string getCode();
    void addStudent(int );
    void removeStudent(int );
    void viewCourse(int );
    int view_Course_assignments();
    int  get_num_submitted_assignmet(int );
    int get_total_solution_grades(int );
    int get_total_course_grade();
    void course_report(int );
    void student_in_course();
    void courses_info();
    ~Course();
    friend class Doctor;
};

#endif // COURSE_H
