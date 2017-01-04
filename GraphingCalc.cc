#include "GraphingCalc.h"

GraphingCalc::GraphingCalc(float price, int id, bool c, int m)
  :  Electronic(price, id), colourScreen(c), memory(m)
{}
GraphingCalc::~GraphingCalc() {}
