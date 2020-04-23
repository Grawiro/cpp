#pragma once

char pole1, pole2, pole3, pole4, pole5, pole6, pole7, pole8, pole9, kto;

namespace My9TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for tic_tac_toe
	/// </summary>
	public ref class tic_tac_toe : public System::Windows::Forms::Form
	{
	public:
		tic_tac_toe(void)
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
		~tic_tac_toe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  odNowa;
	private: System::Windows::Forms::PictureBox^  p1;
	private: System::Windows::Forms::PictureBox^  p2;
	private: System::Windows::Forms::PictureBox^  p3;
	private: System::Windows::Forms::PictureBox^  p4;
	private: System::Windows::Forms::PictureBox^  p6;
	private: System::Windows::Forms::PictureBox^  p7;
	private: System::Windows::Forms::PictureBox^  p9;
	private: System::Windows::Forms::PictureBox^  p5;
	private: System::Windows::Forms::PictureBox^  p8;
	private: System::Windows::Forms::Label^  tur;
	private: System::Windows::Forms::PictureBox^  tura;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager (tic_tac_toe::typeid));
			this->odNowa = (gcnew System::Windows::Forms::Button ());
			this->p1 = (gcnew System::Windows::Forms::PictureBox ());
			this->p2 = (gcnew System::Windows::Forms::PictureBox ());
			this->p3 = (gcnew System::Windows::Forms::PictureBox ());
			this->p4 = (gcnew System::Windows::Forms::PictureBox ());
			this->p6 = (gcnew System::Windows::Forms::PictureBox ());
			this->p7 = (gcnew System::Windows::Forms::PictureBox ());
			this->p9 = (gcnew System::Windows::Forms::PictureBox ());
			this->p5 = (gcnew System::Windows::Forms::PictureBox ());
			this->p8 = (gcnew System::Windows::Forms::PictureBox ());
			this->tur = (gcnew System::Windows::Forms::Label ());
			this->tura = (gcnew System::Windows::Forms::PictureBox ());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p3))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p4))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p6))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p7))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p9))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p5))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p8))->BeginInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tura))->BeginInit ();
			this->SuspendLayout ();
			// 
			// odNowa
			// 
			this->odNowa->Font = (gcnew System::Drawing::Font (L"Rockwell Extra Bold", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->odNowa->Location = System::Drawing::Point (343, 192);
			this->odNowa->Name = L"odNowa";
			this->odNowa->Size = System::Drawing::Size (243, 84);
			this->odNowa->TabIndex = 0;
			this->odNowa->Text = L"Od Nowa";
			this->odNowa->UseVisualStyleBackColor = true;
			this->odNowa->Click += gcnew System::EventHandler (this, &tic_tac_toe::tic_tac_toe_Load);
			// 
			// p1
			// 
			this->p1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p1.Image")));
			this->p1->Location = System::Drawing::Point (13, 13);
			this->p1->Name = L"p1";
			this->p1->Size = System::Drawing::Size (100, 100);
			this->p1->TabIndex = 1;
			this->p1->TabStop = false;
			this->p1->Click += gcnew System::EventHandler (this, &tic_tac_toe::p1_Click);
			// 
			// p2
			// 
			this->p2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p2.Image")));
			this->p2->Location = System::Drawing::Point (119, 13);
			this->p2->Name = L"p2";
			this->p2->Size = System::Drawing::Size (100, 100);
			this->p2->TabIndex = 1;
			this->p2->TabStop = false;
			this->p2->Click += gcnew System::EventHandler (this, &tic_tac_toe::p2_Click);
			// 
			// p3
			// 
			this->p3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p3.Image")));
			this->p3->Location = System::Drawing::Point (225, 12);
			this->p3->Name = L"p3";
			this->p3->Size = System::Drawing::Size (100, 100);
			this->p3->TabIndex = 1;
			this->p3->TabStop = false;
			this->p3->Click += gcnew System::EventHandler (this, &tic_tac_toe::p3_Click);
			// 
			// p4
			// 
			this->p4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p4.Image")));
			this->p4->Location = System::Drawing::Point (13, 119);
			this->p4->Name = L"p4";
			this->p4->Size = System::Drawing::Size (100, 100);
			this->p4->TabIndex = 1;
			this->p4->TabStop = false;
			this->p4->Click += gcnew System::EventHandler (this, &tic_tac_toe::p4_Click);
			// 
			// p6
			// 
			this->p6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p6.Image")));
			this->p6->Location = System::Drawing::Point (225, 118);
			this->p6->Name = L"p6";
			this->p6->Size = System::Drawing::Size (100, 100);
			this->p6->TabIndex = 1;
			this->p6->TabStop = false;
			this->p6->Click += gcnew System::EventHandler (this, &tic_tac_toe::p6_Click);
			// 
			// p7
			// 
			this->p7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p7.Image")));
			this->p7->Location = System::Drawing::Point (13, 225);
			this->p7->Name = L"p7";
			this->p7->Size = System::Drawing::Size (100, 100);
			this->p7->TabIndex = 1;
			this->p7->TabStop = false;
			this->p7->Click += gcnew System::EventHandler (this, &tic_tac_toe::p7_Click);
			// 
			// p9
			// 
			this->p9->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p9.Image")));
			this->p9->Location = System::Drawing::Point (225, 224);
			this->p9->Name = L"p9";
			this->p9->Size = System::Drawing::Size (100, 100);
			this->p9->TabIndex = 1;
			this->p9->TabStop = false;
			this->p9->Click += gcnew System::EventHandler (this, &tic_tac_toe::p9_Click);
			// 
			// p5
			// 
			this->p5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p5.Image")));
			this->p5->Location = System::Drawing::Point (119, 118);
			this->p5->Name = L"p5";
			this->p5->Size = System::Drawing::Size (100, 100);
			this->p5->TabIndex = 1;
			this->p5->TabStop = false;
			this->p5->Click += gcnew System::EventHandler (this, &tic_tac_toe::p5_Click);
			// 
			// p8
			// 
			this->p8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->p8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"p8.Image")));
			this->p8->Location = System::Drawing::Point (119, 224);
			this->p8->Name = L"p8";
			this->p8->Size = System::Drawing::Size (100, 100);
			this->p8->TabIndex = 1;
			this->p8->TabStop = false;
			this->p8->Click += gcnew System::EventHandler (this, &tic_tac_toe::p8_Click);
			// 
			// tur
			// 
			this->tur->AutoSize = true;
			this->tur->Font = (gcnew System::Drawing::Font (L"Rockwell Extra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tur->Location = System::Drawing::Point (354, 104);
			this->tur->Name = L"tur";
			this->tur->Size = System::Drawing::Size (198, 28);
			this->tur->TabIndex = 2;
			this->tur->Text = L"Tura Gracza:";
			// 
			// tura
			// 
			this->tura->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject (L"tura.Image")));
			this->tura->Location = System::Drawing::Point (547, 104);
			this->tura->Name = L"tura";
			this->tura->Size = System::Drawing::Size (30, 30);
			this->tura->TabIndex = 3;
			this->tura->TabStop = false;
			// 
			// tic_tac_toe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF (6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size (603, 339);
			this->Controls->Add (this->tura);
			this->Controls->Add (this->tur);
			this->Controls->Add (this->p9);
			this->Controls->Add (this->p6);
			this->Controls->Add (this->p3);
			this->Controls->Add (this->p7);
			this->Controls->Add (this->p4);
			this->Controls->Add (this->p8);
			this->Controls->Add (this->p5);
			this->Controls->Add (this->p2);
			this->Controls->Add (this->p1);
			this->Controls->Add (this->odNowa);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject (L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"tic_tac_toe";
			this->Text = L"tic_tac_toe";
			this->Load += gcnew System::EventHandler (this, &tic_tac_toe::tic_tac_toe_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p1))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p2))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p3))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p4))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p6))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p7))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p9))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p5))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->p8))->EndInit ();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tura))->EndInit ();
			this->ResumeLayout (false);
			this->PerformLayout ();

		}
		 public:
			 System::EventArgs^ arg;

			 void wygrana () {
				 if ((pole1 == pole2 && pole2 == pole3 && pole1 != 'n') ||
					 (pole4 == pole5 && pole5 == pole6 && pole4 != 'n') ||
					 (pole7 == pole8 && pole8 == pole9 && pole7 != 'n') ||
					 (pole1 == pole4 && pole4 == pole7 && pole1 != 'n') ||
					 (pole2 == pole5 && pole5 == pole8 && pole2 != 'n') ||
					 (pole3 == pole6 && pole6 == pole9 && pole3 != 'n') ||
					 (pole1 == pole5 && pole5 == pole9 && pole1 != 'n') ||
					 (pole3 == pole5 && pole5 == pole7 && pole3 != 'n')) {

					 p1->Enabled = false;
					 p2->Enabled = false;
					 p3->Enabled = false;
					 p4->Enabled = false;
					 p5->Enabled = false;
					 p6->Enabled = false;
					 p7->Enabled = false;
					 p8->Enabled = false;
					 p9->Enabled = false;

					 if (kto == 'x') {

						 MessageBox::Show ("Wygywa Kolko!", "Koniec Gry", MessageBoxButtons::OK, MessageBoxIcon::Information);
					 }
					 else {
						 MessageBox::Show ("Wygywa Krzyzyk!", "Koniec Gry", MessageBoxButtons::OK, MessageBoxIcon::Information);
					 }
				 }else if (pole1 != 'n' && pole2 != 'n' && pole3 != 'n' &&
					 pole4 != 'n' && pole5 != 'n' && pole6 != 'n' &&
					 pole7 != 'n' && pole8 != 'n' && pole9 != 'n') {
					 MessageBox::Show ("Remis!", "Koniec Gry", MessageBoxButtons::OK, MessageBoxIcon::Information);
				 }
			 }
