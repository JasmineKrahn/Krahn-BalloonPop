// 
// Bird is a abstract class for Birds.
// 
#pragma once		// This is instead of the "#ifndef guard"

#include <cstddef>	// including for nullptr declaration

// Needed for gcroot declaration: allow use of GC class in non-GC class
#include <vcclr.h>   
#include "MyObject.h"

class Bird : public MyObject {
public:
   //constructor
   Bird(int startX, int startY, Panel^ drawingPanel, TextBox^ inScore) : MyObject(startX, startY, drawingPanel, inScore)
   {
      image = gcnew Drawing::Bitmap("bird.bmp");
      Color backColor = image->GetPixel(1, 1);
      image->MakeTransparent(backColor);
      type = -1;
   }

   //destructor
   ~Bird() { delete image; }

   //Moves a bird object in a random nature
   void Move();

   // no scores because the bird can not be popped
   int popScore();

   // -1 so it cannot be popped
   int typeOfObject();

};