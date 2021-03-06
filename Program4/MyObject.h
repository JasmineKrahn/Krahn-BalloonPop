// 
// given
// MyObject is a abstract base class for balloons and bombs.
// 
#pragma once		// This is instead of the "#ifndef guard"

#include <cstddef>	// including for nullptr declaration

// Needed for gcroot declaration: allow use of GC class in non-GC class
#include <vcclr.h>   

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

// Allows the double buffer to be accessed as public
public ref class MyPanel : public System::Windows::Forms::Panel
{
public:
	void SetStyle(System::Windows::Forms::ControlStyles flag, System::Boolean value)
	{
		System::Windows::Forms::Control::SetStyle(flag, value);
		UpdateStyles();
	}
};

class MyObject
{
public:
	// constructor
	// purposely not using : initialization to include a comment about each variable setting
	MyObject(int startX, int startY, Panel^ drawingPanel, TextBox^ inScore)
	{
		x = startX;				// starting x coordinate of object's image (upper-left)
		y = startY;				// starting y coordinate of object's image (upper-left)
		panel = drawingPanel;	// panel from main form we are drawing on
		scores = 100;			// just a positive integer to indicate "balloon" hasn't popped
		image = nullptr;		// image pointer to what we want to draw for this object
		score = inScore;		// this is the main form's score text box
								// *making use of data coupling to avoid global variable (common coupling = bad)
	}
	
	// destructor
	virtual ~MyObject() { }

	// virtual function for different movements of objects
	// You MUST implement this function separately in each object
	virtual void Move() = 0;

	// virtual function for different scores of balloon (technically, for a bomb as well)
	// You MUST implement this function separately in each object
	virtual int popScore() = 0;

	// virtual function to specify the type of object 
	// (It may help to distinguish different types of balloons and bombs
	//  you may remove it based on your logic)
	virtual int typeOfObject() = 0;

	// Returns whether a balloon is popped 
	bool IsPopped() const { return scores <= 0; }
	
	// Shows objects on the screen.
	// You do not need to override this function in all the different objects
	virtual void Show(Graphics^ g);
	
	// Checks if the balloons and bombs collided with one another
	// This function evaluates whether image boundaries are overlapping
	bool CollidedWith(MyObject * b) const;
	
	// Calculates points of object collisions
	// bomb vs bomb = point deduction
	// bomb vs balloon = post increase (according to popScore())
	void setScores(MyObject* b);

protected:
	int x, y;						// Current position of the object (upper-left coordinate)
	gcroot<Drawing::Bitmap^> image;	// Image displayed for the object
	gcroot<Panel^> panel;			// Panel on which to show the object
	int scores;						// positive integer value indicates not popped or exploded
	int type;						// Type of Object - might help identify 
									// ballon vs bomb or extra features
	gcroot<TextBox^> score;			// current overall score from GUI stored in textbox 
};