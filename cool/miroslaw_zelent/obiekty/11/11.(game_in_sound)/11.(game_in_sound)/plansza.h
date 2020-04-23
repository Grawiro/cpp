#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>
#include <string>

int liczby[200];

int ktora = 0;
int licznik = 0;

bool gra_rozpoczeta = false;

namespace My11gameinsound {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for plansza
	/// </summary>
	public ref class plansza : public System::Windows::Forms::Form
	{
	public:
		plansza(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~plansza()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  tlo;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  z1;
	private: System::Windows::Forms::PictureBox^  z2;
	private: System::Windows::Forms::PictureBox^  z3;
	private: System::Windows::Forms::PictureBox^  z4;
	private: System::Windows::Forms::PictureBox^  z5;
	private: System::Windows::Forms::PictureBox^  z1a;
	private: System::Windows::Forms::PictureBox^  z2a;
	private: System::Windows::Forms::PictureBox^  z3a;
	private: System::Windows::Forms::PictureBox^  z4a;
	private: System::Windows::Forms::PictureBox^  z5a;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager (plansza::typeid));
			this->tlo = (gcnew System::Windows::Forms::PictureBox ());
			this->label1 = (gcnew System::Windows::Forms::Label ());
			this->z1 = (gcnew System::Windows::Forms::PictureBox ());
			this->z2 = (gcnew System::Windows::Forms::PictureBox ());
			this->z3 = (gcnew System::Windows::Forms::PictureBox ());
			this->z4 = (gcnew System::Windows::Forms::PictureBox ());
			this->z5 = (gcnew System::Windows::Forms::PictureBox ());
			this->z1a = (gcnew System::Windows::Forms::PictureBox ());
			this->z2a = (gcnew System::Windows::Forms::PictureBox ());
			this->z3a = (gcnew System::Windows::Forms::PictureBox ());
			this->z4a = (gcnew System::Windows::Forms::PictureBox ());
			this->z5a = (gcnew System::Windows::Forms::PictureBox ());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tlo))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z1))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z2))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z3))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z4))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z5))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z1a))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z2a))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z3a))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z4a))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z5a))->BeginInit ();
			this->SuspendLayout ();
			// 
			// tlo
			// 
			this->tlo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"tlo.Image")));
			this->tlo->Location = System::Drawing::Point (0, 0);
			this->tlo->Name = L"tlo";
			this->tlo->Size = System::Drawing::Size (799, 534);
			this->tlo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->tlo->TabIndex = 0;
			this->tlo->TabStop = false;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label1->Font = (gcnew System::Drawing::Font (L"Comic Sans MS", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point (81, 425);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size (616, 88);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Rozpocznij Gre";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler (this, &plansza::label1_Click);
			// 
			// z1
			// 
			this->z1->BackColor = System::Drawing::Color::Transparent;
			this->z1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->z1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z1.Image")));
			this->z1->Location = System::Drawing::Point (114, 183);
			this->z1->Name = L"z1";
			this->z1->Size = System::Drawing::Size (81, 123);
			this->z1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z1->TabIndex = 2;
			this->z1->TabStop = false;
			this->z1->Click += gcnew System::EventHandler (this, &plansza::z1_Click);
			this->z1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z1_MouseDown);
			this->z1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z1_MouseUp);
			// 
			// z2
			// 
			this->z2->BackColor = System::Drawing::Color::Transparent;
			this->z2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->z2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z2.Image")));
			this->z2->Location = System::Drawing::Point (239, 183);
			this->z2->Name = L"z2";
			this->z2->Size = System::Drawing::Size (81, 123);
			this->z2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z2->TabIndex = 2;
			this->z2->TabStop = false;
			this->z2->Click += gcnew System::EventHandler (this, &plansza::z2_Click);
			this->z2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z2_MouseDown);
			this->z2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z2_MouseUp);
			// 
			// z3
			// 
			this->z3->BackColor = System::Drawing::Color::Transparent;
			this->z3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->z3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z3.Image")));
			this->z3->Location = System::Drawing::Point (359, 183);
			this->z3->Name = L"z3";
			this->z3->Size = System::Drawing::Size (81, 123);
			this->z3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z3->TabIndex = 2;
			this->z3->TabStop = false;
			this->z3->Click += gcnew System::EventHandler (this, &plansza::z3_Click);
			this->z3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z3_MouseDown);
			this->z3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z3_MouseUp);
			// 
			// z4
			// 
			this->z4->BackColor = System::Drawing::Color::Transparent;
			this->z4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->z4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z4.Image")));
			this->z4->Location = System::Drawing::Point (475, 183);
			this->z4->Name = L"z4";
			this->z4->Size = System::Drawing::Size (81, 123);
			this->z4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z4->TabIndex = 2;
			this->z4->TabStop = false;
			this->z4->Click += gcnew System::EventHandler (this, &plansza::z4_Click);
			this->z4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z4_MouseDown);
			this->z4->MouseUp += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z4_MouseUp);
			// 
			// z5
			// 
			this->z5->BackColor = System::Drawing::Color::Transparent;
			this->z5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->z5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z5.Image")));
			this->z5->Location = System::Drawing::Point (587, 183);
			this->z5->Name = L"z5";
			this->z5->Size = System::Drawing::Size (81, 123);
			this->z5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z5->TabIndex = 2;
			this->z5->TabStop = false;
			this->z5->Click += gcnew System::EventHandler (this, &plansza::z5_Click);
			this->z5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z5_MouseDown);
			this->z5->MouseUp += gcnew System::Windows::Forms::MouseEventHandler (this, &plansza::z5_MouseUp);
			// 
			// z1a
			// 
			this->z1a->BackColor = System::Drawing::Color::Transparent;
			this->z1a->Cursor = System::Windows::Forms::Cursors::Default;
			this->z1a->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z1a.Image")));
			this->z1a->Location = System::Drawing::Point (114, 183);
			this->z1a->Name = L"z1a";
			this->z1a->Size = System::Drawing::Size (81, 123);
			this->z1a->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z1a->TabIndex = 2;
			this->z1a->TabStop = false;
			// 
			// z2a
			// 
			this->z2a->BackColor = System::Drawing::Color::Transparent;
			this->z2a->Cursor = System::Windows::Forms::Cursors::Default;
			this->z2a->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z2a.Image")));
			this->z2a->Location = System::Drawing::Point (239, 183);
			this->z2a->Name = L"z2a";
			this->z2a->Size = System::Drawing::Size (81, 123);
			this->z2a->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z2a->TabIndex = 2;
			this->z2a->TabStop = false;
			// 
			// z3a
			// 
			this->z3a->BackColor = System::Drawing::Color::Transparent;
			this->z3a->Cursor = System::Windows::Forms::Cursors::Default;
			this->z3a->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z3a.Image")));
			this->z3a->Location = System::Drawing::Point (359, 183);
			this->z3a->Name = L"z3a";
			this->z3a->Size = System::Drawing::Size (81, 123);
			this->z3a->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z3a->TabIndex = 2;
			this->z3a->TabStop = false;
			// 
			// z4a
			// 
			this->z4a->BackColor = System::Drawing::Color::Transparent;
			this->z4a->Cursor = System::Windows::Forms::Cursors::Default;
			this->z4a->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z4a.Image")));
			this->z4a->Location = System::Drawing::Point (475, 183);
			this->z4a->Name = L"z4a";
			this->z4a->Size = System::Drawing::Size (81, 123);
			this->z4a->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z4a->TabIndex = 2;
			this->z4a->TabStop = false;
			// 
			// z5a
			// 
			this->z5a->BackColor = System::Drawing::Color::Transparent;
			this->z5a->Cursor = System::Windows::Forms::Cursors::Default;
			this->z5a->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"z5a.Image")));
			this->z5a->Location = System::Drawing::Point (587, 183);
			this->z5a->Name = L"z5a";
			this->z5a->Size = System::Drawing::Size (81, 123);
			this->z5a->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->z5a->TabIndex = 2;
			this->z5a->TabStop = false;
			// 
			// plansza
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size (799, 534);
			this->Controls->Add (this->z5a);
			this->Controls->Add (this->z4a);
			this->Controls->Add (this->z3a);
			this->Controls->Add (this->z2a);
			this->Controls->Add (this->z1a);
			this->Controls->Add (this->z5);
			this->Controls->Add (this->z4);
			this->Controls->Add (this->z3);
			this->Controls->Add (this->z2);
			this->Controls->Add (this->z1);
			this->Controls->Add (this->label1);
			this->Controls->Add (this->tlo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject (L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"plansza";
			this->Text = L"Game in Sound";
			this->Load += gcnew System::EventHandler (this, &plansza::plansza_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tlo))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z1))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z2))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z3))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z4))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z5))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z1a))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z2a))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z3a))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z4a))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->z5a))->EndInit ();
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
			public:
				void losuj () {
					for (int i = 0; i < 200; i++) {
						liczby[i] = rand () % 5 + 1;
					}
					for (int i = 0; i < 200; i++) {
						liczby[i] = rand () % 5 + 1;
					}
					for (int i = 0; i < 200; i++) {
						liczby[i] = rand () % 5 + 1;
					}
				}

		void sekwecja () {
			z1->Load ("img/p1.png");
			z2->Load ("img/p2.png");
			z3->Load ("img/p3.png");
			z4->Load ("img/p4.png");
			z5->Load ("img/p5.png");


			Application::DoEvents ();
			Sleep (1000);

			z1->Enabled = false;
			z2->Enabled = false;
			z3->Enabled = false;
			z4->Enabled = false;
			z5->Enabled = false;

			label1->Text = "Nastepna runda za 2";
			Application::DoEvents ();
			Sleep (1000);
			label1->Text = "Nastepna runda za 1";
			Application::DoEvents ();
			Sleep (1000);
			label1->Text = "Zapamietaj sekwecje";
			Application::DoEvents ();
			Sleep (1000);

			ktora++;

			for (int i = 0; i < ktora; i++) {
				switch (liczby[i])
				{
				case 1:
				{
					sndPlaySound (TEXT ("snd/d1.wav"), SND_ASYNC);
					z1a->Visible = true;
					z1->Visible = false;
					break;
				}
				case 2:
				{
					sndPlaySound (TEXT ("snd/d2.wav"), SND_ASYNC);
					z2a->Visible = true;
					z2->Visible = false;
					break;
				}
				case 3:
				{
					sndPlaySound (TEXT ("snd/d3.wav"), SND_ASYNC);
					z3a->Visible = true;
					z3->Visible = false;
					break;
				}
				case 4:
				{
					sndPlaySound (TEXT ("snd/d4.wav"), SND_ASYNC);
					z4a->Visible = true;
					z4->Visible = false;
					break;
				}
				case 5:
				{
					sndPlaySound (TEXT ("snd/d5.wav"), SND_ASYNC);
					z5a->Visible = true;
					z5->Visible = false;
					break;
				}
				}
				Application::DoEvents ();
				Sleep (1200);

				z1->Visible = true;
				z2->Visible = true;
				z3->Visible = true;
				z4->Visible = true;
				z5->Visible = true;

				z1a->Visible = false;
				z2a->Visible = false;
				z3a->Visible = false;
				z4a->Visible = false;
				z5a->Visible = false;
				Application::DoEvents ();
				Sleep (100);
			}

			z1->Enabled = true;
			z2->Enabled = true;
			z3->Enabled = true;
			z4->Enabled = true;
			z5->Enabled = true;

			licznik = 0;

			label1->Text = "Powtorz sekwecje";

		}
