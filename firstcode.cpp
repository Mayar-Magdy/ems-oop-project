// #include <bits/stdc++.h>
// using namespace std;
// class Person
// {
// protected:
//     string username;
//     string password;
//     string name;
//     string email;
// public:
//     Person( string username, string password, string name, string email)
//     {
//         this->username = username;
//         this->password = password;
//         this->name = name;
//         this->email = email;
//     }
//     string get_username()
//     {
//         return username;
//     }
//     string get_password()
//     {
//         return password;
//     }
//     string get_name()
//     {
//         return name;
//     }
//     string get_email()
//     {
//         return email;
//     }
//     void set_password(string password)
//     {
//         this->password = password;
//     }
//     void set_email(string email)
//     {
//         this->email = email;
//     }
//     virtual void display()
//     {
//         cout << "Username: " << username << endl;
//         cout << "Name: " << name << endl;
//         cout << "Email: " << email << endl;
//     }
// };
// class Solution
// {
// private:

//     string solutionContent;
//     string feedback;
//     int student_id;
//     int grade;
//     void setGrade(int grade)
//     {
//         this->grade = grade;
//     }
//     void setFeedback(string feedback)
//     {
//         this->feedback = feedback;
//     }
// public:
//     Solution() {};
//     Solution(int student_id, string solutionContent)
//     {
//         this->student_id=student_id;
//         this->solutionContent=solutionContent;
//         grade=-1;

//     }

//     string getSolutionContent()
//     {
//         return solutionContent;
//     }
//     int get_Solution_Grade()
//     {
//         return this->grade;
//     }
//     string getFeedback()
//     {
//         return feedback;
//     }
//     void viewSolution() const
//     {
//         cout << "Solution content: " << solutionContent << endl;
//         cout << "Grade: " << grade << endl;
//         cout << "Feedback: " << feedback << endl;
//     }

//     int getStudentId()
//     {
//         return this->student_id;
//     }
//     friend class Doctor;


// };
// class Assignment
// {
// private:
//     string assignmentContent;
//     int grade;
//     vector<Solution*> solutions;

// public:
//     Assignment() {}
//     Assignment(string content, int grade)
//     {
//         assignmentContent=content;
//         this-> grade=grade;
//     }
//     static int get_id() ; //error logic
//     ~Assignment()
//     {

//     }
//     string getAssignmentContent()
//     {
//         return assignmentContent;
//     }
//     void addSolution(Solution* solution)
//     {
//         solutions.push_back(solution);
//     }

//     int getGrade()
//     {
//         return this->grade;
//     }

//     void viewAssignment_for_student()
//     {
//         cout << "Assignment content: " << assignmentContent << endl;
//         cout << "Assignment Grade: " << grade << endl;
//     }

//     int solutions_grade(int id)
//     {
//         for(int i=0; i<int (solutions.size()); ++i)
//         {
//             if(solutions[i]->getStudentId()==id)
//                 return solutions[i]->get_Solution_Grade();
//         }
//         return 0;
//     }
//     bool isSubmitted(int id)
//     {
//         for(int i=0 ; i<int (solutions.size()); ++i)
//         {
//             if(solutions[i]->getStudentId()==id)
//                 return true;
//         }
//         return false;
//     }
//     int view_solutions()
//     {
//         if(solutions.size())
//         {
//             cout <<"This Assignment has "<< solutions.size()<<"solutions." << endl;
//             cout<<"Which ith [ 1 -"<<solutions.size()<<"] ?";
//         }
//         else cout<<"This Assignment has not any solutions yet :( \n";
//       return (int)solutions.size();
//     }
//     Solution* get_solution(int sol_num )
//     {
//         if(sol_num<=int(solutions.size())&&sol_num>=0)
//             return solutions[sol_num-1];
//         return nullptr;
//     }
//     friend class Doctor;

// };
// class Course
// {
// private:
//     string name;
//     string code;
//     vector<Assignment*> assignments;
//     vector<int> students; //ids
//     string doctor;
//     int total_assignments_grades;
//     int total_solution_grades;
//     int total_submitted=0;

//     Course(string name, string code, string doctor)
//     {
//         this->name = name;
//         this->code = code;
//         this->doctor = doctor;
//         assignments_num=0;
//         total_assignments_grades=0;
//     };
//     void updateName(string name)
//     {
//         name=name;
//     };
//     void updateCode(string code)
//     {
//         code =code;
//     };
// public:
//     int assignments_num;
//     Assignment* get_Assignment(int id )
//     {
//         if(id<=int (assignments.size())&&id>=0)
//             return assignments[id-1];
//         return nullptr;
//     }
//     void addAssignment(Assignment* assignment)
//     {
//         assignments.push_back(assignment);
//         total_assignments_grades+=assignment->getGrade();
//         ++assignments_num;

