#ifndef SCIENCET_H
#define SCIENCET_H

#include <string>
#include "Tutor.h"
using namespace std;

class ScienceT : public Tutor
{
  public:
    ScienceT(string);
   ~ScienceT();
    virtual void tutorBio(string&);
};

#endif
