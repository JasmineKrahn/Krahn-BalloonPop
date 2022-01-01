#pragma once
#include "MyObjectList.h"
#include "Bombs.h"
#include "MyObject.h"
#include "RedBalloons.h"
#include "YellowBalloons.h"
#include "Bird.h"
#include <vcclr.h>
#include <fstream>

using namespace std;

namespace Program4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Program4
	/// </summary>
	public ref class Program4 : public System::Windows::Forms::Form
	{
	public:
		Program4(void)
		{
			InitializeComponent();
			static_cast<MyPanel^>(panel1)->SetStyle(ControlStyles::UserPaint, true);
			static_cast<MyPanel^>(panel1)->SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			static_cast<MyPanel^>(panel1)->SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
			objects = new MyObjectList();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Program4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ fireBomb;
	protected:
	private: System::Windows::Forms::Button^ releaseBalloons;
	private: System::Windows::Forms::TextBox^ numberOfBalloons;
	private: System::Windows::Forms::TrackBar^ movementSpeed;
	private: System::Windows::Forms::Timer^ movementTimer;


	private: System::Windows::Forms::TextBox^ scoreText;

	private: System::Windows::Forms::Label^ ScoreLabel;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ restart;
	private: System::Windows::Forms::Label^ highScoreLabel;
	private: System::Windows::Forms::TextBox^ highScoreText;
	private: System::Windows::Forms::Button^ surprise;
	private: System::Windows::Forms::Button^ help;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
	private: MyObjectList* objects;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->fireBomb = (gcnew System::Windows::Forms::Button());
			this->releaseBalloons = (gcnew System::Windows::Forms::Button());
			this->numberOfBalloons = (gcnew System::Windows::Forms::TextBox());
			this->movementSpeed = (gcnew System::Windows::Forms::TrackBar());
			this->movementTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->scoreText = (gcnew System::Windows::Forms::TextBox());
			this->ScoreLabel = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->restart = (gcnew System::Windows::Forms::Button());
			this->highScoreLabel = (gcnew System::Windows::Forms::Label());
			this->highScoreText = (gcnew System::Windows::Forms::TextBox());
			this->surprise = (gcnew System::Windows::Forms::Button());
			this->help = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->movementSpeed))->BeginInit();
			this->SuspendLayout();
			// 
			// fireBomb
			// 
			this->fireBomb->Location = System::Drawing::Point(119, 13);
			this->fireBomb->Name = L"fireBomb";
			this->fireBomb->Size = System::Drawing::Size(106, 49);
			this->fireBomb->TabIndex = 0;
			this->fireBomb->Text = L"Fire Bomb";
			this->fireBomb->UseVisualStyleBackColor = true;
			this->fireBomb->Click += gcnew System::EventHandler(this, &Program4::fireBomb_Click);
			// 
			// releaseBalloons
			// 
			this->releaseBalloons->Location = System::Drawing::Point(13, 39);
			this->releaseBalloons->Name = L"releaseBalloons";
			this->releaseBalloons->Size = System::Drawing::Size(100, 23);
			this->releaseBalloons->TabIndex = 1;
			this->releaseBalloons->Text = L"Release Balloons";
			this->releaseBalloons->UseVisualStyleBackColor = true;
			this->releaseBalloons->Click += gcnew System::EventHandler(this, &Program4::releaseBalloons_Click);
			// 
			// numberOfBalloons
			// 
			this->numberOfBalloons->Location = System::Drawing::Point(13, 13);
			this->numberOfBalloons->MaxLength = 2;
			this->numberOfBalloons->Name = L"numberOfBalloons";
			this->numberOfBalloons->Size = System::Drawing::Size(100, 20);
			this->numberOfBalloons->TabIndex = 2;
			// 
			// movementSpeed
			// 
			this->movementSpeed->LargeChange = 1;
			this->movementSpeed->Location = System::Drawing::Point(254, 17);
			this->movementSpeed->Maximum = 250;
			this->movementSpeed->Minimum = 1;
			this->movementSpeed->Name = L"movementSpeed";
			this->movementSpeed->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->movementSpeed->Size = System::Drawing::Size(104, 45);
			this->movementSpeed->TabIndex = 1;
			this->movementSpeed->TickFrequency = 50;
			this->movementSpeed->Value = 1;
			this->movementSpeed->Scroll += gcnew System::EventHandler(this, &Program4::movementSpeed_Scroll);
			// 
			// movementTimer
			// 
			this->movementTimer->Enabled = true;
			this->movementTimer->Interval = 1;
			this->movementTimer->Tick += gcnew System::EventHandler(this, &Program4::movementTimer_Tick);
			// 
			// scoreText
			// 
			this->scoreText->Location = System::Drawing::Point(455, 14);
			this->scoreText->Name = L"scoreText";
			this->scoreText->ReadOnly = true;
			this->scoreText->Size = System::Drawing::Size(100, 20);
			this->scoreText->TabIndex = 4;
			this->scoreText->Text = L"0";
			// 
			// ScoreLabel
			// 
			this->ScoreLabel->AutoSize = true;
			this->ScoreLabel->Location = System::Drawing::Point(411, 17);
			this->ScoreLabel->Name = L"ScoreLabel";
			this->ScoreLabel->Size = System::Drawing::Size(38, 13);
			this->ScoreLabel->TabIndex = 5;
			this->ScoreLabel->Text = L"Score:";
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 68);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(959, 581);
			this->panel1->TabIndex = 6;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Program4::panel1_Paint);
			// 
			// restart
			// 
			this->restart->Location = System::Drawing::Point(864, 12);
			this->restart->Name = L"restart";
			this->restart->Size = System::Drawing::Size(108, 45);
			this->restart->TabIndex = 7;
			this->restart->Text = L"Restart";
			this->restart->UseVisualStyleBackColor = true;
			this->restart->Click += gcnew System::EventHandler(this, &Program4::restart_Click);
			// 
			// highScoreLabel
			// 
			this->highScoreLabel->AutoSize = true;
			this->highScoreLabel->Location = System::Drawing::Point(386, 44);
			this->highScoreLabel->Name = L"highScoreLabel";
			this->highScoreLabel->Size = System::Drawing::Size(63, 13);
			this->highScoreLabel->TabIndex = 8;
			this->highScoreLabel->Text = L"High Score:";
			// 
			// highScoreText
			// 
			this->highScoreText->Location = System::Drawing::Point(455, 41);
			this->highScoreText->Name = L"highScoreText";
			this->highScoreText->ReadOnly = true;
			this->highScoreText->Size = System::Drawing::Size(100, 20);
			this->highScoreText->TabIndex = 9;
			this->highScoreText->Text = L"0";
			// 
			// surprise
			// 
			this->surprise->Location = System::Drawing::Point(570, 12);
			this->surprise->Name = L"surprise";
			this->surprise->Size = System::Drawing::Size(164, 45);
			this->surprise->TabIndex = 10;
			this->surprise->Text = L"Surprise Item";
			this->surprise->UseVisualStyleBackColor = true;
			this->surprise->Click += gcnew System::EventHandler(this, &Program4::surprise_Click);
			// 
			// help
			// 
			this->help->Location = System::Drawing::Point(740, 12);
			this->help->Name = L"help";
			this->help->Size = System::Drawing::Size(118, 45);
			this->help->TabIndex = 11;
			this->help->Text = L"Help";
			this->help->UseVisualStyleBackColor = true;
			this->help->Click += gcnew System::EventHandler(this, &Program4::help_Click);
			// 
			// Program4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 661);
			this->Controls->Add(this->help);
			this->Controls->Add(this->surprise);
			this->Controls->Add(this->highScoreText);
			this->Controls->Add(this->highScoreLabel);
			this->Controls->Add(this->restart);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->ScoreLabel);
			this->Controls->Add(this->scoreText);
			this->Controls->Add(this->movementSpeed);
			this->Controls->Add(this->numberOfBalloons);
			this->Controls->Add(this->releaseBalloons);
			this->Controls->Add(this->fireBomb);
			this->DoubleBuffered = true;
			this->Name = L"Program4";
			this->Text = L"Program4";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->movementSpeed))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void movementTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (objects != nullptr)
	{
		objects->MoveObjects();
		panel1->Refresh();
		int score = Convert::ToInt32(scoreText->Text);
	}
}
private: System::Void movementSpeed_Scroll(System::Object^ sender, System::EventArgs^ e) {
	movementTimer->Interval = 251 - movementSpeed->Value;
}
private: System::Void fireBomb_Click(System::Object^ sender, System::EventArgs^ e) {
	if (objects != nullptr)
	{
		MyObject* bomb = new Bombs(0, 100, panel1, scoreText);
		objects->Add(bomb);
	}
}
private: System::Void releaseBalloons_Click(System::Object^ sender, System::EventArgs^ e) {
	int num;
	if (this->numberOfBalloons->Text != "")
		num = Convert::ToInt32(numberOfBalloons->Text);
	else
		num = 2;
	for (int i = 0; i < num; i++)
	{
		int startSpot = rand() % panel1->Width;

		if (rand() % 2 == 0)
		{
			MyObject* redBalloon = new RedBalloons(startSpot, panel1->Height, panel1, scoreText);
			objects->Add(redBalloon);
		}
		else
		{
			MyObject* yellowBalloon = new YellowBalloons(startSpot, panel1->Height, panel1, scoreText);
			objects->Add(yellowBalloon);
		}
	}
}
private: System::Void Program4_Closing(Object^, System::ComponentModel::CancelEventArgs^ e)
{
	movementTimer->Enabled = false;
	if (objects != nullptr)
		delete objects;
}
//Extra Stuff: added a button to clear the score as well as the panel inorder to restart the game
//also included a high score so even if they restart the high score is displayed.
private: System::Void restart_Click(System::Object^ sender, System::EventArgs^ e) {
	movementTimer->Enabled = false;
	objects->~MyObjectList();
	objects = new MyObjectList();
	panel1->Refresh();
	if (Convert::ToInt32(scoreText->Text) > Convert::ToInt32(highScoreText->Text))
		highScoreText->Text = scoreText->Text;
	scoreText->Text = "0";
	movementTimer->Enabled = true;
}
//Extra: Unique feature that moves randomly throughout the panel
private: System::Void surprise_Click(System::Object^ sender, System::EventArgs^ e) {
	int startSpot = rand() % panel1->Width;
	MyObject* bird = new Bird(startSpot, panel1->Height, panel1, scoreText);
	objects->Add(bird);
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	objects->ShowObjects(e->Graphics);
}
//Extra:Help message box explaining the game
private: System::Void help_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Hello! Welcome young game palyer. Have you ever wanted to shoot bombs at some " 
		"floating balloons? Nows your chance! In this fun but poorly made game you get to send out bombs "
		"at balloon. The yellow balloon will get you more points. However, dont hit other bombs as your "
		"score will decrease. You are able to enter the number of balloons you wish to release at any given "
		"time. You can also choose the speed at whiich the objects move using the slider provided. You may "
		"choose to reset the game but your high score will be displayed.There's a surprise item "
		"that is just for your confusion.");
}
};
}
