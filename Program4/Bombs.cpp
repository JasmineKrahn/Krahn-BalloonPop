#include "MyObject.h"
#include "Bombs.h"

void Bombs::Move()
{
   if (MyObject::IsPopped() == false)
   {
      x += 20;
      if (x + image->Width >= panel->Width)
      {
         x = 50;
      }
   }
}

int Bombs::popScore()
{
   return scores;
}

int Bombs::typeOfObject()
{
   return type;
}
