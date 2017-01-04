#ifndef GRAPHINGCALC_H
#define GRAPHINGCALC_H

#include <string>
#include "Electronic.h"

class GraphingCalc : public Electronic
// Graphing Calculator product.
{
  public:
    GraphingCalc(float, int, bool, int);
    virtual ~GraphingCalc();
  private:
    bool colourScreen;
    int memory;
};

#endif


