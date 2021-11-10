#pragma once
#include "Juego.h"

namespace KirbyRecycleDeluxe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			// Archivos de los sprites
			// Deberia ser juego
			bmpAnaconda = gcnew Bitmap("sprites\\snake.png");
			bmpArana = gcnew Bitmap("sprites\\spider.png");
			bmpBasura = gcnew Bitmap("sprites\\trash.png");
			bmpCondor = gcnew Bitmap("sprites\\condor.png");
			bmpCushuro = gcnew Bitmap("sprites\\cushuro.png");
			bmpFruta = gcnew Bitmap("sprites\\fruit.png");
			bmpGranizo = gcnew Bitmap("sprites\\granizo.png");
			bmpKirbyHielo = gcnew Bitmap("sprites\\kirby_ice.png");
			bmpKirbyNada = gcnew Bitmap("sprites\\kirby_swim.png");
			bmpKirbyVuela = gcnew Bitmap("sprites\\kirby_fly.png");
			bmpPez = gcnew Bitmap("sprites\\fish.png");
			bmpPirana = gcnew Bitmap("sprites\\piranha.png");
			bmpPulpo = gcnew Bitmap("sprites\\pulpo.png");
			// Fondos 
			bmpCosta = gcnew Bitmap("sprites\\underwater.png");
			bmpSierra =  gcnew Bitmap("sprites\\sierra.png");
			bmpSelva = gcnew Bitmap("sprites\\selva.png");

			objJuego = new Juego();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			// Eliminar variables
			delete objJuego, bmpAnaconda, bmpArana, bmpBasura, bmpCondor, bmpCushuro, bmpFruta, bmpGranizo,
				bmpKirbyHielo, bmpKirbyNada, bmpKirbyVuela, bmpPez, bmpPirana, bmpPulpo,
				bmpCosta, bmpSelva, bmpSierra;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		// Inicializar variables
		// Aca deberia ser Juego, no selva
		Juego* objJuego;
		Bitmap^ bmpAnaconda;
		Bitmap^ bmpArana;
		Bitmap^ bmpBasura;
		Bitmap^ bmpCondor;
		Bitmap^ bmpCushuro;
		Bitmap^ bmpFruta;
		Bitmap^ bmpGranizo;
		Bitmap^ bmpKirbyVuela;
		Bitmap^ bmpKirbyNada;
		Bitmap^ bmpKirbyHielo;
		Bitmap^ bmpPez;
		Bitmap^ bmpPirana;
		Bitmap^ bmpPulpo;
		// Fondos
		Bitmap^ bmpCosta;
		Bitmap^ bmpSelva;
	   Bitmap^ bmpSierra;
	private: System::Windows::Forms::Label^ lbPuntos;
	private: System::Windows::Forms::Label^ lbTiempo;
	private: System::Windows::Forms::Label^ lbVidas;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbPuntos = (gcnew System::Windows::Forms::Label());
			this->lbTiempo = (gcnew System::Windows::Forms::Label());
			this->lbVidas = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// lbPuntos
			// 
			this->lbPuntos->AutoSize = true;
			this->lbPuntos->Location = System::Drawing::Point(12, 9);
			this->lbPuntos->Name = L"lbPuntos";
			this->lbPuntos->Size = System::Drawing::Size(46, 17);
			this->lbPuntos->TabIndex = 0;
			this->lbPuntos->Text = L"label1";
			// 
			// lbTiempo
			// 
			this->lbTiempo->AutoSize = true;
			this->lbTiempo->Location = System::Drawing::Point(12, 40);
			this->lbTiempo->Name = L"lbTiempo";
			this->lbTiempo->Size = System::Drawing::Size(46, 17);
			this->lbTiempo->TabIndex = 1;
			this->lbTiempo->Text = L"label2";
			// 
			// lbVidas
			// 
			this->lbVidas->AutoSize = true;
			this->lbVidas->Location = System::Drawing::Point(12, 70);
			this->lbVidas->Name = L"lbVidas";
			this->lbVidas->Size = System::Drawing::Size(46, 17);
			this->lbVidas->TabIndex = 2;
			this->lbVidas->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 631);
			this->Controls->Add(this->lbVidas);
			this->Controls->Add(this->lbTiempo);
			this->Controls->Add(this->lbPuntos);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left)
			objJuego->Desplazar(dir::left);
		if (e->KeyCode == Keys::Right)
			objJuego->Desplazar(dir::right);
		if (e->KeyCode == Keys::Up)
			objJuego->Desplazar(dir::up);
		if (e->KeyCode == Keys::Down)
			objJuego->Desplazar(dir::down);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		System::String^ puntos = "Puntos: " + (objJuego->getContador());
		lbPuntos->Text = puntos;

		System::String^ tiempo = "Tiempo: " + (objJuego->getTiempo()) + "s";
		lbTiempo->Text = tiempo;

		System::String^ vidas = "Vidas: " + (objJuego->getVidas());
		lbVidas->Text = vidas;

		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

		// Variable que obtenga en que nivel esta ahora el juego
		int nivel = objJuego->getNivel();

		// Fondos
		if (nivel == 1)
			bf->Graphics->DrawImage(bmpCosta, ClientRectangle,
				Rectangle(0, 0, bmpCosta->Width, bmpCosta->Height), GraphicsUnit::Pixel);
		if (nivel == 2)
			bf->Graphics->DrawImage(bmpSierra, ClientRectangle,
				Rectangle(0, 0, bmpSierra->Width, bmpSierra->Height), GraphicsUnit::Pixel);
		if (nivel == 3)
			bf->Graphics->DrawImage(bmpSelva, ClientRectangle,
				Rectangle(0, 0, bmpSelva->Width, bmpSelva->Height), GraphicsUnit::Pixel);

		// el Forms evalua en que nivel esta el juego
		if (!objJuego->getFin()) {
			if (nivel == 1)
				objJuego->Jugar_Costa();
			if (nivel == 2)
				objJuego->Jugar_Sierra();
			if (nivel == 3)
				objJuego->Jugar_Selva(bf->Graphics, bmpFruta, bmpAnaconda, bmpArana, bmpPirana,
					bmpKirbyVuela, bmpKirbyNada, bmpBasura);
		}
		else {
			if (objJuego->getGanador()) {
				if (nivel == 1 || nivel == 2)
					objJuego->setNivel();
				if (nivel == 3)
					objJuego->Resumen(bf->Graphics);
			}
			else {
				objJuego->Resumen(bf->Graphics);
			}
		}

		bf->Render(g);
		delete bf, espacio, g;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
