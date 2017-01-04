#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"
#include "Product.h"
#include "Desktop.h"
#include "GraphingCalc.h"
#include "Laptop.h"

using namespace std;

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course" << endl;
  cout << "  ( 2 )  List all courses" << endl;
  cout << "  ( 3 )  Delete course" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 4 )  Add textbook" << endl;
  cout << "  ( 5 )  List course textbooks" << endl;
  cout << "  Product options:" << endl;
  cout << "  ( 6 )  Add desktop" << endl;
  cout << "  ( 7 )  Add graphing calculator" << endl;
  cout << "  ( 8 )  Add laptop" << endl;
  cout << "  ( 9 )  Add Book (not associated with course)" << endl;
  cout << "  ( 10 ) Print inventory" << endl;
  cout << "  Tutor Database:" << endl;
  cout << "  ( 11 ) Browse tutor database" << endl;
  cout << "  ( 12 ) Book tutor appointment" << endl << endl;

  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 12) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::showTutors(Tutor** tutors, int numTut)
{
  cout << endl << "Tutors in your area:" << endl;
  int i;
  for (i = 0; i < numTut; i++){
    string bio = "";
    tutors[i]->tutorBio(bio);
    cout << endl << i+1 << ". " << "Name: " << tutors[i]->getName() << endl ;
    cout << "   Bio : " << bio << endl;
    cout << " Status: " << tutors[i]->getStatus() << endl;
  }
}

void UImanager::chooseTutor(int& choice)
{
  cout << endl << "Which tutor # would you like to book? (eg 1): ";
  choice = getInt();
}

void UImanager::getQuantity(int& q)
{
  cout << "How many?: ";
  q = getInt();
}

void UImanager::getTextbookData(Book** newBook)
{
  string title, author, isbn;
  int edition, year, id;
  float price;

  cout << endl;
  cout << "Enter book title:  ";
  getline(cin, title);

  cout << endl << "Enter book author:  ";
  getline(cin, author);

  cout << endl << "Enter isbn:  ";
  getline(cin, isbn);

  cout << endl << "Enter edition (eg 4):  ";
  cin >> edition;

  cout << endl << "Enter year:  ";
  cin >> year;

  cout << endl << "Enter price: ";
  cin >> price;

  cout << endl << "Enter id#:  ";
  cin >> id;

  Book* tmpBook;
  tmpBook = new Book(price, id, title, author, isbn, edition, year);
  *newBook = tmpBook;
}

void UImanager::getDesktopData(Product** newDesktop)
{
  float price, ampDraw;
  int id;
  string size;

  cout << endl;
  cout << "Enter price: $";
  cin >> price;

  cout << endl << "Enter ID: #";
  cin >> id;

  getline(cin, size);// temporary. Flush previous input
  cout << endl << "Enter size (small, large, etc): ";
  getline(cin, size);

  cout << endl << "Enter amp draw: ";
  cin >> ampDraw;

  Product* tempDesktop;
  tempDesktop = new Desktop(price, id, size, ampDraw);
  *newDesktop = tempDesktop;
}

void UImanager::getGraphingCalcData(Product** newGCalc)
{
  float price;
  int id, mem;
  bool cScreen;
  char c;

  cout << endl;
  cout << "Enter price: $";
  cin >> price;

  cout << endl << "Enter ID: #";
  cin >> id;

  cout << endl << "Enter memory size (eg 256): ";
  cin >> mem;

  cout << endl << "Colour screen? (y or n) ";
  cin >> c;
  if (c == 'y'){
    cScreen = true;
  } else {
    cScreen = false;
  }

  Product* tempGCalc;
  tempGCalc = new GraphingCalc(price, id, cScreen, mem);
  *newGCalc = tempGCalc;
}

void UImanager::getLaptopData(Product** newLaptop)
{
  float price, ampDraw, sWidth;
  int id, bLife;
  string size;

  cout << endl;
  cout << "Enter price: $";
  cin >> price;

  cout << endl << "Enter ID: #";
  cin >> id;

  getline(cin, size);// temporary. Flush previous input
  cout << endl << "Enter size (small, large, etc): ";
  getline(cin, size);

  cout << endl << "Enter amp draw: ";
  cin >> ampDraw;

  cout << endl << "Enter screen width: ";
  cin >> sWidth;

  cout << endl << "Enter batter life (hours): ";
  cin >> bLife;

  Product* tempLaptop;
  tempLaptop = new Laptop(price, id, size, ampDraw, sWidth, bLife);
  *newLaptop = tempLaptop;
}

void UImanager::getCourseData(Course** course)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;

  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }
  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  ";
  getline(cin, name);

  cout << endl << "Enter instructor name:   ";
  getline(cin, inst);

  cout << endl << "Enter enrolment:   ";
  getline(cin, str);
  stringstream ss(str);
  ss >> enrol;
  Course* tmpCourse;
  tmpCourse = new Course(subj, num, name, inst, enrol);
  *course = tmpCourse;

}

void UImanager::printProduct(Product* p)
{
  cout << "Product price: " << p->getPrice() << ", ID: " << p->getID() << endl;
}

void UImanager::printTextbooks(Course* c)
{
  cout << "Textbooks:" << c->getNumBooks() << endl << endl;
  for (int i = 0; i < c->getNumBooks(); i++) {
    Book* b = c->getBook(i);
    cout << "Title: " << b->getTitle() << endl;
    cout << "Author: " << b->getAuthors() << endl;
    cout << "ISBN: " << b-> getISBN() << endl;
    cout << "Edition: " << b->getEdition() << endl;
    cout << "Year: " << b->getYear() << endl << endl;
  }
}

void UImanager::printCourses(string coursesInfo)
{
  cout << coursesInfo << endl;
}

void UImanager::getCourseCode(string& code)
{
  string enteredCode;
  cout << "Enter the course code: ";
  getline(cin, enteredCode);
  code = enteredCode;
}

void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

void UImanager::printError(const string& err)
{
  cout << endl << err << endl;
}

int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

