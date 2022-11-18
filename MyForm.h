#pragma once
#include <string>
#include <vector>
#include "fstream"
#include <algorithm>
#include <bitset>
#include <msclr\marshal_cppstd.h>
#include <fstream>
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
			this->errorGen->Text = "";
			this->label4->Text = "";
			this->label5->Visible = false;
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

	private: System::Windows::Forms::Label^ errorInput;
	private: System::Windows::Forms::Label^ errorKey;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Label^ errorGen;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->errorInput = (gcnew System::Windows::Forms::Label());
			this->errorKey = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->errorGen = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(347, 20);
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
			this->label2->Size = System::Drawing::Size(317, 20);
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
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
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
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(16, 298);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Результат:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(124, 298);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"результат";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(443, 9);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(731, 617);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// serialPort1
			// 
			this->serialPort1->PortName = L"COM3";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::ForestGreen;
			this->label5->Location = System::Drawing::Point(16, 334);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Arduino";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 250;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(20, 376);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(214, 55);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Сгенерировать данные";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileName = L"CriptoDate.txt";
			// 
			// errorGen
			// 
			this->errorGen->AutoSize = true;
			this->errorGen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->errorGen->ForeColor = System::Drawing::Color::Red;
			this->errorGen->Location = System::Drawing::Point(16, 434);
			this->errorGen->Name = L"errorGen";
			this->errorGen->Size = System::Drawing::Size(103, 20);
			this->errorGen->TabIndex = 14;
			this->errorGen->Text = L"Валидация";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1191, 640);
			this->Controls->Add(this->errorGen);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->errorKey);
			this->Controls->Add(this->errorInput);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Базовый сетевой шифр замены-перестановки";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Зашифровать 
		this->validate();

		separator->SetInput(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		keyGen->SetKey(msclr::interop::marshal_as<std::string>(this->textBox2->Text));

		Graphics^ g = pictureBox1->CreateGraphics();
		g->Clear(Color::Silver);

		for (int i = 0; i < separator->GetCountWords(); i++) {
			Section* section = new Section();

			section->SetInput(stoi(separator->GetNextWord()));
			unsigned long input = section->GetOutput().to_ulong();
			section->Encrypt(keyGen, g);
			unsigned long res = section->GetOutput().to_ulong();


			this->label4->Text = gcnew System::String(to_string( res ).c_str());

			cli::array<Byte>^ buffer = gcnew cli::array<Byte> { input >> 8, input, res >> 8, res };
			
			if (this->serialPort1->IsOpen) {
				this->serialPort1->Write(buffer, 0, 4);
			}
		}
		
	}

	System::Void TextValidate(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) { // Валидация
		TextBox^ textbox = safe_cast<TextBox^>(sender);
		textbox->Text = System::Text::RegularExpressions::Regex::Replace(textbox->Text, "[^0-9]", "");
	}

	System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // Расшифровать
		this->validate();
		separator->SetInput(msclr::interop::marshal_as<std::string>(this->textBox1->Text));
		keyGen->SetKey(msclr::interop::marshal_as<std::string>(this->textBox2->Text));

		Graphics^ g = pictureBox1->CreateGraphics();
		g->Clear(Color::Silver);

		for (int i = 0; i < separator->GetCountWords(); i++) {
			Section* section = new Section();

			section->SetInput(stoi(separator->GetNextWord()));
			unsigned long input = section->GetOutput().to_ulong();
			section->Decrypt(keyGen, g);
			unsigned long res = section->GetOutput().to_ulong();

			this->label4->Text = gcnew System::String(to_string(res).c_str());

			cli::array<Byte>^ buffer = gcnew cli::array<Byte> { input >> 8, input, res >> 8, res };

			if (this->serialPort1->IsOpen) {
				this->serialPort1->Write(buffer, 0, 4);
			}
		}
	}

	void validate() {
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
	}

	void ConnectComPort() {
		cli::array<String^>^ portNames = this->serialPort1->GetPortNames();
		bool port = false;

		for each (String ^ portName in portNames)
		{
			if (portName == "COM3")
			{
				port = true;				
			}

		}

		if (!port) {
			this->label5->Visible = false;
		}
		else {
			if (this->serialPort1->IsOpen == false) {
				this->serialPort1->Open();
				this->label5->Visible = true;
			}
		}
	}

	System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		this->ConnectComPort();
	}

	System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Генерация файла
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) { return; }

		string filename = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);

		ofstream file;
		file.open(filename, std::ofstream::out | std::ofstream::trunc);
		file.close();

		S_Block* s_block = new S_Block();
		P_Block* p_block = new P_Block();

		vector<int> dateWriteFile = s_block->GetSubstitution();
		WriteVectorFile(dateWriteFile, filename);

		dateWriteFile = p_block->GetPermutation();
		WriteVectorFile(dateWriteFile, filename);

		ExempleGen(filename);
	}

	template <class T>
	void WriteVectorFile(T data, string filename) {
		ofstream file;
		file.open(filename, ios_base::out | ios_base::app);

		T::iterator itr;

		for (itr = data.begin(); itr != data.end(); itr++) {
			file << *itr << " ";
		}

		file << endl;

		file.close();
	}

	void ExempleGen(string filename) {
		
		for (int i = 0; i < 10000; i++) {
			uint16_t rand64C = ((uint16_t)rand() << 15) + rand();
			uint16_t rand64P = ((uint16_t)rand() << 15) + rand();

			separator->SetInput(to_string(rand64C));
			keyGen->SetKey(to_string(rand64P));

			for (int j = 0; j < separator->GetCountWords(); j++) {
				Section* section = new Section();

				section->SetInput(stoi(separator->GetNextWord()));
				unsigned long input = section->GetOutput().to_ulong();
				section->EncryptNoDisplay(keyGen);
				unsigned long res = section->GetOutput().to_ulong();

				ofstream file;
				file.open(filename, ios_base::out | ios_base::app);

				file << input << " " << res << endl;

				file.close();
			}
		}

	}
};
}
