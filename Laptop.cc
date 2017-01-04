#include <string>
using namespace std;
#include "Laptop.h"

Laptop::Laptop(float price, int id, string si, float am, float s, int b)
  :   Desktop(price, id, si, am), screenWidth(s), batteryLife(b)
{}
Laptop::~Laptop() {}
