#ifndef TUTOR_H
#define TUTOR_H

#include <string>
using namespace std;

class Tutor
{
  public:
    Tutor(string);
   ~Tutor();
    virtual void tutorBio(string&) = 0;
    void bookTutor(string);
    string getStatus();
    string getName();

  protected:
    string status;
    string name;
};

#endif
