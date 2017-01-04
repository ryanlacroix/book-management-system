#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include "Book.h"

class BookArray {
/* Purpose: Holds a backing array of Book objects.  */
/*          Restricts access to Book array.         */
  public:
    BookArray();
    ~BookArray();
    int      getSize();

    void    add(Book*); 
      /* Purpose: Adds a book to the backing array */
      /*   Input: Pointer to Book object           */

    Book* getBook(int); 
      /* Purpose: Return pointer to book at given  */
      /*          position in backing array        */
      /*   Input: Index of desired book            */
      /*  Output: Pointer to desired book          */

  private:
    int  size;
    Book* books[MAX_BOOKS];
};

#endif
