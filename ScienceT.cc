#include "ScienceT.h"
#include <string>
using namespace std;

ScienceT::ScienceT(string n)
  : Tutor(n)
{}

void ScienceT::tutorBio(string& bio)
{
  bio = "I am a science tutor! Chemistry, Physics, you name it and I can help out.";
}