//     };
//     string getName()
//     {
//         return name;
//     };
//     string getCode()
//     {
//         return code;
//     };


//     void addStudent(int id)
//     {
//         students.push_back(id);
//     };

//     void removeStudent(int id)
//     {
//         for(int i=0; i<int (students.size()); ++i )
//         {
//             if(students[i]==id)
//                 students.erase(students.begin()+i);
//         }

//     };
//     void viewCourse(int student_id)
//     {
//         cout << "Course name: " << name << endl;
//         cout << "Course code: " << code << endl;
//         cout << "taught by : " <<doctor << endl;
//         cout << "Number of assignments: " << assignments.size() << endl;
//         for (int i=0; i<int(assignments.size()); ++i)
//         {
//             cout << "Assignment " <<i+1<<(assignments[i]->isSubmitted(student_id)?"Submitted ":"Not Submitted ")
//                  <<(assignments[i]->solutions_grade(student_id)!=-1?assignments[i]->solutions_grade(student_id):0)<<'/'
//                  <<assignments[i]->getGrade()<< endl;
//         }

//     };
//     void view_Course_assignments()
//     {
//         if(assignments.size())
//         {
//             cout << "Number of assignments: " << assignments.size() << endl;
//             for (int i=0; i<int (assignments.size()); ++i)
//             {
//                 cout << "Assignment " <<'('<<i+1<<')';
//                 cout<< " - Grade" <<assignments[i]->getGrade()<< endl;

//             }
//             cout<<"Which ith [ 1 -"<<assignments.size()<<"] ?";

//         }
//         else cout<<"This Course has not assignments yet!\n";

//     };

//     int  get_num_submitted_assignmet(int student_id)
//     {
//         total_submitted=0;
//         for (int i=0; i<int (assignments.size()); ++i)
//         {
//             total_submitted+=assignments[i]->isSubmitted(student_id);


//         }
//         return total_submitted;
//     }
//     int get_total_solution_grades(int student_id)
//     {
//         total_solution_grades=0;
//         for (int i=0; i<int (assignments.size()); ++i)
//         {
//             total_solution_grades+=assignments[i]->solutions_grade(student_id);
//         }

//         return total_solution_grades;
//     }
//     int get_total_course_grade()
//     {
//         return total_assignments_grades;
//     }
//     void course_report(int id)
//     {
//         if(total_submitted)
//             cout<<"Course Code "<<this->code<<" - "<<"Total submitted "<< get_num_submitted_assignmet(id)<<"assignments - Grade"<<get_total_solution_grades(id)<<"/"<<total_assignments_grades<<"\n";
//     }
//     void student_in_course()
//     {
//         cout << "Number of students: " << students.size() << endl;
//         for (auto student : students)
//         {
//             cout << "student id: " << student << endl;
//         }
//     }
//     void courses_info()
//     {
//         cout<<this->name<<" "<<this->code<<" "<<"taught by "<< this->doctor<<"\n";
//     }


//     ~Course() {};
//     friend class Doctor;

// };
// class Doctor : public Person
// {
// private:
//     int id;
//     vector<Course*>my_courses;
// public:
//     Doctor(int id, string username, string password, string name, string email) : Person(username, password, name, email)
//     {
//         this->id=id;
//     }


//     void display() override
//     {
//         Person::display();
//         cout << "ID: " << id << endl;
//     }
//     void set_course(string name, string code ) //checked
//     {
//         Course*course=new Course(name,code,this->name);
//         my_courses.push_back(course);
//     }
//     Course* get_course(string code)
//     {
//         for (int i = 0; i < int (my_courses.size()); ++i)
//         {
//             if (my_courses[i]->getCode() == code)
//             {
//                 return my_courses[i];
//             }
//         }
//         return nullptr;
//     }
//     void list_my_courses()
//     { if(int (my_courses.size()))
//         for(int i=0; i< int (my_courses.size()); ++i)
//         {
//             my_courses[i]->courses_info();

