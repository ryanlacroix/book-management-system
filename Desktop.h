#ifndef DESKTOP_H
#define DESKTOP_H

#include <string>
#include <iostream>
using namespace std;
#include "Electronic.h"

class Desktop : public Electronic
// Desktop product
{
  public:
    Desktop(float, int, string, float);
    virtual ~Desktop();
  private:
    string size;
    float ampDraw;
};

#endif
