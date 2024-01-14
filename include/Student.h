#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Course.h"

class Student : public Person
{
private:
    int id;
    vector<Course*>student_courses; //mycourses
    map<string, Course*> indexing_student_courses; //not innnnnnnnt
public:

    Student(int , string , string , string , string );
    int get_id();
    void list_my_courses();
    void add_course(Course* );
    void remove_course(string );
    int viewed_course_ith;
    Course* current_viewed_course;
    void view_courses();
    void addSolution_dummy(string ,int ,Solution*  );
    void addSolution(string ,int ,Solution*  );
    void display() override;
    void grade_repots();
    ~Student();

};

#endif // STUDENT_H
