// 
// Boom is a abstract class for booms.
// 
#pragma once		// This is instead of the "#ifndef guard"

#include <cstddef>	// including for nullptr declaration

// Needed for gcroot declaration: allow use of GC class in non-GC class
#include <vcclr.h>   
#include "MyObject.h"

class Boom : public MyObject {
public:
   //constructor
   Boom(int startX, int startY, Panel^ drawingPanel, TextBox^ inScore) : MyObject(startX, startY, drawingPanel, inScore)
   {
      image = gcnew Drawing::Bitmap("boom.bmp");
      Color backColor = image->GetPixel(1, 1);
      image->MakeTransparent(backColor);
      type = 3;
   }

   //destructor
   ~Boom() { delete image; }

   // moves boom object
   void Move();

   // no popping a boom
   int popScore();

   // didnt get to this
   int typeOfObject();

};