#include "Solution.h"
void Solution::setGrade(int grade)
{
    this->grade = grade;
}
void Solution::setFeedback(string feedback)
{
    this->feedback = feedback;
}
Solution::Solution() {};
Solution:: Solution(int student_id, string solutionContent)
{
    this->student_id=student_id;
    this->solutionContent=solutionContent;
    grade=-1;

}
string Solution::getSolutionContent()
{
    return solutionContent;
}
int Solution:: get_Solution_Grade()
{
    return this->grade;
}
string Solution::getFeedback()
{
    return feedback;
}
void Solution::viewSolution()
{
    cout << "Solution content: " << solutionContent << endl;
    cout << "Grade: " << grade << endl;
    cout << "Feedback: " << feedback << endl;
}

int Solution::getStudentId()
{
    return this->student_id;
}
Solution::~Solution()
{
    //dtor
}
