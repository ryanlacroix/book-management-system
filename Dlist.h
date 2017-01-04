#ifndef DLIST_H
#define DLIST_H

#include "Course.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


template <class T>
class Dlist {
/* Purpose: Holds a doubly linked list of Course objects. */
/*          Restricts access to Course array.             */
  template <class V>
  friend ostream& operator<<(ostream&, Dlist<V>&);

  template <class R>
  class Node
  {
    friend class Dlist<R>;
    
    template <class K>
    friend ostream& operator<<(ostream&, Dlist<K>&);
    Node<R>* next;
    Node<R>* prev;
    R* data;
  };
  public:
    Dlist();
    ~Dlist();
    void cleanup();

    // Overloaded operators
    Dlist<T>& operator+=(T*);
    Dlist<T>& operator+=(Dlist<T>&);
    Dlist<T>& operator-=(T*);
    Dlist<T>& operator-=(Dlist<T>&);

    int getSize();

    void           deleteCourse(T*);
      /* Purpose: Delete course from list         */
      /*   Input: Pointer to Course to delete     */

    T*               getCourse(int);
      /* Purpose: Find course of array index      */
      /*   Input: Index of desired course         */
      /*  Output: Pointer to correct course       */

    T*      getCourseFromID(string); 
      /* Purpose: Find course corresponding to ID */
      /*   Input: Course code                     */
      /*  Output: Pointer to correct course       */
      /*          (or null of not found)          */

    void                    add(T*);
      /* Purpose: Add a course to the array       */
      /*   Input: Pointer of course to add        */

    string            toStringFwd();
      /* Purpose: Return a string containing      */
      /*          information on all courses      */
      /*          printed forwards.               */
      /*  Output: Formatted string of course info */

    string            toStringBwd();
      /* Purpose: Return a string containing      */
      /*          information on all courses      */
      /*          printed backwards.              */
      /*  Output: Formatted string of course info */

  private:
    int size;
    Node<T>* head;

};

template <class T>
Dlist<T>::Dlist() : head(0), size(0){};

