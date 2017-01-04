#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "Dlist.h"
#include "Book.h"
#include "Product.h"
#include "Desktop.h"
#include "GraphingCalc.h"
#include "Laptop.h"
#include "Course.h"
#include "Tutor.h"
#include "MathT.h"
#include "ScienceT.h"
#include "MusicT.h"
#include "BusinessT.h"

class BMScontrol {
/* Purpose: Main controller for book management system. */
/*          Organizes UI and menus.                     */
  public:
    BMScontrol();

    void launch(); 
      /* Purpose: Main menu loop of the program.*/

    void populateTutorArray();
      /* Purpose: Fills tutor array with tutors.*/

  private:
    UImanager*     view;
    Dlist<Course>* courses;
    Product*       products[MAX_PRODUCTS];
    Tutor*         tutors[MAX_TUTORS];
    int            numProducts;
    int            numTutors;
};

#endif

