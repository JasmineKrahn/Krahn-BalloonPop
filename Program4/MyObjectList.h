#pragma once
//holds all elements displayed on the panel
#include <vcclr.h>
#include <vector>
#include "MyObject.h"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class MyObjectList
{
private:
   vector<MyObject*> objectList;
public:
   // constructor
   MyObjectList();

   // Destructor
   ~MyObjectList();

   // adds an object to object list
   void Add(MyObject* val);

   // deletes object from object list
   void Delete();

   // shows all objects in object list on panel
   void ShowObjects(Graphics^ g);

   // moves all objects currently on panel and in object list
   void MoveObjects();

   // checks if 2 obbjects have collided with each other and updates score
   void CheckCollision();
};
