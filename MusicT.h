#ifndef MUSICT_H
#define MUSICT_H

#include <string>
#include "Tutor.h"

class MusicT : public Tutor
{
  public:
    MusicT(string);
   ~MusicT();
    virtual void tutorBio(string&);
};

#endif
