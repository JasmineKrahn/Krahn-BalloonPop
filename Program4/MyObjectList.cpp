#include "MyObjectList.h"
#include "MyObject.h"

MyObjectList::MyObjectList() {}

MyObjectList::~MyObjectList()
{
   for (int i = objectList.size() - 1; i >= 0; i--)
   {
      delete objectList[i];
      objectList.erase(objectList.begin() + i);
   }
}

void MyObjectList::Add(MyObject* val)
{
   objectList.push_back(val);
}

void MyObjectList::Delete()
{
   for (int i = 0; i < objectList.size(); i++)
   {
      if (objectList[i]->IsPopped())
      {
         delete objectList[i];
         objectList.erase(objectList.begin() + i);
      }
   }
}

void MyObjectList::ShowObjects(Graphics^ g)
{
   for (int i = 0; i < objectList.size(); i++)
      objectList[i]->Show(g);
}

void MyObjectList::MoveObjects()
{
   if (objectList.size() != 0)
   {
      for (int i = 0; i < objectList.size(); i++)
         objectList[i]->Move();
   }
   CheckCollision();
}

void MyObjectList::CheckCollision()
{
   for (int i = 0; i < objectList.size(); i++)
   {
      for (int j = i + 1; j < objectList.size(); j++)
      {
         if (objectList[i]->CollidedWith(objectList[j]))
         {
            objectList[i]->setScores(objectList[j]);
         }
      }
   }
   Delete();
}


