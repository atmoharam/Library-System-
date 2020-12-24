#include "UserList.h"
#include "User.h"

UserList::UserList () { } //empty cons
UserList::UserList (int capacity) //prameterize constructor take size
{
    this -> capacity = capacity;
    users = new User[capacity];
    usersCount = 0;
    for (int ind = 0; ind < capacity; ind ++) {
        ( users + ind ) -> setName ("");
        ( users + ind ) -> setAge (0);
        ( users + ind ) -> setEmail ("");
        ( users + ind ) -> setPassword ("");
        ( users + ind ) -> setId (ind + 1);
    }
}

void UserList::addUser (User user)       //add user function
{
    users[ usersCount ] . setName (user . getName ());
    users[ usersCount ] . setAge (user . getAge ());
    users[ usersCount ] . setPassword (user . getPassword ());
    users[ usersCount ] . setEmail (user . getEmail ());
    usersCount ++;

}

User *UserList::searchUser (string name)            //search by name function
{
    for (int ind = 0; ind < capacity && ind < usersCount; ind ++) {
        if (users[ ind ] . getName () == name) {
            return &users[ ind ];
        }
    }
    return nullptr;
}

User *UserList::searchUser (int id)         //search by id function
{
    for (int ind = 0; ind < usersCount; ind ++) {
        if (users[ ind ] . getId () == id) {
            return &users[ ind ];
        }
    }
    return nullptr;
}

void UserList::deleteUser (int id)          //delete user from list function
{
    users[ id - 1 ] . setPassword ("");
    users[ id - 1 ] . setEmail ("");
    users[ id - 1 ] . setAge (0);
    users[ id - 1 ] . setName ("");
    for (int ind = id - 1; ind < capacity - 1; ind ++) {
        users[ ind ] = users[ ind + 1 ];
    }
    users[ capacity - 1 ] . setId (id);
    usersCount --;
}

ostream &operator<< (ostream &output, UserList &userList)      //output
{

    for (int ind = 0; ind < userList . usersCount; ind ++) {
        output << userList . users[ ind ];
    }
    return output;
}

UserList::~UserList () { delete[] users; }


