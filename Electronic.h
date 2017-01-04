#ifndef ELECTRONIC_H
#define ELECTRONIC_H
#include "Product.h"

class Electronic : public Product
// Superclass for electronic device classes
{
  public:
    Electronic(float p, int i);
    virtual ~Electronic();
  private:
};


#endif