template <class T>
Dlist<T>::~Dlist()
// Remember to run cleanup() first if data needs removing
{
  Node<T>* currNode = head;
  Node<T>* nextNode;

  while (currNode != 0){
    nextNode = currNode->next;
    //delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
void Dlist<T>::cleanup()
// Full cleanup of nodes and data
{
  Node<T>* currNode = head;
  Node<T>* nextNode;

  while (currNode != 0){
    nextNode = currNode->next;
    delete currNode->data;
    currNode = nextNode;
  }
}

// Overloaded Operators
template <class T>
ostream& operator<<(ostream& out, Dlist<T>& list)
{
  out << list.toStringFwd() << endl << list.toStringBwd() << endl;
  return out;
}

template <class T>
Dlist<T>& Dlist<T>::operator+=(T* data)
{
  add(data);
  return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator+=(Dlist<T>& list2)
{
  Node<T>* currNode;
  currNode = list2.head;
  while (currNode != NULL)
  {
    add(currNode->data);
    currNode = currNode->next;
  }
  return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator-=(T* data)
{
  deleteCourse(data);
  return *this;
}

template <class T>
Dlist<T>& Dlist<T>::operator-=(Dlist<T>& list2)
{
  Node<T>* currNode;
  currNode = list2.head;
  while (currNode != NULL)
  {
    deleteCourse(currNode->data);
    currNode = currNode->next;
  }
  return *this;
}

template <class T>
string Dlist<T>::toStringFwd()
/* NOTE: MUST BE OVERLOADED FOR ANYTHING THAT IS NOT A COURSE */
{
  Node<T>* currNode = head;
  string returnString;
  stringstream ss;
  ss << "Printing forwards (Alphabetically)\n";
  while (currNode != 0){
    string currdat = "";
    T* c = currNode->data;
    ss << "Course:     " << c->getCode() << " " << c->getName() << "\n";
    ss << "Instructor: " << c->getInstr() << "\n";
    ss << "Enrolment:  " << c->getEnrol() << "\n";
    ss << "# of textbooks: " << c->getNumBooks() << "\n   -----\n";
    currNode = currNode->next;
  }
  returnString = ss.str();
  return returnString;
}

template <class T>
string Dlist<T>::toStringBwd()
/* NOTE: MUST BE OVERLOADED FOR ANYTHING THAT IS NOT A COURSE */
{
  Node<T>* currNode = head;
  // Walk to the end of the list first
  while (currNode != 0){
    if (currNode->next == 0)
      break;
    currNode = currNode->next;
  }
  string returnString;
  stringstream ss;
  ss << "Printing backwards (Alphabetically)\n";
  while (currNode != 0){
    string currdat = "";
    T* c = currNode->data;
    ss << "Course:         " << c->getCode() << " " << c->getName() << "\n";
    ss << "Instructor:     " << c->getInstr() << "\n";
    ss << "Enrolment:      " << c->getEnrol() << "\n";
    ss << "# of textbooks: " << c->getNumBooks() << "\n   -----\n";
    currNode = currNode->prev;
  }
  returnString = ss.str();
  return returnString;
}

template <class T>
void Dlist<T>::deleteCourse(T* dat) // change name
{
  Node<T>* currNode = head;
  Node<T>* prevNode = 0;

  if (currNode == 0){ 
    // List is empty
    return;
  }
  while (currNode != 0){
    if (currNode->data == dat){
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  if (currNode == 0){
    // Element was not found
    return;
  }
  if (prevNode == 0){
    // Remove first element
    if (currNode->next == 0){
      // This is the only element in the list
      delete currNode->data;
      delete currNode;
      head = 0;
      size--;
      return;
    }
    // There is more than one element
    head = currNode->next;
    delete currNode->data;
    delete currNode;
    head->prev = 0;
    size--;
    return;
  }
  if (currNode->next == 0){
    // Remove last element in list
    delete currNode->data;
    delete currNode;
    prevNode->next = 0;
    size--;
    return;
  }
  if (prevNode != 0){
    // Remove from middle of list
    delete currNode->data;
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    delete currNode;
  }
  
}

template <class T>
void Dlist<T>::add(T* dat)
/* Object must have some sort of getCode() for ordering. Check back at forum */
{
  // Set up the new node
  Node<T>* tmpNode = new Node<T>();
  tmpNode->data = dat;
  tmpNode->next = 0;
  tmpNode->prev = 0;

  Node<T>* currNode;
  Node<T>* prevNode;

  currNode = head;
  prevNode = 0;

  if (currNode == 0){ 
    // List is empty
    head = tmpNode;
    size++;
    return;
  }
  while (currNode != 0) {
    if ((currNode->data)->getCode() > (tmpNode->data)->getCode()) {
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  } // At correct position

  if (prevNode == 0){ 
    // Insert at start of list
    tmpNode->next = head;
    head->prev = tmpNode;
    head = tmpNode;
    size++;
    return;
  }
  if (currNode == 0){ 
    // Insert at end of list
    prevNode->next = tmpNode;
    tmpNode->prev = prevNode;
    size++;
    return;
  }
  if (prevNode != 0){ 
    // Insert in middle of list
    tmpNode->next = currNode;
    tmpNode->prev = prevNode;
    prevNode->next = tmpNode;
    currNode->prev = tmpNode;
    size++;
    return;
  }
}

template <class T>
int Dlist<T>::getSize(){ return size; }

template <class T>
T* Dlist<T>::getCourse(int i) // change name of this
{
  int o = 0;
  Node<T>* currNode = head;
  while (currNode != 0){
    if (o == i){
      return currNode->data;
    }
    currNode = currNode->next;
    o++;
  }
  return 0; // Something went wrong.
}

template <class T>
T* Dlist<T>::getCourseFromID(string id)
{
  Node<T>* currNode = head;
  while (currNode != 0){
    if ((currNode->data)->getCode() == id){
      return currNode->data;
    }
    currNode = currNode->next;
  }
  return 0; // Course was not found
}
#endif
