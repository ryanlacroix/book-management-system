#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "BookArray.h"

class Course {
/* Purpose: Holds information about one course.  */
  public:
    Course(string="", string="", string="", string="", int=0);
    ~Course();
    string  getCode();
    string  getName();
    string  getInstr();
    int     getEnrol();
    int      getNumBooks();
    Book*     getBook(int);

    void    addBook(Book*); 
      /* Purpose: Add a textbook to the course */
      /*   Input: Pointer to book to add       */

  private:
    string    subj;
    string    num;
    string    name;
    string    instr;
    int       enrol;
    BookArray* books;
};

#endif

