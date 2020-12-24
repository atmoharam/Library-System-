#ifndef RT_BOOKLIST_H
#define RT_BOOKLIST_H
#include "Book.h"
class BookList {
private:
    Book* books = nullptr;
    int capacity;
    int booksCount=0;
public:
    int count_how_many_books =0;        // use it get all books function for user to count how many books with the same author that taken as parameter
    BookList();
    BookList(const BookList& anotherList);
    BookList(int capacity);
    void addBook(Book book);
    Book * searchBook(string name);
    Book * searchBook(int id);
    void deleteBook(int id); //delete a book
    Book  getTheHighestRatedBook();
    Book* getBooksForUser(User s); // get all books of this author
    Book & operator [ ] (int position);
    friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books ~BookList(); };
    ~BookList();
};

#endif //RT_BOOKLIST_H
