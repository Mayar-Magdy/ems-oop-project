#ifndef PERSON_H
#define PERSON_H
#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string username;
    string password;
    string name;
    string email;
public:
    Person( string , string , string , string );
    string get_username();
    string get_password();
    string get_name();
    string get_email();
    void set_password(string );
    void set_email(string );
    virtual void display();
    ~Person();
};

#endif // PERSON_H
