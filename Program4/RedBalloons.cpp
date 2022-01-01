#include "RedBalloons.h"
#include "MyObject.h"
#include <cstdlib>// allows use of rand()

void RedBalloons::Move()
{
   if (MyObject::IsPopped() == false)
   {
      y -= 30;
      if (y + image->Height <= 0)
      {
         y = panel->Height;
         x = rand() % ((panel->Width - image->Width) - 150) + 100;
      }
   }
}

int RedBalloons::popScore()
{
   return scores;
}

int RedBalloons::typeOfObject()
{
   return type;
}
