// 
// YellowBalloons is a abstract class for YellowBalloons
// 
#pragma once		// This is instead of the "#ifndef guard"

#include <cstddef>	// including for nullptr declaration

// Needed for gcroot declaration: allow use of GC class in non-GC class
#include <vcclr.h>   
#include "MyObject.h"

class YellowBalloons : public MyObject{
public:
   //constructor
   YellowBalloons(int startX, int startY, Panel^ drawingPanel, TextBox^ inScore) : MyObject(startX, startY, drawingPanel, inScore)
   {
      scores = 50;
      image = gcnew Drawing::Bitmap("yellowBalloon.bmp");
      Color backColor = image->GetPixel(1, 1);
      image->MakeTransparent(backColor);
      type = 2;
   }

   //destructor
   ~YellowBalloons() { delete image; }

   // moves yellow balloon object
   void Move();

   // yellow balloon pop score of 25
   int popScore();

   // yello balloon type object
   int typeOfObject();

};