#pragma endregion
	private: System::Void plansza_Load (System::Object^  sender, System::EventArgs^  e) {
		label1->Parent = tlo;
		label1->BackColor = Color::Transparent;

		z1->Parent = tlo;
		z1->BackColor = Color::Transparent;
		z2->Parent = tlo;
		z2->BackColor = Color::Transparent;
		z3->Parent = tlo;
		z3->BackColor = Color::Transparent;
		z4->Parent = tlo;
		z4->BackColor = Color::Transparent;
		z5->Parent = tlo;
		z5->BackColor = Color::Transparent;

		z1a->Parent = tlo;
		z1a->BackColor = Color::Transparent;
		z2a->Parent = tlo;
		z2a->BackColor = Color::Transparent;
		z3a->Parent = tlo;
		z3a->BackColor = Color::Transparent;
		z4a->Parent = tlo;
		z4a->BackColor = Color::Transparent;
		z5a->Parent = tlo;
		z5a->BackColor = Color::Transparent;

		z1a->Visible = false;
		z2a->Visible = false;
		z3a->Visible = false;
		z4a->Visible = false;
		z5a->Visible = false;



		srand (time (NULL));
		losuj ();
	}



private: System::Void label1_Click (System::Object^  sender, System::EventArgs^  e) {
	if (gra_rozpoczeta == false)
	{
		gra_rozpoczeta = true;
		sndPlaySound (TEXT ("snd/start.wav"), SND_ASYNC);
		sekwecja ();
	}
}
private: System::Void z1_Click (System::Object^  sender, System::EventArgs^  e) {
	if (gra_rozpoczeta == true)
	{
		licznik++;
		if (liczby[licznik-1] != 1) {
			ktora--;
			std::string ktory = std::to_string (ktora);
			String^ ile = gcnew String (ktory.c_str ());
			label1->Text = "Skucha! Twoj wynik: "+ile;
			sndPlaySound (TEXT ("snd/koniec.wav"), SND_ASYNC);
			gra_rozpoczeta = false;
			ktora = 0;
			losuj ();
		}
		if (licznik == ktora) {
			label1->Text = "Doskonale";
			sekwecja ();
		}
	}
}
private: System::Void z2_Click (System::Object^  sender, System::EventArgs^  e) {
	if (gra_rozpoczeta == true)
	{
		licznik++;
		if (liczby[licznik - 1] != 2) {
			ktora--;
			std::string ktory = std::to_string (ktora);
			String^ ile = gcnew String (ktory.c_str ());
			label1->Text = "Skucha! Twoj wynik: " + ile;
			sndPlaySound (TEXT ("snd/koniec.wav"), SND_ASYNC);
			gra_rozpoczeta = false;
			ktora = 0;
			losuj ();
		}
		if (licznik == ktora) {
			label1->Text = "Doskonale";
			sekwecja ();
		}
	}
}
private: System::Void z3_Click (System::Object^  sender, System::EventArgs^  e) {
	if (gra_rozpoczeta == true)
	{
		licznik++;
		if (liczby[licznik - 1] != 3) {
			ktora--;
			std::string ktory = std::to_string (ktora);
			String^ ile = gcnew String (ktory.c_str ());
			label1->Text = "Skucha! Twoj wynik: " + ile;
			sndPlaySound (TEXT ("snd/koniec.wav"), SND_ASYNC);
			gra_rozpoczeta = false;
			ktora = 0;
			losuj ();
		}
		if (licznik == ktora) {
			label1->Text = "Doskonale";
			sekwecja ();
		}
	}
}
private: System::Void z4_Click (System::Object^  sender, System::EventArgs^  e) {
	if (gra_rozpoczeta == true)
	{
		licznik++;
		if (liczby[licznik - 1] != 4) {
			ktora--;
			std::string ktory = std::to_string (ktora);
			String^ ile = gcnew String (ktory.c_str ());
			label1->Text = "Skucha! Twoj wynik: " + ile;
			sndPlaySound (TEXT ("snd/koniec.wav"), SND_ASYNC);
			gra_rozpoczeta = false;
			ktora = 0;
			losuj ();
		}
		if (licznik == ktora) {
			label1->Text = "Doskonale";
			sekwecja ();
		}
	}
}
private: System::Void z5_Click (System::Object^  sender, System::EventArgs^  e) {
	if (gra_rozpoczeta == true)
	{
		licznik++;
		if (liczby[licznik - 1] != 5) {
			ktora--;
			std::string ktory = std::to_string (ktora);
			String^ ile = gcnew String (ktory.c_str ());
			label1->Text = "Skucha! Twoj wynik: " + ile;
			sndPlaySound (TEXT ("snd/koniec.wav"), SND_ASYNC);
			gra_rozpoczeta = false;
			ktora = 0;
			losuj ();
		}
		if (licznik == ktora) {
			label1->Text = "Doskonale";
			sekwecja ();
		}
	}
}
private: System::Void z1_MouseDown (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z1->Load ("img/p1a.png");
	sndPlaySound (TEXT ("snd/d1.wav"), SND_ASYNC);
}
private: System::Void z1_MouseUp (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z1->Load ("img/p1.png");
}
private: System::Void z2_MouseDown (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z2->Load ("img/p2a.png");
	sndPlaySound (TEXT ("snd/d2.wav"), SND_ASYNC);
}
private: System::Void z2_MouseUp (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z2->Load ("img/p2.png");
}
private: System::Void z3_MouseDown (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z3->Load ("img/p3a.png");
	sndPlaySound (TEXT ("snd/d3.wav"), SND_ASYNC);
}
private: System::Void z3_MouseUp (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z3->Load ("img/p3.png");
}
private: System::Void z4_MouseDown (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z4->Load ("img/p4a.png");
	sndPlaySound (TEXT ("snd/d4.wav"), SND_ASYNC);
}
private: System::Void z4_MouseUp (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z4->Load ("img/p4.png");
}
private: System::Void z5_MouseDown (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z5->Load ("img/p5a.png");
	sndPlaySound (TEXT ("snd/d5.wav"), SND_ASYNC);
}
private: System::Void z5_MouseUp (System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	z5->Load ("img/p5.png");
}
};
}

