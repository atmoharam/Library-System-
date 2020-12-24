#ifndef USER_H
#define USER_H
#include<cstring>
#include<iostream>
#include "cstring"
#include "algorithm"
static int count()
{
    return 0;
}
using namespace std;
class User
{
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count;   //this variable will be increased by 1 every time we create an object of the class.
    User();
    User(string name, int age, string email, string password);
    User( const User& user);
    bool operator==(const User& user);
    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword()const;
    void setEmail(string email);
    string getEmail() const;
    void setAge(int age);
    int getAge() const;
    void setId(int id);
    int getId() const;
    friend ostream &operator<<(ostream &output, const User &user );
    friend istream &operator>>( istream &input, User &user );
    ~User();
};
#endif // USER_H


