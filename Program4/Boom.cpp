#include "MyObject.h"
#include "Boom.h"

void Boom::Move()
{
   delete image;
}

int Boom::popScore()
{
   return scores;
}

int Boom::typeOfObject()
{
   return type;
}
