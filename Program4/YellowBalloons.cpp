#include "YellowBalloons.h"
#include "MyObject.h"
#include <cstdlib> // allows use of rand()

void YellowBalloons::Move()
{
   if (MyObject::IsPopped() == false)
   {
      y -= 15;
      if (y + image->Height <= 0)
      {
         y = panel->Height;
         x = rand() % ((panel->Width - image->Width) - 150) + 100;
      }
   }
}

int YellowBalloons::popScore()
{
   return scores;
}

int YellowBalloons::typeOfObject()
{
   return type;
}
