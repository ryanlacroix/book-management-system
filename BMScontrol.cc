#include <iostream>
#include <string>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
  view        = new UImanager();
  courses     = new Dlist<Course>();
  numProducts = 0;
  numTutors   = 0;
  populateTutorArray();
}

void BMScontrol::launch()
{
  int  choice;
  string code;

  while (1) {
    choice = -1;
    view->mainMenu(&choice);
    if (choice == 0) {
      // Exit the program
      break;
    }
    else if (choice == 1) { 
      // Add a new course / courses
      int quantity;
      view->getQuantity(quantity);
      if (quantity == 1){
        Course* newCourse;
        view->getCourseData(&newCourse);
        //courses->add(newCourse);
        (*courses) += newCourse;
      } else if (quantity > 1){
        // Create temporary Dlist of courses
        Dlist<Course>* tempList;
        tempList = new Dlist<Course>();
        int i;
        for (i = 0; i < quantity; i++){
          Course* newCourse;
          view->getCourseData(&newCourse);
          (*tempList) += newCourse;
        }
        // Add tempList to courses
        (*courses) += (*tempList);
        // free the temporary list object
        delete tempList;
      }
    }
    else if (choice == 2) {
      // Print all the courses
      view->printCourses(courses->toStringFwd()); // First forwards..
      view->printCourses(courses->toStringBwd()); // then backwards
    }
    else if (choice == 3) {
      // Delete a course;
      string courseCode;
      Course* chosenCourse;
      int quantity;
      view->getQuantity(quantity);
      if (quantity == 1){
        view->getCourseCode(courseCode);
        chosenCourse = courses->getCourseFromID(courseCode);
        if (chosenCourse != 0){
          (*courses) -= chosenCourse;
        } else {
          view->printError("Delete failed, course not found!");
        }
      } else if (quantity > 1){
        Dlist<Course>* tempList;
        tempList = new Dlist<Course>();
        int i;
        for (i = 0; i < quantity; i++){
          // need to collect strings
          string courseCode;
          Course* chosenCourse;
          view->getCourseCode(courseCode);
          chosenCourse = courses->getCourseFromID(courseCode);
          if (chosenCourse != NULL){
            (*tempList) += chosenCourse;
          } else {
            view->printError("Course not found!");
          }
        }
        (*courses) -= (*tempList);
      }
    }
    else if (choice == 4) {
      // Add a textbook
      string    courseCode;
      Course* chosenCourse;
      view->getCourseCode(courseCode);
      chosenCourse = courses->getCourseFromID(courseCode);
      if (chosenCourse != 0){
        Book* newBook;
        view->getTextbookData(&newBook);
        chosenCourse->addBook(newBook);
      } else {
        view->printError("Course not found!");
      }
    }
    else if (choice == 5) {
      // Print textbooks for a specific course
      string  courseCode;
      Course* chosenCourse;
      view->getCourseCode(courseCode);
      chosenCourse = courses->getCourseFromID(courseCode);
      if (chosenCourse != 0){
        view->printTextbooks(chosenCourse);
      } else {
        view->printError("Course not found!");
      }
    }
    else if (choice == 6) {
      // Add a desktop
      Product* newDesktop;
      view->getDesktopData(&newDesktop);
      products[numProducts] = newDesktop;
      numProducts++;
    }
    else if (choice == 7) {
      // Add Graphing Calculator
      Product* newGCalc;
      view->getGraphingCalcData(&newGCalc);
      products[numProducts] = newGCalc;
      numProducts++;
    }
    else if (choice == 8) {
      // Add Laptop
      Product* newLaptop;
      view->getLaptopData(&newLaptop);
      products[numProducts] = newLaptop;
      numProducts++;
    }
    else if (choice == 9) {
      // Add book not associated with course
      Book* newBook;
      view->getTextbookData(&newBook);
      products[numProducts] = newBook;
      numProducts++;
    }
    else if (choice == 10) {
      // Print out inventory
      int i;
      for (i = 0; i < numProducts; i++){
        view->printProduct(products[i]);
      }
    }
    else if (choice == 11) {
      // Show list of tutors
      view->showTutors(tutors, numTutors);
    }
    else if (choice == 12) {
      // Book appointment with tutor
      view->showTutors(tutors, numTutors);
      int c;
      view->chooseTutor(c);
      if (c > numTutors || c < 1){
        view->printError("Invalid selection!");
      } else {
        // Check if tutor is available
        if (tutors[c-1]->getStatus() != "Available"){
          view->printError("Tutor not available!");
        } else {
          // Book the tutor
          tutors[c-1]->bookTutor("Booked");
          view->printError("Tutor has been booked!");
        }
      }
    }

    view->pause();
  }

  // End of program, deallocate stuff
  delete view;
  courses->cleanup();
  int i;
  for (i = 0; i < numProducts; i++){
    delete products[i];
  }
  for (i = 0; i < numTutors; i++){
    delete tutors[i];
  }
  delete courses;
}

void BMScontrol::populateTutorArray()
{
  tutors[0] = new ScienceT("Don Vaughn");
  tutors[1] = new MathT("Johnathan Footwaffle");
  tutors[2] = new MusicT("Ludwig Von-Sneeze");
  tutors[3] = new BusinessT("Biobraf Vermicelli");
  numTutors = 4;
}

