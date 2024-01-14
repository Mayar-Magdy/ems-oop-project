#ifndef SYSTEM_H
#define SYSTEM_H
#include "Person.h"
#include "Course.h"
#include "Doctor.h"
#include "Student.h"

class System
{
private:
    vector<Person*> users;
    vector<Course*>courses;
    Person* current_user; // the user whose login
    map<string, int> indexing_courses;

public:
    System();
    ~System();
    void display_main_menu();
    void display_sign_in_menu();
    void display_sign_up_menu();
    void sign_in(string , string );
    void sign_up(string , string , string , string , int );
    void display_user_menu();
    void log_out();
    void Veiw_all_courses();
    Course* search_course(string );
    void display_student_menu(Student* );
    void display_course_menu(Student* , Course* );
    void display_doctor_menu(Doctor* );
    void generate_dummy_data();

};
#endif // SYSTEM_H