//         }
//         else cout<<"You have no courses yet :( \n";
//     }
//     void set_assignment()
//     {
//         list_my_courses();
//         string code, content;
//         int grade;
//         cout << "Code: " ;
//         cin>>code;
//         cout << "Content: " ;
//         cin >> content;
//         cout << "Grade: " ;
//         cin>>grade;
//         Assignment *as= new Assignment(content,grade);
//         for(int i=0; i< int (my_courses.size()); ++i)
//         {
//             if( my_courses[i]->getCode() ==code)
//                 my_courses[i]->addAssignment(as);
//         }
//     }
//     Assignment*  set_assignment_dummy(string code,string content,int grade)
//     {
//         Assignment *as= new Assignment(content,grade);
//         for(int i=0; i<int (my_courses.size()); ++i)
//         {
//             if(my_courses[i]->getCode()==code)
//             {
//                 my_courses[i]->addAssignment(as);
//                 break;
//             }

//         }
//         return as;

//     }
//     void set_grades()
//     {
//         //show cources
//         for(int i=0; i<int (my_courses.size()); ++i)
//         {

//             my_courses[i]->courses_info();

//         }
//         cout<<"Which ith [ 1 -"<<my_courses.size()<<"] :";
//         //chose course
//         int current_courses;
//         cin>>current_courses;
//         //view assignment
//         my_courses[current_courses-1]->view_Course_assignments();
//         int assignment_num;
//         cin>>assignment_num;
//         //choose assignment
//         Assignment * current_assignment;
//         current_assignment=my_courses[current_courses-1]->get_Assignment(assignment_num);
//         //view sol
//       int isSolu=  current_assignment->view_solutions();
//       if(isSolu) {
//           Solution *current_solution;
//           //choose sol
//           int current_solution_num;
//           cin >> current_solution_num;
//           //show sol content
//           current_solution = current_assignment->get_solution(current_solution_num);
//           current_solution->getSolutionContent();
//           int sol_grade;
//           string feedback;
//           cout << "Enter Solution Grade : ";
//           cin >> sol_grade;
//           cout << "Any Feedback or Comments ?";
//           cin >> feedback;
//           current_solution->setGrade(sol_grade);
//           current_solution->setFeedback(feedback);
//       }
//       else return;
//     }


// };
// class Student : public Person
// {
// private:
//     int id;
//     vector<Course*>student_courses; //mycourses
//     map<string, Course*> indexing_student_courses; //not innnnnnnnt
// public:

//     Student(int id, string username, string password, string name, string email) : Person(username, password, name, email)
//     {
//         this->id = id;
//     }
//     int get_id()
//     {
//         return id;
//     }
//     void list_my_courses()
//     {
//         for(int i=0 ; i<int (student_courses.size()); ++i)
//             cout<<i+1<<')'<<student_courses[i]->getName()<<'-'<<"Code "<<student_courses[i]->getCode()<<"\n";
//     }
//     void add_course(Course* course)
//     {
//         auto Registed=indexing_student_courses.find(course->getCode());
//         if (Registed != indexing_student_courses.end())
//         {
//             cout<<"You already Registed! ";
//         }
//         else
//         {
//             student_courses.push_back(course);
//             indexing_student_courses[course->getCode()]=course;
//             cout << "You have registered in the course successfully\n" ;
//         }
//     }
//     void remove_course(string _code)
//     {
//         for (int i = 0; i < int (student_courses.size()); ++i)
//         {
//             if (student_courses[i]->getCode() == _code)
//             {
//                 student_courses.erase(student_courses.begin() + i);
//                 break;
//             }
//         }
//     }
//     int viewed_course_ith;
//     Course* current_viewed_course;
//     void view_courses()
//     {

//         list_my_courses();
//         cout<<"Which ith [1 -"<<student_courses.size()<<"]course to view?";
//         cin>>viewed_course_ith;
//         student_courses[viewed_course_ith-1]->viewCourse( this->id );
//         current_viewed_course=student_courses[viewed_course_ith-1];
//     }
//     void addSolution_dummy(string code,int ass_num,Solution* solution )
//     {
//         indexing_student_courses[code]->get_Assignment(ass_num)->addSolution(solution);
//         // student_courses[viewed_course_ith-1]->get_Assignment(id)->addSolution(solution);
//     }
//     void addSolution(string code,int ass_num,Solution* solution )
//     {
//         student_courses[viewed_course_ith-1]->get_Assignment(id)->addSolution(solution);
//     }
//     void display() override
//     {
//         Person::display();
//         cout << "ID: " << id << "\n";
//         cout << "Number of courses: " << student_courses.size() << "\n";
//         list_my_courses()  ;
//     }
//     void grade_repots()
//     {
//         for(int i=0 ; i<int (student_courses.size()); ++i)
//             student_courses[i]->course_report(this->id);
//     }

