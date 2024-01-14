#include "Student.h"
Student::Student(int id, string username, string password, string name, string email) : Person(username, password, name, email)
{
    this->id = id;
}
int Student::get_id()
{
    return id;
}
void Student::list_my_courses()
{
    for(int i=0 ; i<int (student_courses.size()); ++i)
        cout<<i+1<<')'<<student_courses[i]->getName()<<'-'<<"Code "<<student_courses[i]->getCode()<<"\n";
}
void Student::add_course(Course* course)
{
    auto Registed=indexing_student_courses.find(course->getCode());
    if (Registed != indexing_student_courses.end())
    {
        cout<<"You already Registed! ";
    }
    else
    {
        student_courses.push_back(course);
        indexing_student_courses[course->getCode()]=course;
        cout << "You have registered in the course successfully\n" ;
    }
}
void Student::remove_course(string _code)
{
    for (int i = 0; i < int (student_courses.size()); ++i)
    {
        if (student_courses[i]->getCode() == _code)
        {
            student_courses.erase(student_courses.begin() + i);
            break;
        }
    }
}
void Student::view_courses()
{

    list_my_courses();
    cout<<"Which ith [1 -"<<student_courses.size()<<"]course to view?";
    cin>>viewed_course_ith;
    student_courses[viewed_course_ith-1]->viewCourse( this->id );
    current_viewed_course=student_courses[viewed_course_ith-1];
}
void Student::addSolution_dummy(string code,int ass_num,Solution* solution )
{
    indexing_student_courses[code]->get_Assignment(ass_num)->addSolution(solution);
    // student_courses[viewed_course_ith-1]->get_Assignment(id)->addSolution(solution);
}
void Student::addSolution(string code,int ass_num,Solution* solution )
{
    student_courses[viewed_course_ith-1]->get_Assignment(id)->addSolution(solution);
}
void Student::display()
{
    Person::display();
    cout << "ID: " << id << "\n";
    cout << "Number of courses: " << student_courses.size() << "\n";
    list_my_courses()  ;
}
void Student::grade_repots()
{
    for(int i=0 ; i<int (student_courses.size()); ++i)
        student_courses[i]->course_report(this->id);
}
Student::~Student()
{
    //dtor
}
