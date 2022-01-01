// 
// RedBalloons is a abstract class for balloons
// 
#pragma once		// This is instead of the "#ifndef guard"

#include <cstddef>	// including for nullptr declaration

// Needed for gcroot declaration: allow use of GC class in non-GC class
#include <vcclr.h>   
#include "MyObject.h"

class RedBalloons : public MyObject{
public:
   //constructor
   RedBalloons(int startX, int startY, Panel^ drawingPanel, TextBox^ inScore) : MyObject(startX, startY, drawingPanel, inScore)
   {
      scores = 25;
      image = gcnew Drawing::Bitmap("redBalloon.bmp");
      Color backColor = image->GetPixel(1, 1);
      image->MakeTransparent(backColor);
      type = 1;
   }

   //destructor
   ~RedBalloons() { delete image; }

   // moves a red balloon object
   void Move();

   // red balloon pop score of 25
   int popScore();

   // red balloon type
   int typeOfObject();

};