// };
// class System
// {
// private:
//     vector<Person*> users;
//     vector<Course*>courses;
//     Person* current_user; // the user whose login
//     map<string, int> indexing_courses;

// public:
//     System()
//     {
//         current_user = nullptr;
//         generate_dummy_data();
//     }
//     ~System()
//     {
//    //  delete
//     }
//     ////////////////auth////////////////
//     void display_main_menu()
//     {
//         cout << "Welcome to the Educational Management System\n";
//         cout << "Please choose an option [ 1-3 ] :\n";
//         cout << "1. Sign in\n" ;
//         cout << "2. Sign up\n";
//         cout << "3. Exit\n";
//     }
//     void display_sign_in_menu()
//     {
//         cout << "Please enter your username and password to sign in\n";
//         cout << "Username: ";
//         string username;
//         cin >> username;
//         cout << "Password: ";
//         string password;
//         cin>>password;
//         /*string pwd="";
//         int i=0;
//         for (; i < 4; ++i)
//         {
//             pwd[i] = getch();
//             cout<<"*";
//         }
//         pwd[i] = '\0';
//         cout<<"\n";*/
//         sign_in(username, password);
//     }
//     void display_sign_up_menu()
//     {
//         cout << "Please enter your details to sign up\n";
//         cout << "Username: ";
//         string username;
//         cin >> username;
//         cout << "Password: ";
//         string password;
//         cin>>password;
//         cout << "Name: ";
//         string name;
//         cin.ignore();
//         getline(cin, name);
//         cout << "Email: ";
//         string email;
//         cin >> email;
//         cout << "Role-> Choose 1 for doctor or 0 for student\n";
//         int role;
//         cin >> role;
//         sign_up(username, password, name, email, role);
//     }

//     void sign_in(string username, string password)
//     {
//         for (int i=0 ; i<int (users.size()); ++i)
//         {
//             if (users[i]->get_username()== username && users[i]->get_password() == password)
//             {
//                 current_user = users[i];
//                 cout << "Sign in successful\n";
//                 display_user_menu();
//                 return;
//             }
//         }
//         cout << "Invalid username or password\n";
//         display_main_menu();
//     }

//     void sign_up(string username, string password, string name, string email, int role)
//     {
//         if (role != 0 && role != 1)
//         {
//             cout << "Role must be 0 or 1\n";
//             display_main_menu();
//             return;
//         }
//         if (role)
//         {
//             Doctor* new_user = new Doctor(users.size(),username, password, name, email);
//             users.push_back(new_user);
//         }
//         else
//         {
//             Student* new_user = new Student(users.size(), username, password, name, email);
//             users.push_back(new_user);
//         }
//         cout << "Sign up successful\n";
//         display_main_menu();
//     }
//     void display_user_menu()
//     {
//         if (Doctor* doctor = dynamic_cast<Doctor*>(current_user))
//         {
//             display_doctor_menu(doctor);
//         }
//         else if (Student* student = dynamic_cast<Student*>(current_user))
//         {
//             display_student_menu(student);
//         }
//         else
//         {
//             cout << "Invalid user\n";
//             display_main_menu();
//         }

//     }
//     void log_out()
//     {
//         current_user = nullptr;
//         cout << "You have logged out successfully\n";
//         display_main_menu();
//     }
// //////////////////////////////////about cources//////////////////////////
//     void Veiw_all_courses()
//     {
//         for(int i=0 ; i<int (courses.size()); ++i)
//         {
//             cout<<i+1<<')';
//             courses[i]->courses_info();
//         }
//     }
//     Course* search_course(string _code)
//     {
//         auto it = indexing_courses.find(_code);
//         if (it != indexing_courses.end())
//         {
//             return courses[it->second];
//         }
//         else  return nullptr;

