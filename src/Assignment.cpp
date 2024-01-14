#include "Assignment.h"
Assignment::Assignment() {}

Assignment::Assignment(string content, int grade)
{
    assignmentContent=content;
    this-> grade=grade;
}
string Assignment::getAssignmentContent()
{
    return assignmentContent;
}
void Assignment::addSolution(Solution* solution)
{
    solutions.push_back(solution);
}

int Assignment::getGrade()
{
    return this->grade;
}

void Assignment::viewAssignment_for_student()
{
    cout << "Assignment content: " << assignmentContent << endl;
    cout << "Assignment Grade: " << grade << endl;
}

int Assignment::solutions_grade(int id)
{
    for(int i=0; i<int (solutions.size()); ++i)
    {
        if(solutions[i]->getStudentId()==id)
            return solutions[i]->get_Solution_Grade();
    }
    return 0;
}
bool Assignment:: isSubmitted(int id)
{
    for(int i=0 ; i<int (solutions.size()); ++i)
    {
        if(solutions[i]->getStudentId()==id)
            return true;
    }
    return false;
}
int Assignment::view_solutions()
{
    if(solutions.size())
    {
        cout <<"This Assignment has "<< solutions.size()<<"solutions." << endl;
        cout<<"Which ith [ 1 -"<<solutions.size()<<"] ?";
    }
    else cout<<"This Assignment has not any solutions yet :( \n";
    return (int)solutions.size();
}
Solution* Assignment::get_solution(int sol_num )
{
    if(sol_num<=int(solutions.size())&&sol_num>=0)
        return solutions[sol_num-1];
    return nullptr;
}Assignment::~Assignment()
{
    //dtor
}