#pragma endregion
	private: System::Void odNowa_Click (System::Object^  sender, System::EventArgs^  e) {
		tic_tac_toe_Load (this, arg);
	}
	private: System::Void tic_tac_toe_Load (System::Object^  sender, System::EventArgs^  e) {
		p1->Load ("img/nic.bmp"); pole1 = 'n'; p1->Enabled = true;
		p2->Load ("img/nic.bmp"); pole2 = 'n'; p2->Enabled = true;
		p3->Load ("img/nic.bmp"); pole3 = 'n'; p3->Enabled = true;
		p4->Load ("img/nic.bmp"); pole4 = 'n'; p4->Enabled = true;
		p5->Load ("img/nic.bmp"); pole5 = 'n'; p5->Enabled = true;
		p6->Load ("img/nic.bmp"); pole6 = 'n'; p6->Enabled = true;
		p7->Load ("img/nic.bmp"); pole7 = 'n'; p7->Enabled = true;
		p8->Load ("img/nic.bmp"); pole8 = 'n'; p8->Enabled = true;
		p9->Load ("img/nic.bmp"); pole9 = 'n'; p9->Enabled = true;
		kto = 'o';
		tura->Load ("img/osmall.bmp");
	}
private: System::Void p1_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole1 == 'n') {
		if (kto == 'o') {
			p1->Load ("img/o.bmp"); 
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole1 = 'o';
		}
		else {
			p1->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole1 = 'x';
		}
		p1->Enabled = false;
		wygrana ();
	}
}
private: System::Void p2_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole2 == 'n') {
		if (kto == 'o') {
			p2->Load ("img/o.bmp");
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole2 = 'o';
		}
		else {
			p2->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole2 = 'x';
		}
		p2->Enabled = false;
		wygrana ();
	}
}
private: System::Void p3_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole3 == 'n') {
		if (kto == 'o') {
			p3->Load ("img/o.bmp");
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole3 = 'o';
		}
		else {
			p3->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole3 = 'x';
		}
		p3->Enabled = false;
		wygrana ();
	}
}
private: System::Void p4_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole4 == 'n') {
		if (kto == 'o') {
			p4->Load ("img/o.bmp");
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole4 = 'o';
		}
		else {
			p4->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole4 = 'x';
		}
		p4->Enabled = false;
		wygrana ();
	}
}
private: System::Void p5_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole5 == 'n') {
		if (kto == 'o') {
			p5->Load ("img/o.bmp");
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole5 = 'o';
		}
		else {
			p5->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole5 = 'x';
		}
		p5->Enabled = false;
		wygrana ();
	}
}
private: System::Void p6_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole6 == 'n') {
		if (kto == 'o') {
			p6->Load ("img/o.bmp");
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole6 = 'o';
		}
		else {
			p6->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole6 = 'x';
		}
		p6->Enabled = false;
		wygrana ();
	}
}
private: System::Void p7_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole7 == 'n') {
		if (kto == 'o') {
			p7->Load ("img/o.bmp");
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole7 = 'o';
		}
		else {
			p7->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole7 = 'x';
		}			
		p7->Enabled = false;
		wygrana ();
	}
}
private: System::Void p8_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole8 == 'n') {
		if (kto == 'o') {
			p8->Load ("img/o.bmp");
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole8 = 'o';
		}
		else {
			p8->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole8 = 'x';
		}
		p8->Enabled = false;
		wygrana ();
	}
}
private: System::Void p9_Click (System::Object^  sender, System::EventArgs^  e) {
	if (pole9 == 'n') {
		if (kto == 'o') {
			p9->Load ("img/o.bmp");
			kto = 'x';
			tura->Load ("img/xsmall.bmp");
			pole9 = 'o';
		}
		else {
			p9->Load ("img/x.bmp");
			kto = 'o';
			tura->Load ("img/osmall.bmp");
			pole9 = 'x';
		}
		p9->Enabled = false;
		wygrana ();
	}
}

};


}
