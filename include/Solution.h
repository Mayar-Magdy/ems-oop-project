#ifndef SOLUTION_H
#define SOLUTION_H
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:

    string solutionContent;
    string feedback;
    int student_id;
    int grade;
    void setGrade(int );
    void setFeedback(string );
public:
    Solution() ;
    Solution(int, string );

    string getSolutionContent();
    int get_Solution_Grade();
    string getFeedback();
    void viewSolution() ;
    int getStudentId();
    ~Solution();
    friend class Doctor;


};

#endif // SOLUTION_H
