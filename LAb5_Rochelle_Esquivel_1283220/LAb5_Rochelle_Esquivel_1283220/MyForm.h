#pragma once
#include "Pokemon.h"
#include "Orden.h"
namespace LAb5RochelleEsquivel1283220 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

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
			miPokedex = gcnew array <Pokemon^>(array_size);
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
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ lstNombres;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button3;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lstNombres = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(159, 107);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(437, 107);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Calcular";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// lstNombres
			// 
			this->lstNombres->FormattingEnabled = true;
			this->lstNombres->Location = System::Drawing::Point(265, 33);
			this->lstNombres->Name = L"lstNombres";
			this->lstNombres->Size = System::Drawing::Size(120, 95);
			this->lstNombres->TabIndex = 3;
			this->lstNombres->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::lstNombres_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(382, 176);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 93);
			this->textBox1->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(221, 246);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Mostrar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(83, 255);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 23);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Ordenar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(559, 362);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->lstNombres);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		array <Pokemon^>^ miPokedex;
		array <Orden^>^ miOrden;
		int array_size = 100;
		int cant_Pokemon = 0;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (System::Windows::Forms::DialogResult::OK == openFileDialog1->ShowDialog()) {
			StreamReader^ inputStream = gcnew StreamReader(openFileDialog1->FileName);
			if (inputStream != nullptr) {
				String^ linea = inputStream->ReadLine();
				while (linea && (cant_Pokemon < array_size)) {

					array<String^>^ datos = linea->Split(',');
					Pokemon^ miPokemon = gcnew Pokemon();
					miPokemon->establecer_Tipo(datos[0]);
					miPokemon->establecer_Nombre(datos[1]);
					miPokemon->establecer_Gen(datos[2]);

					miPokedex[cant_Pokemon] = miPokemon;

					linea = inputStream->ReadLine();
					cant_Pokemon++;
				}
			}
			inputStream->Close();
			for (int i = 0; i < cant_Pokemon; i++) {
				lstNombres->Items->Add(miPokedex[i]->obtener_Nombre());
			}
		}
	}
		   
	private: System::Void lstNombres_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (lstNombres->SelectedIndex >= 0) {
			String^ info_Pokemon = "Nombre:" + miPokedex[lstNombres->SelectedIndex]->obtener_Nombre() + "\r\n"
			+ "Generación:" + miPokedex[lstNombres->SelectedIndex]->obtener_Gen() + "\r\n"
			+ "Tipo:" + miPokedex[lstNombres->SelectedIndex]->obtener_Tipo();

			textBox1->Text = info_Pokemon;
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	listBox1->Items->Add(miPokedex[i]->obtener_Nombre());
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < cant_Pokemon; i++) {
		lstNombres->Items->Add(miOrden[i]->Quicksort());
	}
}
};
}
