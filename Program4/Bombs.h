// 
// Bombs is a abstract class for bombs.
// 
#pragma once		// This is instead of the "#ifndef guard"

#include <cstddef>	// including for nullptr declaration

// Needed for gcroot declaration: allow use of GC class in non-GC class
#include <vcclr.h>   
#include "MyObject.h"

class Bombs : public MyObject {
public:
   //constructor
   Bombs(int startX, int startY, Panel^ drawingPanel, TextBox^ inScore) : MyObject(startX, startY, drawingPanel, inScore)
   {
      image = gcnew Drawing::Bitmap("bomb.bmp");
      Color backColor = image->GetPixel(1, 1);
      image->MakeTransparent(backColor);
      type = 0;
   }

   //destructor
   ~Bombs() { delete image; }

   // moves a bomb object
   void Move();

   // score for popping a bomb which is -5
   int popScore();

   // type 0 for bomb
   int typeOfObject();

};