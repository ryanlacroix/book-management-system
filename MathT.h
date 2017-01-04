#ifndef MATHT_H
#define MATHT_H

#include <string>
#include "Tutor.h"

class MathT : public Tutor
{
  public:
    MathT(string);
   ~MathT();
    virtual void tutorBio(string&);
};

#endif
