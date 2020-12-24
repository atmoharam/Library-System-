#include "BookList.h"
#include "Book.h"

BookList::BookList ( ) { };

BookList::BookList ( const BookList &anotherList )     //copy constructor
{
    this -> capacity = anotherList . capacity;
    books = new Book[capacity];
    this -> booksCount = anotherList . booksCount;
    for ( int ind = 0; ind < anotherList . capacity; ind ++ ) {
        *( books + ind ) = *( anotherList . books + ind );
    }
}

BookList::BookList ( int capacity )        //pratmeteraize constructor take size
{
    this -> capacity = capacity;
    books = new Book[capacity];
    booksCount = 0;
    for ( int ind = 0; ind < capacity; ind ++ ) {
        ( books + ind ) -> setCategory ( "" );
        ( books + ind ) -> setISBN ( "" );
        ( books + ind ) -> setTitle ( "" );
        ( books + ind ) -> setId ( ind + 1 );

    }
}

Book *BookList::searchBook ( string name )       //search function by name
{
    for ( int ind = 0; ind < capacity && ind < booksCount; ind ++ ) {
        if ( books[ ind ] . getTitle ( ) == name ) {
            return &books[ ind ];
        }
    }
    return nullptr;
}

Book *BookList::searchBook ( int id )     //search function by id
{
    for ( int ind = 0; ind < capacity && ind < booksCount; ind ++ ) {
        if ( books[ ind ] . getId ( ) == id ) {
            return &books[ ind ];
        }
    }
    return nullptr;
}

void BookList::deleteBook ( int id )       //delete book from list
{
    books[ id - 1 ] . setCategory ( "" );
    ( books + id - 1 ) -> setCategory ( "" );
    ( books + id - 1 ) -> setISBN ( "" );
    ( books + id - 1 ) -> setTitle ( "" );
    ( books + id - 1 ) -> setId ( 0 );
    for ( int ind = id; ind < capacity - 1; ind ++ ) {
        books[ ind ] = books[ ind + 1 ];
    }
    books[ capacity - 1 ] . setId ( id );
    booksCount --;
}

Book BookList::getTheHighestRatedBook ( )     //search for the highest rateing in list
{
    double max = books[ 0 ] . averageRating;
    Book maxx ( books[ 0 ] );
    for ( int ind = 0; ind < capacity; ind ++ ) {
        if ( max < ( books + ind ) -> averageRating ) {
            max = ( books + ind ) -> averageRating;
            maxx = books[ ind ];
        }
    }
    return maxx;
}

Book *BookList::getBooksForUser ( User author_target )     //search for all books with the author
{
    for ( int ind = 0; ind < booksCount; ind ++ ) {
        if ( books[ ind ] . getAuthor ( ) . getId ( ) == author_target . getId ( )) {
            count_how_many_books ++;
        }
    }
    Book *founded = new Book[count_how_many_books];       //array of books with the target author
    for ( int ind = 0, index = 0; ind < booksCount && index < count_how_many_books; ind ++ ) {
        if ( books[ ind ] . getAuthor ( ) . getId ( ) == author_target . getId ( )) {
            founded[ index ] = books[ ind ];
            index ++;
        }
    }
    return founded;

}

Book &BookList::operator[] ( int position )       //opereator overload [] to return the content in posistion
{
    if ( position < 0 || position >= capacity ) { cout << "ERROR" << endl; }
    else { return ( books[ position ] ); }


}

void BookList::addBook ( Book book )          //function to add a book
{
    if ( booksCount >= capacity ) {
        cout << "didn't found storage" << endl;
    } else {
        books[ booksCount ] . setTitle ( book . getTitle ( ));
        books[ booksCount ] . setCategory ( book . getCategory ( ));
        books[ booksCount ] . setISBN ( book . getISBN ( ));
        booksCount ++;
    }
}

ostream &operator<< ( ostream &output, BookList &booklist )           //output
{
    for ( int i = 0; i < booklist . booksCount ; i ++ ) {
        Book temp;
        temp = booklist[ i ];
        cout << temp;
    }
    return output;

}

BookList::~BookList ( ) { delete[] books; }
