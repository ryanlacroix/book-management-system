#ifndef PRODUCT_H
#define PRODUCT_H

class Product
// Base class for different kinds of products to be stored.
{
  public:
    Product(float, int);
    virtual ~Product();

    float getPrice();
    int      getID();

  protected:
    // blank for now
    float price;
    int id;
};

#endif
