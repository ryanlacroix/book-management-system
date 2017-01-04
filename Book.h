#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Product.h"

class Book : public Product
{
/* Purpose: Holds information about one book  */
  public:
    Book(float, int, string="", string="", string="", int=1, int=0);
    string  getTitle();
    string  getAuthors();
    string  getISBN();
    int     getEdition();
    int     getYear();

  private:
    string    title;
    string    authors;
    string    isbn;
    int       edition;
    int       year;
};

#endif

