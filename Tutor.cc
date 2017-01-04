#include "Tutor.h"
#include <string>
using namespace std;

Tutor::Tutor(string n)
  : status("Available"), name(n)
{}
Tutor::~Tutor()
{}

void Tutor::bookTutor(string newStatus)
{
  status = newStatus;
}

string Tutor::getStatus() { return status; }
string Tutor::getName()   { return name; }

