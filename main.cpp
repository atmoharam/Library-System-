#include <iostream>
#include "algorithm"
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"

int User::count;
int Book::count2;
using namespace std;

int main () {
    int count_number_of_books = 0;        //to count how many book is stored
    UserList *UserList1 = new UserList;  //create a userlist
    while (true) {
        // choose which menu
        cout << "Select one of the following choices:" << endl
             << "1- Books Menu" << endl
             << "2- Users Menu" << endl
             << "3- Exit" << endl;
        int first_choice = 0; //to chose User / Book
        cin >> first_choice;
        if ( first_choice == 2 )    //userlist choise
        {
            cout << "How many users will be added" << endl;
            int size_of_usersList = 0;      //to input the size of list
            int counter_to_check_UserList_capacity = 0;       //counter to check how many user entered
            cin >> size_of_usersList;
            UserList1 = new UserList (size_of_usersList);        //make a UserList with the size the user enterd
            while (true) {                  //user menu
                cout << "USERS MENU" << endl
                     << "1- Create a USER and add it to the List" << endl
                     << "2- search for a User" << endl
                     << "3- Display all users" << endl
                     << "4- back to main menu" << endl;
                int first_choice_from_user_menu = 0;     //chose from user list
                cin >> first_choice_from_user_menu;
                if ( first_choice_from_user_menu == 1 )  //create user
                {
                    if ( counter_to_check_UserList_capacity >= size_of_usersList )       //check if there any storage to store the  new user or not
                    {
                        cout << "there is no storage in user list" << endl;
                        continue;
                    } else {
                        User firstUser;
                        cin >> firstUser;
                        UserList1 -> addUser (firstUser);
                        counter_to_check_UserList_capacity ++;               //incerment the counter after user is stored
                    }
                } else if ( first_choice_from_user_menu == 2 )      //search
                {
                    while (true) {
                        cout << "SEARCH FOR A USER" << endl
                             << "1- search by name" << endl
                             << "2- search by id" << endl
                             << "3- Return to User Menu" << endl;
                        int search_type = 0;      //to choose search by id / name
                        cin >> search_type;
                        string name_target = "";      //the user name that will search about
                        if ( search_type == 1 ) //by name
                        {
                            cout << "Enter Name" << endl;
                            cin >> name_target;              //enter the user name
                            if ( UserList1 -> searchUser (name_target) ==
                                 nullptr )           //check if user exist or nor
                            {
                                cout << "NOT FOUNDED with name = "<<name_target;
                                continue;
                            } else {
                                cout << *UserList1 -> searchUser (name_target);       //user founded and will print his data

                                cout << "1- Delete User" << endl
                                     << "2- Return to Users Menu" << endl;
                                int after_search_choice = 0;        //to choose delete or return
                                cin >> after_search_choice;
                                if ( after_search_choice == 1 )      //delete
                                {
                                    UserList1 -> deleteUser (UserList1 -> searchUser (name_target) -> getId ());
                                    counter_to_check_UserList_capacity --;
                                    continue;
                                } else if ( after_search_choice == 2 ) //return to user menu
                                {
                                    break;
                                }
                            }

                        } else if ( search_type == 2 )  //by id
                        {
                            cout << "Enter ID" << endl;
                            int Id_Target = 0;        //id of user that will search about
                            cin >> Id_Target;
                            if ( UserList1 -> searchUser (Id_Target) == nullptr )     //check if user exist or not
                            {
                                cout << "NOT FOUNDED with Id = "<<Id_Target << endl;
                                continue;
                            } else {
                                cout << *UserList1 -> searchUser (Id_Target);
                                cout <<"1- Delete User" << endl
                                     << "2- Return to Users Menu" << endl;
                                int after_search_choice = 0;
                                cin >> after_search_choice;
                                if ( after_search_choice == 1 )      //delete
                                {
                                    UserList1 -> deleteUser (UserList1 -> searchUser (Id_Target) -> getId ());
                                    counter_to_check_UserList_capacity --;       //decrese the number of user in list by 1
                                    continue;
                                } else if ( after_search_choice == 2 ) //return to user menu
                                {
                                    break;
                                }
                            }

                        } else if ( search_type == 3 ) {
                            break;
                        }
                    }
                } else if ( first_choice_from_user_menu == 3 ) //Display
                {
                    cout << *UserList1;
                } else if ( first_choice_from_user_menu == 4 ) //return
                {
                    break;
                }
            }
        } else if ( first_choice == 1 )        //book system
        {
            cout << "How many books will be added?" << endl;
            int size_of_bookslist = 0;
            cin >> size_of_bookslist;      //book size
            BookList BookList1 (size_of_bookslist);
            while (true) {
                cout << "BOOKS MENU" << endl
                     << "1- Create a book and add it to the list" << endl
                     << "2- Search for a book" << endl
                     << "3- Display all books (with book rating)" << endl
                     << "4- Get the highest rating book" << endl
                     << "5- Get all books of a user" << endl
                     << "6- Copy the current book list to a new book list and switch to it" << endl
                     << "7- back to the main menu" << endl;
                int choose_from_book_menu = 0;        //to choose from book menu
                cin >> choose_from_book_menu;
                if ( choose_from_book_menu == 1 )       //create book
                {
                    if ( count_number_of_books >= size_of_bookslist )       //check if there storage or not
                    {
                        cout << "there is no storage in Book list" << endl;
                        continue;
                    } else {
                        Book firstBook;
                        cin >> firstBook;
                        BookList1 . addBook (firstBook);
                        count_number_of_books ++;
                        while (true) {
                            cout << "1- Assign author" << endl
                                 << "2- Continue" << endl;
                            int first_choose_after_create = 0;      //to choose if set author or return
                            cin >> first_choose_after_create;
                            if ( first_choose_after_create == 1 )     //assign author
                            {

                                cout << "Enter author id:" << endl;
                                int author_Id = 0;      //the Id of author in users list
                                cin >> author_Id;

                                if ( UserList1 -> searchUser (author_Id) ==
                                     nullptr )        //check if this Id exist or not
                                {
                                    cout << "User NOT FOUNDED with Id = "<<author_Id << endl;
                                } else {
                                    BookList1[ count_number_of_books - 1 ] . setAuthor (
                                            *UserList1 -> searchUser (author_Id));
                                    break;
                                }
                            } else if ( first_choose_after_create == 2 ) //break
                            {
                                break;

                            }
                        }
                    }
                } else if ( choose_from_book_menu == 2 )      //search
                {
                    bool f1=0;
                    while (true)
                    {
                        cout << "SEARCH FOR A BOOK" << endl
                             << "1- Search by name" << endl
                             << "2- Search by id" << endl
                             << "3- Return to Books Menu" << endl;
                        int type_of_search = 0;       //to choose type of search by name or by id
                        cin >> type_of_search;
                        string name_target = "";      //name of book that will search about
                        if ( type_of_search == 1 )     //search by name
                        {
                            cout << "Enter name" << endl;
                            cin >> name_target;
                            if ( BookList1 . searchBook (name_target) == nullptr )        //check if book exist or not
                            {
                                cout << "NOT FOUNDED With name = " <<name_target<< endl;
                                continue;
                            } else {
                                cout << "============Book " << BookList1 . searchBook (name_target) -> getId ()
                                     << " info ===============" << endl
                                     << "Title: " << BookList1 . searchBook (name_target) -> getTitle () << endl
                                     << "ISBN: " << BookList1 . searchBook (name_target) -> getISBN () << endl
                                     << "Id: " << BookList1 . searchBook (name_target) -> getId () << endl
                                     << "Category: " << BookList1 . searchBook (name_target) -> getCategory () << endl
                                     << "Avg Rating: " << BookList1 . searchBook (name_target) -> averageRating << endl;
                                if (BookList1 . searchBook (name_target) ->getAuthor().getName() != "" )       //to check if this book has an author to print his name or not
                                {
                                    cout << "Author: "
                                         <<   BookList1 . searchBook (name_target)->getAuthor().getName()
                                         << endl;
                                }
                                cout<<"=============================="<<endl;
                                while (true) {
                                    cout << "1- Update author" << endl
                                         << "2- Update name" << endl
                                         << "3- Update Category" << endl
                                         << "4- Delete Book" << endl
                                         << "5- Rate book" << endl
                                         << "6- Get back to books menu" << endl;
                                    int choose_after_search = 0;        //choose after search Update author, Update name, Update Category, etc
                                    cin >> choose_after_search;
                                    if ( choose_after_search == 1 ) //update author
                                    {
                                        User new_author;     //object of user to assign the new author
                                        cin >> new_author;
                                        BookList1[ BookList1 . searchBook (name_target) -> getId () - 1 ] . setAuthor (new_author);
                                    } else if ( choose_after_search == 2 )     //update name
                                    {
                                        cout << "Enter name" << endl;
                                        string new_name;        //new name of book
                                        cin >> new_name;
                                        BookList1[ BookList1 . searchBook (name_target) -> getId () - 1 ] . setTitle (
                                                new_name); //get index of result and edit it's name
                                    } else if ( choose_after_search == 3 )   //update category
                                    {
                                        cout << "Enter Category" << endl;
                                        string new_category;        //new category of book
                                        cin >> new_category;
                                        BookList1[ BookList1 . searchBook (name_target) -> getId () -
                                                   1 ] . setCategory (
                                                new_category); //get index of result and edit it's category
                                    } else if ( choose_after_search == 4 )       //delete book
                                    {
                                        BookList1 . deleteBook (BookList1 . searchBook (
                                                name_target) -> getId ());       //get index of result and delete it
                                        count_number_of_books --;            //decrese the number of book in the list
                                        break;
                                    } else if ( choose_after_search == 5 )    //rate book
                                    {
                                        cout << "Enter the Rate" << endl;
                                        int new_rate = 0;       //new rating to the book in index of (search result)
                                        cin >> new_rate;
                                        BookList1[ BookList1 . searchBook (name_target) -> getId () - 1 ] . rateBook (new_rate);
                                    }
                                    else if ( choose_after_search == 6 )      //back
                                    {
                                        f1=1;
                                        break;
                                    }
                                }
                            }
                        } else if ( type_of_search == 2 )       //search by id
                        {
                            cout << "Enter ID:" << endl;
                            int Id_target = 0;
                            cin >> Id_target;    //id of book will search about
                            if ( BookList1 . searchBook (Id_target) ==
                                 nullptr )          //check if book is exist or not
                            {
                                cout << "NOT FOUNDED with Id = " <<Id_target<< endl;
                                continue;
                            } else {
                                cout << "============Book " << BookList1 . searchBook (Id_target) -> getId ()
                                     << " info ===============" << endl
                                     << "Title: " << BookList1 . searchBook (Id_target) -> getTitle () << endl
                                     << "ISBN: " << BookList1 . searchBook (Id_target) -> getISBN () << endl
                                     << "Id: " << BookList1 . searchBook (Id_target) -> getId () << endl
                                     << "Category: " << BookList1 . searchBook (Id_target) -> getCategory () << endl
                                     << "Avg Rating: " << BookList1 . searchBook (Id_target) -> averageRating << endl;
                                if (  BookList1 . searchBook (Id_target) ->getAuthor().getName() != "" )      //to check if this book has an author to print his name or not
                                {
                                    cout << "Author: "
                                         <<  BookList1 . searchBook(Id_target)->getAuthor().getName()
                                         << endl;
                                }
                                cout<<"=============================="<<endl;
                                while (true) {
                                    cout << "1- Update author" << endl
                                         << "2- Update name" << endl
                                         << "3- Update Category" << endl
                                         << "4- Delete Book" << endl
                                         << "5- Rate book" << endl
                                         << "6- Get back to books menu" << endl;
                                    int after_search_choose = 0;    //to choose which edit will done
                                    cin >> after_search_choose;
                                    if ( after_search_choose == 1 ) //update author
                                    {
                                        User new_author;
                                        cin >> new_author;
                                        BookList1[ Id_target - 1 ] . setAuthor (new_author);
                                    } else if ( after_search_choose == 2 )     //update name
                                    {
                                        cout << "Enter name" << endl;
                                        string new_author;
                                        cin >> new_author;
                                        BookList1[ Id_target - 1 ] . setTitle (new_author);
                                    } else if ( after_search_choose == 3 )   //update cat
                                    {
                                        cout << "Enter Category" << endl;
                                        string new_category;
                                        cin >> new_category;
                                        BookList1[ Id_target - 1 ] . setCategory (new_category);
                                    } else if ( after_search_choose == 4 )       //delete book
                                    {
                                        BookList1 . deleteBook (BookList1 . searchBook (Id_target) -> getId ());
                                        count_number_of_books --;        //decrease number of books in list
                                        break;
                                    } else if ( after_search_choose == 5 )    //rate book
                                    {
                                        cout << "Enter the Rate" << endl;
                                        int new_rating = 0;
                                        cin >> new_rating;
                                        BookList1[ Id_target - 1 ] . rateBook (new_rating);
                                    } else if ( after_search_choose == 6 )      //back
                                    {
                                        f1=1;
                                        break;

                                    }
                                }
                            }
                        } else if ( type_of_search == 3)       //exit
                        {
                            break;
                        }
                        if(f1==1)
                        {
                            break;
                        }
                    }

                }
                else if ( choose_from_book_menu == 3 )      //Display
                {
                    cout << BookList1;
                }
                else if ( choose_from_book_menu == 4 )  //Get highest
                {
                    cout << BookList1 . getTheHighestRatedBook ();
                } else if ( choose_from_book_menu == 5 )      //get all books from user
                {
                    cout << "enter Id: " << endl;
                    int Id_target;      //the id will search about
                    cin >> Id_target;
                    if (( UserList1 -> searchUser (Id_target)) != nullptr )       //check if this user exist or not
                    {
                        Book *temp = BookList1 . getBooksForUser (*( UserList1 -> searchUser (Id_target)));     //make a ptr that poiter on the array in function
                        for ( int i = 0; i < BookList1.count_how_many_books ; i ++ )       //to print all data of all array
                        {
                            cout << "============Book " << (( temp + i )) -> getId () << " info ===============" << endl
                                 << "Title: " << ( temp + i ) -> getTitle () << endl
                                 << "ISBN: " << ( temp + i ) -> getISBN () << endl
                                 << "Id: " << ( temp + i ) -> getId () << endl
                                 << "Category: " << ( temp + i ) -> getCategory () << endl
                                 << "Avg Rating: " << ( temp + i ) -> averageRating << endl;
                            if ( UserList1 -> searchUser (( temp + i ) -> getAuthor () . getName ()) !=
                                 nullptr )      //to check if this book has an author to print his name or not
                            {
                                cout << "Author: "
                                     << UserList1->searchUser( BookList1 . searchBook (Id_target)->getAuthor().getName())->getName()<< endl;
                            }
                        }
                    }
                } else if ( choose_from_book_menu == 6 )      //copy list
                {
                    BookList copy (BookList1);       //create a new list and make it the list used in menu
                    BookList1 = copy;
                    cout << "Copied current List (" << count_number_of_books
                         << " books) to a new list and switched to it" << endl;
                } else if ( choose_from_book_menu == 7 )          //back
                {
                    break;
                }

            }
        } else if ( first_choice == 3 ) {
            break;
        }
    }
}
