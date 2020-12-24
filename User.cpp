#include "User.h"

User::User ( )                //the default constructor function.
{
    name = "";             //initialize the user name with empty string
    age = 0;
    id = 0;
    password = "";
    email = "";
    count ++;            //Every time the user create a new object variable count Will increase by 1.
    this -> id = count; //Store value of count in id as Id of the User.
}

User::User ( string name_, int age_, string email_, string password_ ) //The Parameterized constructor
{
    this -> name = name_;
    this -> age = age_;
    this -> email = email_;
    this -> password = password_;
    count ++;
    this -> id = count;
}

User::User ( const User & user )                  //Copy constructor
{
    this -> name = user . name;
    this -> age = user . age;
    this -> id = user . id;
    this -> email = user . email;
    this -> password = user . password;
}

bool
User::operator == ( const User & user ) //Two users are considered equal if they have the same email, name, age and id
{
    if ( this -> name == user . name && this -> age == user . age && this -> id == user . id &&
         this -> email == user . email && this -> password == user . password ) {
        return true;
    } else {
        return false;
    }
}

void User::setName ( string name_ )    //Setter function it sets the value of private member name
{
    this -> name = name_;
}

string User::getName ( ) const    //Getter function of name. it returns the name of the user
{
    return name;
}

void User::setPassword ( string password_ )         //Setter function it sets the value of private member password
{
    this -> password = password_;
}

string User::getPassword ( ) const          //Getter function of password. it returns the password of the user
{
    return password;
}

void User::setEmail ( string email_ )      //Setter function it sets the value of private member email
{
    this -> email = email_;
}

string User::getEmail ( ) const           //Getter function of email. it returns the email of the user
{
    return email;
}

void User::setAge ( int age_ )             //Setter function it sets the value of private member age
{
    this -> age = age_;
}

int User::getAge ( ) const               //Getter function of age. it returns the age of the user
{
    return age;
}

void User::setId ( int id_ )               //Setter function it sets the value of private member id
{
    this -> id = id_;
}

int User::getId ( ) const                 //Getter function of id. it returns the id of the user
{
    return id;
}

ostream & operator << ( ostream & output, const User & user )    //Operator >> and operator << (cout & cin function )
{
    output << "======== User " << user . id << " info ========" << endl
           << "Name: " << user . name << endl << "Age: " << user . age << endl << "ID: " << user . id << endl
           << "Email: " << user . email << endl
           << "==============================" << endl;
    return output;
}

istream & operator >> ( istream & input, User & user ) {
    cout << "Enter the User information in this order" << endl
         << "Name Age Email Password (space separated) " << endl;
    input >> user . name;
    input >> user . age;
    input >> user . email;
    input >> user . password;
    cout << endl;
    return input;
}

User::~User ( ) { }
