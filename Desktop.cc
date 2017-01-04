#include <string>
#include <iostream>
using namespace std;

#include "Desktop.h"

Desktop::Desktop(float price, int id, string s, float a)
  :  Electronic(price, id), size(s), ampDraw(a)
{}
Desktop::~Desktop() {}
