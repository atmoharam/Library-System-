#ifndef BOOK_H
#define BOOK_H
#include<cstring>
#include<iostream>
#include "User.h"
using namespace std;
class Book
{
private:
    string title;
    string isbn;
    int id;
    string category;

    User author;
    bool flag = 0; //this is a flag to check if function setAuthor to print the book & AUTHOR DATA in parallel
    double sumRate = 0; //this is a sumRate variable to store all ratings for the book in each time
    double countRates = 0; // this is a countRates variable to count number of ratings in each book to Get average with sumRate/countrates
public:
    double averageRating;
    static int count2; //this is a variable count but we use the same name in User class so i modified the name to count2
    Book();
    Book(string title, string isbn, string category);
    Book(const Book& book);
    void setTitle(string title);
    string getTitle() const;
    void setISBN(string isbn);
    string getISBN();
    void setId(int id);
    int getId();
    void setCategory(string category);
    string getCategory();
    void setAuthor(User user);
    User getAuthor();
    void rateBook(int rating);
    bool operator==(const Book& book);
    friend ostream &operator<<(ostream &output, const Book &book );
    friend istream &operator>>( istream &input, Book &book );
    ~Book();
};
#endif
BOOK_H

