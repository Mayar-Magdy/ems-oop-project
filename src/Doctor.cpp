#include "Doctor.h"
Doctor::Doctor(int id, string username, string password, string name, string email) : Person(username, password, name, email)
    {
        this->id=id;
    }
void Doctor::display()
    {
        Person::display();
        cout << "ID: " << id << endl;
    }
void Doctor::set_course(string name, string code ) //checked
    {
        Course*course=new Course(name,code,this->name);
        my_courses.push_back(course);
    }
Course* Doctor::get_course(string code)
    {
        for (int i = 0; i < int (my_courses.size()); ++i)
        {
            if (my_courses[i]->getCode() == code)
            {
                return my_courses[i];
            }
        }
        return nullptr;
    }
void Doctor::list_my_courses()
    { if(int (my_courses.size()))
        for(int i=0; i< int (my_courses.size()); ++i)
        {
            my_courses[i]->courses_info();

        }
        else cout<<"You have no courses yet :( \n";
    }
void  Doctor::set_assignment()
    {
        list_my_courses();
        string code, content;
        int grade;
        cout << "Code: " ;
        cin>>code;
        cout << "Content: " ;
        cin >> content;
        cout << "Grade: " ;
        cin>>grade;
        Assignment *as= new Assignment(content,grade);
        for(int i=0; i< int (my_courses.size()); ++i)
        {
            if( my_courses[i]->getCode() ==code)
                my_courses[i]->addAssignment(as);
        }
    }
Assignment*  Doctor::set_assignment_dummy(string code,string content,int grade)
    {
        Assignment *as= new Assignment(content,grade);
        for(int i=0; i<int (my_courses.size()); ++i)
        {
            if(my_courses[i]->getCode()==code)
            {
                my_courses[i]->addAssignment(as);
                break;
            }

        }
        return as;

    }
void Doctor::set_grades()
    {
        //show cources
        for(int i=0; i<int (my_courses.size()); ++i)
        {

            my_courses[i]->courses_info();

        }
        cout<<"Which ith [ 1 -"<<my_courses.size()<<"] :";
        //chose course
        int current_courses;
        cin>>current_courses;
        //view assignment
        my_courses[current_courses-1]->view_Course_assignments();
        int assignment_num;
        cin>>assignment_num;
        //choose assignment
        Assignment * current_assignment;
        current_assignment=my_courses[current_courses-1]->get_Assignment(assignment_num);
        //view sol
      int isSolu=  current_assignment->view_solutions();
      if(isSolu) {
          Solution *current_solution;
          //choose sol
          int current_solution_num;
          cin >> current_solution_num;
          //show sol content
          current_solution = current_assignment->get_solution(current_solution_num);
          current_solution->getSolutionContent();
          int sol_grade;
          string feedback;
          cout << "Enter Solution Grade : ";
          cin >> sol_grade;
          cout << "Any Feedback or Comments ?";
          cin >> feedback;
          current_solution->setGrade(sol_grade);
          current_solution->setFeedback(feedback);
      }
      else return;
    }
Doctor::~Doctor()
{
    //dtor
}
