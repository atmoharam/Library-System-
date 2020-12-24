#include "Book.h"

Book::Book ( )        //default Constructor
{
    title = " ";
    isbn = " ";
    count2 ++;
    this -> id = count2;
    category = " ";
    averageRating = 0.0;
}

Book::Book ( string title , string isbn , string category ) //Parameterized constructor
{
    this -> title = title;
    this -> isbn = isbn;
    this -> category = category;
    count2 ++;
    this -> id = count2;
}

Book::Book ( const Book & book )        //copy constructor
{
    this -> id = book . id;
    this -> category = book . category;
    this -> isbn = book . isbn;
    this -> title = book . title;
    this -> averageRating = book . averageRating;
    this -> author . setName ( book . author . getName ( ));
    this -> author . setPassword ( book . author . getPassword ( ));
    this -> author . setEmail ( book . author . getEmail ( ));
    this -> author . setAge ( book . author . getAge ( ));
    this -> author . setId ( book . author . getId ( ));
}

void Book::setTitle ( string title_ )          //Setter function. it sets the value of private member title
{
    this -> title = title_;
}

string Book::getTitle ( ) const               //Getter function of title. it returns the title of the book
{
    return title;
}

void Book::setISBN ( string isbn_ )            //Setter function. it sets the value of private member isbn
{
    this -> isbn = isbn_;
}

string Book::getISBN ( )                      //Getter function of isbn. it returns the isbn of the book
{
    return isbn;
}

void Book::setId ( int id_ )                   //Setter function. it sets the value of private member id
{
    this -> id = id_;
}

int Book::getId ( )                           //Getter function of id. it returns the id of the book
{
    return id;
}

void Book::setCategory ( string category_ )        //Setter function. it sets the value of private member category
{
    this -> category = category_;
}

string Book::getCategory ( )                      //Getter function of category. it returns the category of the book
{
    return category;
}

void Book::setAuthor (User user )             //Setter function of the private member author which takes an object of class user as a parameter and Places user data as author data
{
    this -> author . setName ( user . getName ( ));
    this -> author . setAge ( user . getAge ( ));
    this -> author . setEmail ( user . getEmail ( ));
    this -> author . setPassword ( user . getPassword ( ));
    this -> author . setId ( user . getId ( ));
    flag = 1;                         //the value of variable flag will change if we use this function(setAuthor)
    //and this mean that the book has an author now.

}

User Book::getAuthor ( )      //Getter function of author. it returns the author info
{
    return author;
}

void Book::rateBook ( int rating ) //this function calculate the rate of the book
{
    sumRate += rating;
    countRates ++;
    averageRating = ( sumRate / countRates );
}

bool Book::operator == (const Book & book )     //Two books are considered as equal if they have the same title, isbn,category, id and author

{
    if ( this -> title == book . title && this -> isbn == book . isbn && this -> category == category &&
         this -> id == id && this -> author == book . author ) {
        return true;
    } else {
        return false;
    }
}

ostream &
operator << ( ostream & output , const Book & book )         //Operator >> and operator << (cout & cin function )
{
    output << endl << "======== Book " << book . id << " info ========" << endl
           << "Title: " << book . title << endl << "ISBN: " << book . isbn << endl << "ID: " << book . id << endl
           << "Category " << book . category << endl << "Ang Rating: " << book . averageRating << endl;

    if ( book . flag == 1 && book.author.getName() !="" ) //if true this mean that we use the function setAuthor so the author data will be printed.
    {
        output << book . author;
    }
    return output;
}

istream & operator >> ( istream & input , Book & book ) {
    cout << "Enter the book information in this order " << endl
         << "Title ISPN Category (space separated)" << endl;
    input >> book . title >> book . isbn >> book . category;
    return input;
}

Book::~Book () { }
