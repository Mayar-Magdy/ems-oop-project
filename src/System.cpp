#include "System.h"
System::System()
{
    current_user = nullptr;
    generate_dummy_data();
}

////////////////auth////////////////
void System::display_main_menu()
{
    cout << "Welcome to the Educational Management System\n";
    cout << "Please choose an option [ 1-3 ] :\n";
    cout << "1. Sign in\n" ;
    cout << "2. Sign up\n";
    cout << "3. Exit\n";
}
void System::display_sign_in_menu()
{
    cout << "Please enter your username and password to sign in\n";
    cout << "Username: ";
    string username;
    cin >> username;
    cout << "Password: ";
    string password;
    cin>>password;
    /*string pwd="";
    int i=0;
    for (; i < 4; ++i)
    {
        pwd[i] = getch();
        cout<<"*";
    }
    pwd[i] = '\0';
    cout<<"\n";*/
    sign_in(username, password);
}
void System::display_sign_up_menu()
{
    cout << "Please enter your details to sign up\n";
    cout << "Username: ";
    string username;
    cin >> username;
    cout << "Password: ";
    string password;
    cin>>password;
    cout << "Name: ";
    string name;
    cin.ignore();
    getline(cin, name);
    cout << "Email: ";
    string email;
    cin >> email;
    cout << "Role-> Choose 1 for doctor or 0 for student\n";
    int role;
    cin >> role;
    sign_up(username, password, name, email, role);
}

void System::sign_in(string username, string password)
{
    for (int i=0 ; i<int (users.size()); ++i)
    {
        if (users[i]->get_username()== username && users[i]->get_password() == password)
        {
            current_user = users[i];
            cout << "Sign in successful\n";
            display_user_menu();
            return;
        }
    }
    cout << "Invalid username or password\n";
    display_main_menu();
}

void System::sign_up(string username, string password, string name, string email, int role)
{
    if (role != 0 && role != 1)
    {
        cout << "Role must be 0 or 1\n";
        display_main_menu();
        return;
    }
    if (role)
    {
        Doctor* new_user = new Doctor(users.size(),username, password, name, email);
        users.push_back(new_user);
    }
    else
    {
        Student* new_user = new Student(users.size(), username, password, name, email);
        users.push_back(new_user);
    }
    cout << "Sign up successful\n";
    display_main_menu();
}
void System::display_user_menu()
{
    if (Doctor* doctor = dynamic_cast<Doctor*>(current_user))
    {
        display_doctor_menu(doctor);
    }
    else if (Student* student = dynamic_cast<Student*>(current_user))
    {
        display_student_menu(student);
    }
    else
    {
        cout << "Invalid user\n";
        display_main_menu();
    }

}
void System::log_out()
{
    current_user = nullptr;
    cout << "You have logged out successfully\n";
    display_main_menu();
}
//////////////////////////////////about cources//////////////////////////
void System::Veiw_all_courses()
{
    for(int i=0 ; i<int (courses.size()); ++i)
    {
        cout<<i+1<<')';
        courses[i]->courses_info();
    }
}
Course* System::search_course(string _code)
{
    auto it = indexing_courses.find(_code);
    if (it != indexing_courses.end())
    {
        return courses[it->second];
    }
    else  return nullptr;

}
//////////////////////start studrnt////////////////////////////
void System::display_student_menu(Student* student)
{
    cout << "Welcome, " << student->get_name()<<"\n";
    cout << "Please choose an option:" << endl;
    cout << "1. Register in course" << endl;
    cout << "2. List my courses" << endl;
    cout << "3. View a course" << endl;
    cout << "4. Grades report" << endl;
    cout << "5. Log out" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Veiw_all_courses();
        cout<<"Enter Course Code :";
        string Course_Code;
        cin>>Course_Code;
        if(search_course(Course_Code)== nullptr) cout<<"Invalid code\n";
        else
            student->add_course(search_course(Course_Code));
        display_student_menu(student);
        break;
    }
    case 2:
    {
        student->list_my_courses();
        display_student_menu(student);
        break;
    }
    case 3:
    {
        student->view_courses();
        display_course_menu(student,student->current_viewed_course);
        display_student_menu(student);
        break;
    }
    case 4:
    {
        student->grade_repots();
        display_student_menu(student);
        break;
    }
    case 5:
    {
        log_out();
        display_student_menu(student);
        break;
    }
    default:
    {
        cout << "Invalid choice\n";
        display_student_menu(student);
        break;
    }
    }
}
void System::display_course_menu(Student* student, Course* course)
{
    cout << "Please choose an option:\n";
    cout << "1. Submit assignment solution\n";
    cout << "2. Unregister from course\n";
    cout << "3. Back\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout<<"Which ith [1 - "<<course->assignments_num<<" ] to submit ?";
        int assignments_num;
        cin>>assignments_num;
        cout<<"Enter The Solution :";
        string solution;
        cin>>solution;
        Solution* sol= new Solution(student->get_id(),solution);
        course->get_Assignment(assignments_num)->addSolution(sol);
        display_course_menu( student,  course);
        break;

    }
    case 2:
        course->removeStudent(student->get_id());
        student->remove_course(course->getCode());
        display_course_menu( student,  course);
        break;
    case 3:
        display_student_menu(student);
        break;
    default:
        cout << "Invalid choice" << endl;
        display_course_menu(student, course);
        break;
    }
}
//////////////////////////////doctor//////////////////////////
void System::display_doctor_menu(Doctor* doctor)
{
    cout << "Welcome, dr." << doctor->get_name() << endl;
    cout << "Please choose an option:" << endl;
    cout << "1. List courses" << endl;
    cout << "2. Create course" << endl;
    cout << "3. add assignments" << endl;
    cout << "4. add grades" << endl;
    cout << "5. Log out" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        doctor->list_my_courses();
        display_doctor_menu(doctor);
        break;
    }
    case 2:
    {
        string name, code;
        cout<<"Enter name for the course : ";
        cin>>name;
        cout<<"Enter code for the course : ";
        cin>>code;
        doctor->set_course(name, code);
        Course* c = doctor->get_course(code);
        courses.push_back(c);
        indexing_courses[code]=courses.size()-1;
        display_doctor_menu(doctor);
        break;
    }
    case 3:
    {
        doctor->set_assignment();
        display_doctor_menu(doctor);
        break;
    }
    case 4:
    {
        doctor->set_grades();
        display_doctor_menu(doctor);
        break;
    }
    case 5:
    {
        log_out();
        break;
    }
    default:
    {
        cout << "Invalid choice" << endl;
        display_doctor_menu(doctor);
        break;
    }
    }
}




void System::generate_dummy_data()
{

    Doctor* new_user = new Doctor(users.size(),"mai", "0000", "mai", "mai@ems.com");
    users.push_back(new_user);
    Student* new_user1 = new Student(users.size(),"ola", "0000", "ola", "ola@ems.com");
    users.push_back(new_user1);



    system("cls");
}

System::~System()
{
    //dtor
}



