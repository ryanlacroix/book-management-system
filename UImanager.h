#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "Dlist.h"
#include "Book.h"
#include "Tutor.h"
#include <string>

#define TEST_MODE

class UImanager {
/* Purpose: Handles all direct interaction with the user */
  public:
    void mainMenu(int*);
      /* Purpose: Display the main menu to the user */
      /*          and accept the user's selections  */
      /*  Output: Pointer to the selection the      */
      /*          user has made.                    */

    void getCourseData(Course**);
      /* Purpose: Take in data from user to create  */
      /*          new Course Object.                */
      /*  Output: Pointer to address of fully       */
      /*          instantiated Course pointer.      */

    void getTextbookData(Book**);
      /* Purpose: Take in data from user to create  */
      /*          new Book Object.                  */
      /*  Output: Pointer to address of fully       */
      /*          instantiated Book pointer.        */

    void getDesktopData(Product**);
      /* Purpose: Take in data for user to create   */
      /*          new Desktop object.               */
      /*  Output: Pointer to address of fully       */
      /*          instantiated Desktop pointer.     */

    void getGraphingCalcData(Product**);
      /* Purpose: Take in data for user to create   */
      /*          new GraphingCalc object.          */
      /*  Output: Pointer to address of fully       */
      /*          instantiated GraphingCalc pointer.*/

    void getLaptopData(Product**);
      /* Purpose: Take in data for user to create   */
      /*          new Laptop object.                */
      /*  Output: Pointer to address of fully       */
      /*          instantiated Laptop pointer.      */

    void printProduct(Product*);
      /* Purpose: Prints out a product's information*/
      /*      In: Pointer to Product to be printed  */        

    void printCourses(string);
      /* Purpose: Displays info on all courses      */
      /*   Input: Pointer to Dlist to display       */

    void printTextbooks(Course*);
      /* Purpose: Display all textbooks associated  */
      /*          with a given Course.              */
      /*   Input: Pointer to course                 */

    void getCourseCode(string&);
      /* Purpose: Obtain a course code from the user*/
      /*  Output: Address of string containing      */
      /*          course code.                      */

    void getQuantity(int&);
      /* Purpose: Retrieve quantity value from user */
      /*     Out: Quantity.                         */

    void printError(const string&);
      /* Purpose: Prints an error (or message) to   */
      /*          the screen.                       */
      /*   Input: Address of string to print        */

    void pause();
      /* Purpose: Stops program execution until     */
      /*          user presses enter.               */

/* ----- TUTOR FUNCTIONS -----*/

    void showTutors(Tutor**, int);
      /* Purpose: Print out the array of tutors.    */
      /*      In: Array of tutors.                  */
      /*      In: Number of tutors in array.        */

    void chooseTutor(int&);
      /* Purpose: Select which tutor to book        */
      /*          appointment with.                 */
      /*     Out: Selection                         */

  private:
    int getInt();
      /* Purpose: Retrieve an integer from the user */
      /*     Out: Integer.                          */
};

#endif

