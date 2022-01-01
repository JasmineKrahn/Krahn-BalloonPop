#include "MyObject.h"
#include "Bird.h"
#include <cstdlib> // allows use of rand()

void Bird::Move()
{
	if (MyObject::IsPopped() == false)
	{
		x += 30;
		y -= 20;
		if (x + image->Width >= panel->Width)
		{
			x = 0;
			y = rand() % ((panel->Height - image->Height) - 150) + 100;
		}
		if (y + image->Height <= 0)
		{
			y = panel->Height;
			x = rand() % ((panel->Width - image->Width) - 150) + 100;
		}
	}
}

int Bird::popScore()
{
   return scores;
}

int Bird::typeOfObject()
{
   return type;
}
