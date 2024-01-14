#ifndef DOCTOR_H
#define DOCTOR_H
#include "Person.h"
#include "Course.h"


class Doctor : public Person
{
private:
    int id;
    vector<Course*>my_courses;
public:
    Doctor(int , string , string , string , string ) ;
    void display() override;
    void set_course(string , string  ) ;
    Course* get_course(string );
    void list_my_courses();
    void set_assignment();
    Assignment*  set_assignment_dummy(string ,string ,int );
    void set_grades();
   ~Doctor();

};

#endif // DOCTOR_H
