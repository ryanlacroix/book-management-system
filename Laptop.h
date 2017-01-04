#ifndef LAPTOP_H
#define LAPTIO_H

#include "Desktop.h"

class Laptop : public Desktop
// Laptop product
{
  public:
    Laptop(float, int, string, float, float, int);
    virtual ~Laptop();

  private:
    float screenWidth;
    int batteryLife;
};

#endif
