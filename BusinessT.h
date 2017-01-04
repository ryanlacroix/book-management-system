#ifndef BUSINESST_H
#define BUSINESST_H

#include <string>
#include "Tutor.h"

class BusinessT : public Tutor
{
  public:
    BusinessT(string);
   ~BusinessT();
    virtual void tutorBio(string&);
};

#endif
