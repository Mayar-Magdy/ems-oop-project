#include "Person.h"

Person::Person( string username, string password, string name, string email)
{
        this->username = username;
        this->password = password;
        this->name = name;
        this->email = email;
}
string Person::get_username()
{
        return username;
}
string Person::get_password()
{
        return password;
}
string Person::get_name()
{
        return name;
}
string Person:: get_email()
{
        return email;
}
void Person::set_password(string password)
{
        this->password = password;
}
void Person::set_email(string email)
{
        this->email = email;
}
void Person:: display()
{
        cout << "Username: " << username << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
}
    Person::~Person()
{
    //dtor
}
