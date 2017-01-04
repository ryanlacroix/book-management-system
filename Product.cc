#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

Product::Product(float p, int i) 
  :  price(p), id(i)
{}
Product::~Product() {}

float Product::getPrice() { return price; }
int         Product::getID() { return id; }
