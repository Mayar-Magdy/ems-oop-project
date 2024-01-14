#include "Course.h"
Course::Course(string name, string code, string doctor)
{
    this->name = name;
    this->code = code;
    this->doctor = doctor;
    assignments_num=0;
    total_assignments_grades=0;
};
void Course::updateName(string name)
{
    name=name;
};
void Course::updateCode(string code)
{
    code =code;
};
Assignment* Course::get_Assignment(int id )
{
    if(id<=int (assignments.size())&&id>=0)
        return assignments[id-1];
    return nullptr;
}
void Course::addAssignment(Assignment* assignment)
{
    assignments.push_back(assignment);
    total_assignments_grades+=assignment->getGrade();
    ++assignments_num;

};
string Course::getName()
{
    return name;
};
string Course::getCode()
{
    return code;
};


void Course::addStudent(int id)
{
    students.push_back(id);
};

void Course::removeStudent(int id)
{
    for(int i=0; i<int (students.size()); ++i )
    {
        if(students[i]==id)
            students.erase(students.begin()+i);
    }

};
void Course::viewCourse(int student_id)
{
    cout << "Course name: " << name << endl;
    cout << "Course code: " << code << endl;
    cout << "taught by : " <<doctor << endl;
    cout << "Number of assignments: " << assignments.size() << endl;
    for (int i=0; i<int(assignments.size()); ++i)
    {
        cout << "Assignment " <<i+1<<(assignments[i]->isSubmitted(student_id)?"Submitted ":"Not Submitted ")
             <<(assignments[i]->solutions_grade(student_id)!=-1?assignments[i]->solutions_grade(student_id):0)<<'/'
             <<assignments[i]->getGrade()<< endl;
    }

};
void Course::view_Course_assignments()
{
    if(assignments.size())
    {
        cout << "Number of assignments: " << assignments.size() << endl;
        for (int i=0; i<int (assignments.size()); ++i)
        {
            cout << "Assignment " <<'('<<i+1<<')';
            cout<< " - Grade" <<assignments[i]->getGrade()<< endl;

        }
        cout<<"Which ith [ 1 -"<<assignments.size()<<"] ?";

    }
    else cout<<"This Course has not assignments yet!\n";

};

int  Course::get_num_submitted_assignmet(int student_id)
{
    total_submitted=0;
    for (int i=0; i<int (assignments.size()); ++i)
    {
        total_submitted+=assignments[i]->isSubmitted(student_id);


    }
    return total_submitted;
}
int Course::get_total_solution_grades(int student_id)
{
    total_solution_grades=0;
    for (int i=0; i<int (assignments.size()); ++i)
    {
        total_solution_grades+=assignments[i]->solutions_grade(student_id);
    }

    return total_solution_grades;
}
int Course::get_total_course_grade()
{
    return total_assignments_grades;
}
void Course::course_report(int id)
{
    if(total_submitted)
        cout<<"Course Code "<<this->code<<" - "<<"Total submitted "<< get_num_submitted_assignmet(id)<<"assignments - Grade"<<get_total_solution_grades(id)<<"/"<<total_assignments_grades<<"\n";
}
void Course::student_in_course()
{
    cout << "Number of students: " << students.size() << endl;
    for (auto student : students)
    {
        cout << "student id: " << student << endl;
    }
}
void Course::courses_info()
{
    cout<<this->name<<" "<<this->code<<" "<<"taught by "<< this->doctor<<"\n";
}
Course::~Course() {};
