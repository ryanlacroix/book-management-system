#include "BusinessT.h"

BusinessT::BusinessT(string n)
  : Tutor(n)
{}

void BusinessT::tutorBio(string& bio)
{
  bio = "Business? I practically invented it! I can help out, but don't touch my suit. I just had it dry-cleaned.";
}
