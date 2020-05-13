#pragma once
#include"windows.h"
#include "Form2.h"


namespace dicret {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;

	protected:

	public:
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 532);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(632, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Построить граф";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 60);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(632, 466);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(559, 48);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Задайте граф в виде таблицы смежности с разделителями:\n[Space] - пробел и [Enter]"
				L" - перенос строки.";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 511);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 17);
			this->label3->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(656, 562);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Образцов Эльдар М8О-102Б-19";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int i=0, j, k, len, index, **matr, x;
		String^ str;
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			label3->Text = "";
			str = textBox1->Text;
			len = str->Length;
			x = 0;
			using namespace System::Runtime::InteropServices;
			char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
			index = textBox1->Text->IndexOf("\n");
			if (textBox1->Text != "") {
				if (index == -1) {
					MessageBox::Show("Нет оконченных строк", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
				for (i = 0; i < len-1; i++) {
					if (str2[i] == 13 || str2[i] == 10 || str[i]==' '){
						continue;
					}
					else {
						if (str[i] != '0' && str[i] != '1') {
							MessageBox::Show("Таблица смежности должна состоять из 0 и 1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
							return;
						}
					}
				}
				for (i = 0; i<index-1; i++) {
					if (str[i] == '1' || str[i] == '0') {
						x++;
					}
					else continue;
				}
			}
			else {
				MessageBox::Show("Заполните матрицу смежности", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}
			matr = new int* [x];
			for (i = 0; i < x; i++) {
				matr[i] = new int[x];
			}
			i = j = 0;
			for (k = 0; k < len; k++) {
				if (str[k] == '0') {
					matr[i][j] = 0;
					j++;
				}
				else if (str[k] == '1') {
					matr[i][j] = 1;
					j++;
				}
				else{
					continue;
				}
				if (j == x) {
					j = 0;
					i++;
				}
			}
			if (matr[x-1][x-1] != 0 && matr[x-1][x-1] != 1) {
				MessageBox::Show("Введите матрицу до конца", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}
			for (i = 0; i < x; i++) {
				if (matr[i][i] != 1) {
					MessageBox::Show("На главной диагонали Матрицы смежности должны стоять 1", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
				for (j = i+1; j < x; j++){
					if (matr[i][j] != matr[j][i]) {
						MessageBox::Show("Матрица смежности должна быть симметричной", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
				}
			}


			Form2^ f2 = gcnew Form2(x, matr);
			f2->Owner = this;
			f2->Show();
			



			/*
			Form^ form2 = gcnew Form();
			form2->Text = L"Граф";
			form2->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			form2->StartPosition = FormStartPosition::CenterScreen;
			form2->Size= System::Drawing::Size(500, 500);
			form2->ShowDialog();
			*/
		}
	};
}