//     }
//     //////////////////////start studrnt////////////////////////////
//     void display_student_menu(Student* student)
//     {
//         cout << "Welcome, " << student->get_name()<<"\n";
//         cout << "Please choose an option:" << endl;
//         cout << "1. Register in course" << endl;
//         cout << "2. List my courses" << endl;
//         cout << "3. View a course" << endl;
//         cout << "4. Grades report" << endl;
//         cout << "5. Log out" << endl;
//         int choice;
//         cin >> choice;
//         switch (choice)
//         {
//             case 1:
//             {
//                 Veiw_all_courses();
//                 cout<<"Enter Course Code :";
//                 string Course_Code;
//                 cin>>Course_Code;
//                 if(search_course(Course_Code)== nullptr) cout<<"Invalid code\n";
//                 else
//                     student->add_course(search_course(Course_Code));
//                 display_student_menu(student);
//                 break;
//             }
//             case 2: {
//                 student->list_my_courses();
//                 display_student_menu(student);
//                 break;
//             }
//             case 3:{
//                 student->view_courses();
//                 display_course_menu(student,student->current_viewed_course);
//                 display_student_menu(student);
//                 break;}
//             case 4:{
//                 student->grade_repots();
//                 display_student_menu(student);
//                 break;}
//             case 5:{
//                 log_out();
//                 display_student_menu(student);
//                 break;}
//             default:{
//                 cout << "Invalid choice\n";
//                 display_student_menu(student);
//                 break;}
//         }
//     }
//     void display_course_menu(Student* student, Course* course)
//     {
//         cout << "Please choose an option:\n";
//         cout << "1. Submit assignment solution\n";
//         cout << "2. Unregister from course\n";
//         cout << "3. Back\n";
//         int choice;
//         cin >> choice;
//         switch (choice)
//         {
//             case 1:
//             {
//                 cout<<"Which ith [1 - "<<course->assignments_num<<" ] to submit ?";
//                 int assignments_num;
//                 cin>>assignments_num;
//                 cout<<"Enter The Solution :";
//                 string solution;
//                 cin>>solution;
//                 Solution* sol= new Solution(student->get_id(),solution);
//                 course->get_Assignment(assignments_num)->addSolution(sol);
//                 display_course_menu( student,  course);
//                 break;

//             }
//             case 2:
//                 course->removeStudent(student->get_id());
//                 student->remove_course(course->getCode());
//                 display_course_menu( student,  course);
//                 break;
//             case 3:
//                 display_student_menu(student);
//                 break;
//             default:
//                 cout << "Invalid choice" << endl;
//                 display_course_menu(student, course);
//                 break;
//         }
//     }
//     //////////////////////////////doctor//////////////////////////
//     void display_doctor_menu(Doctor* doctor)
//     {
//         cout << "Welcome, dr." << doctor->get_name() << endl;
//         cout << "Please choose an option:" << endl;
//         cout << "1. List courses" << endl;
//         cout << "2. Create course" << endl;
//         cout << "3. add assignments" << endl;
//         cout << "4. add grades" << endl;
//         cout << "5. Log out" << endl;
//         int choice;
//         cin >> choice;
//         switch (choice)
//         {
//             case 1: {
//                 doctor->list_my_courses();
//                 display_doctor_menu(doctor);
//                 break;
//             }
//             case 2:
//             {
//                 string name, code;
//                 cout<<"Enter name for the course : ";
//                 cin>>name;
//                 cout<<"Enter code for the course : ";
//                 cin>>code;
//                 doctor->set_course(name, code);
//                 Course* c = doctor->get_course(code);
//                 courses.push_back(c);
//                 indexing_courses[code]=courses.size()-1;
//                 display_doctor_menu(doctor);
//                 break;
//             }
//             case 3:{
//                 doctor->set_assignment();
//                 display_doctor_menu(doctor);
//                 break;
//             }
//             case 4:{
//                 doctor->set_grades();
//                 display_doctor_menu(doctor);
//                 break;
//             }
//             case 5:{
//                 log_out();
//                 break;
//             }
//             default:{
//                 cout << "Invalid choice" << endl;
//                 display_doctor_menu(doctor);
//                 break;}
//         }
//     }




//     void generate_dummy_data()
//     {

//         Doctor* new_user = new Doctor(users.size(),"mai", "0000", "mai magdy", "mai@ems.com");
//         users.push_back(new_user);
//         Student* new_user1 = new Student(users.size(),"ola", "0000", "ola magdy", "ola@ems.com");
//         users.push_back(new_user1);
  


//         system("cls");
//     }

// };
// int main()
// {
//     System s;
//     s.display_main_menu();
//     int choice;
//     bool flag =1;
//     while (flag)
//     {
//         cin >> choice;
//         switch (choice)
//         {
//             case 1:
//                 s.display_sign_in_menu();
//                 break;
//             case 2:
//                 s.display_sign_up_menu();
//                 break;
//             case 3:
//                 flag =0;
//             default:
//                 cout << "Please enter a valid option [1-3]\n";
//         }
//     }


//     return 0;
// }

