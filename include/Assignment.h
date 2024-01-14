#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <bits/stdc++.h>
#include "Solution.h"
using namespace std;

class Assignment
{
private:
    string assignmentContent;
    int grade;
    vector<Solution*> solutions;

public:
    Assignment();
    Assignment(string , int );
    string getAssignmentContent();
    void addSolution(Solution* );

    int getGrade();

    void viewAssignment_for_student();

    int solutions_grade(int );
    bool isSubmitted(int );
    int view_solutions();
    Solution* get_solution(int );
    ~Assignment();
    friend class Doctor;

};

#endif // ASSIGNMENT_H
