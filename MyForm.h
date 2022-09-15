#pragma once
#include <string>
#include <vector>
#include "fstream"
#include <algorithm>
#include <bitset>
#include <msclr\marshal_cppstd.h>
#include "Separator.h"
#include "KeyGen.h"
#include "Section.h"

namespace BasicSPEncryption {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	Separator* separator = new Separator();
	KeyGen* keyGen = new KeyGen();

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			this->errorInput->Text = "";
			this->errorKey->Text = "";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ errorInput;
	private: System::Windows::Forms::Label^ errorKey;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->errorInput = (gcnew System::Windows::Forms::Label());
			this->errorKey = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(402, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Исходные данные (число от 0 до 65 535)";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(20, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(214, 27);
			this->textBox1->TabIndex = 1;
			this->textBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::TextValidate);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(16, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(372, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Введите ключ (число от 0 до 65 535)";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(20, 125);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(214, 27);
			this->textBox2->TabIndex = 3;
			this->textBox2->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::TextValidate);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(20, 196);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(214, 32);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Зашифровать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(20, 244);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(214, 32);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Расшифровать";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(546, 12);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox3->Size = System::Drawing::Size(550, 410);
			this->textBox3->TabIndex = 6;
			// 
			// errorInput
			// 
			this->errorInput->AutoSize = true;
			this->errorInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->errorInput->ForeColor = System::Drawing::Color::Red;
			this->errorInput->Location = System::Drawing::Point(16, 74);
			this->errorInput->Name = L"errorInput";
			this->errorInput->Size = System::Drawing::Size(103, 20);
			this->errorInput->TabIndex = 7;
			this->errorInput->Text = L"Валидация";
			// 
			// errorKey
			// 
			this->errorKey->AutoSize = true;
			this->errorKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->errorKey->ForeColor = System::Drawing::Color::Red;
			this->errorKey->Location = System::Drawing::Point(16, 155);
			this->errorKey->Name = L"errorKey";
			this->errorKey->Size = System::Drawing::Size(103, 20);
			this->errorKey->TabIndex = 8;
			this->errorKey->Text = L"Валидация";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1108, 468);
			this->Controls->Add(this->errorKey);
			this->Controls->Add(this->errorInput);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Зашифровать 
		this->errorInput->ResetText();
		if (this->textBox1->TextLength <= 0) {
			this->errorInput->Text = "Введите входные данные";
			return;
		}

		this->errorKey->ResetText();
		if (this->textBox2->TextLength <= 0) {
			this->errorKey->Text = "Введите ключ";
			return;
		}

		// Временно. Далее перенести код проверки в сепаратор
		try {
			unsigned short int input = UInt16::Parse(this->textBox1->Text);
		}
		catch (...) {
			this->errorInput->Text = "Число слишком маленькое или слишком большое";
			return;
		}

		try {
			unsigned short int key = UInt16::Parse(this->textBox2->Text);
		}
		catch (...) {
			this->errorKey->Text = "Число слишком маленькое или слишком большое";
			return;
		}

		separator->SetInput(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		keyGen->SetKey(msclr::interop::marshal_as<std::string>(this->textBox2->Text));
		
		for (int i = 0; i < separator->GetCountWords(); i++) {
			Section* section = new Section();

			section->SetInput(separator->GetNextWord());
			section->Encrypt(keyGen);
		}
		
	}

	System::Void TextValidate(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) { // Валидация
		TextBox^ textbox = safe_cast<TextBox^>(sender);
		textbox->Text = System::Text::RegularExpressions::Regex::Replace(textbox->Text, "[^1-9]", "");
	}
};
}
