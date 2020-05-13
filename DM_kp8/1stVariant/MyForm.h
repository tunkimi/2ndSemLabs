#pragma once
#include"windows.h"
#include<cmath>


namespace dpr {


	typedef struct name {
		int key, visited;
		float cordX, cordY;
		float elX, elY;
		struct name** adres; //адреса всех вершин (Null, если не связан)
	}NewGraph;



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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;






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

	private: static System::Collections::Generic::List<Control^>^ list = gcnew System::Collections::Generic::List<Control^>();



		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 767);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(559, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ввести данные в программу";
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
			this->textBox1->Size = System::Drawing::Size(559, 701);
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
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(578, 60);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(844, 701);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(641, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Ребро графа";
			this->label2->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(641, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(322, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Ребро графа из максимального паросочетания";
			this->label4->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(641, 100);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Вершина графа";
			this->label5->Visible = false;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(578, 767);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(279, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Отобразить введённый граф";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(863, 767);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(285, 23);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Ввести новую таблицу";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1154, 767);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(268, 23);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Завершить программу";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1434, 802);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Образцов Эльдар М8О-102Б-19";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		

#pragma endregion
		Graphics^ drowgrahp(NewGraph** graphmas, int** matre, int ex, Bitmap^ img) {

			Graphics^ graphi = Graphics::FromImage(img);
			int a, b;
			graphi->DrawLine(Pens::Black, 0, 8, 50, 8);
			graphi->DrawLine(Pens::Black, 0, 9, 50, 9);
			graphi->DrawLine(Pens::Black, 0, 10, 50, 10);
			graphi->DrawLine(Pens::Red, 0, 25, 50, 25);
			graphi->DrawLine(Pens::Red, 0, 26, 50, 26);
			graphi->DrawLine(Pens::Red, 0, 27, 50, 27);
			graphi->DrawLine(Pens::Blue, 0, 42, 50, 42);
			graphi->DrawLine(Pens::Blue, 0, 40, 50, 40);
			graphi->DrawLine(Pens::Blue, 0, 41, 50, 41);
			for (a = 0; a < ex; a++) {
				graphi->DrawEllipse(Pens::Blue, (int)graphmas[a]->cordX - 20, (int)graphmas[a]->cordY - 20, 40, 40);
				graphi->DrawEllipse(Pens::Blue, (int)graphmas[a]->cordX - 21, (int)graphmas[a]->cordY - 21, 42, 42);
				graphi->DrawEllipse(Pens::Blue, (int)graphmas[a]->cordX - 22, (int)graphmas[a]->cordY - 22, 44, 44);
				for (b = 0; b < ex; b++) {
					if (matre[a][b]) {
						graphi->DrawLine(Pens::Black, graphmas[a]->cordX, graphmas[a]->cordY, graphmas[b]->cordX, graphmas[b]->cordY);
						graphi->DrawLine(Pens::Black, 1 + graphmas[a]->cordX, graphmas[a]->cordY, 1 + graphmas[b]->cordX, graphmas[b]->cordY);
						graphi->DrawLine(Pens::Black, graphmas[a]->cordX, 1 + graphmas[a]->cordY, graphmas[b]->cordX, 1 + graphmas[b]->cordY);
						graphi->DrawLine(Pens::Black, -1 + graphmas[a]->cordX, graphmas[a]->cordY, -1 + graphmas[b]->cordX, graphmas[b]->cordY);
						graphi->DrawLine(Pens::Black, graphmas[a]->cordX, -1 + graphmas[a]->cordY, graphmas[b]->cordX, -1 + graphmas[b]->cordY);
					}
				}
			}
			for (a = 0; a < ex; a++) {
				for (b = 0; b < ex; b++) {
					if (matre[a][b] && a != b) {
						if (graphmas[a]->visited == 0 && graphmas[b]->visited == 0) {
							graphi->DrawLine(Pens::Red, graphmas[a]->cordX, graphmas[a]->cordY, graphmas[b]->cordX, graphmas[b]->cordY);
							graphi->DrawLine(Pens::Red, 1 + graphmas[a]->cordX, graphmas[a]->cordY, 1 + graphmas[b]->cordX, graphmas[b]->cordY);
							graphi->DrawLine(Pens::Red, graphmas[a]->cordX, 1 + graphmas[a]->cordY, graphmas[b]->cordX, 1 + graphmas[b]->cordY);
							graphi->DrawLine(Pens::Red, -1 + graphmas[a]->cordX, graphmas[a]->cordY, -1 + graphmas[b]->cordX, graphmas[b]->cordY);
							graphi->DrawLine(Pens::Red, graphmas[a]->cordX, -1 + graphmas[a]->cordY, graphmas[b]->cordX, -1 + graphmas[b]->cordY);
							graphmas[a]->visited = 1;
							graphmas[b]->visited = 1;
						}
					}
				}
			}
			return graphi;
		}




		int i=0, j, k, len, index, **matr, x;
		String^ str;
		Label^* labels;
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			button2->Enabled = 1;
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
			button1->Enabled = 0;
			textBox1->Enabled = 0;
		}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {



		label2->Visible = 1;
		label4->Visible = 1;
		label5->Visible = 1;
		pictureBox1->Visible = 1;
		int pW = pictureBox1->Width, pH = pictureBox1->Height;
		Bitmap^ img = gcnew Bitmap(pW, pH);
		int mX = int(pW / 2);
		int mY = int(pH / 2);    //координаты серидины окна
		Graphics^ graph; //создаем устройство для рисования на поверхности
		const double PI = acos(-1.), alpha = 2 * PI / x;
		NewGraph** graphMas = new NewGraph * [x];
		for (i = 0; i < x; i++) {
			graphMas[i] = new NewGraph;
			graphMas[i]->key = i;
			graphMas[i]->visited = 0;
			graphMas[i]->cordX = (float)(mX - 200 * sin(alpha * i));			//Координаты норм расставляет
			graphMas[i]->cordY = (float)(mY - 200 * cos(alpha * i));
			graphMas[i]->elX = (float)(mX - 255 * sin(alpha * i));
			graphMas[i]->elY = (float)(mY - 255 * cos(alpha * i));
			graphMas[i]->adres = new NewGraph * [x];
			for (j = 0; j < x; j++) {
				if (i == j) {
					graphMas[i]->adres[j] = NULL;
				}
				else if (matr[i][j]) {
					graphMas[i]->adres[j] = graphMas[j];
				}
				else {
					graphMas[i]->adres[j] = NULL;
				}
			}
		}
		graph = drowgrahp(graphMas, matr, x, img);


		//ебаные лейблы надо удалить как-то чекни киберфорум статью

		for (i = 0; i < x; i++) {
			Label^ label11 = gcnew Label;
			label11->Parent = this;
			label11->Text = Convert::ToString(i + 1);
			label11->Location = System::Drawing::Point(graphMas[i]->elX+426, graphMas[i]->elY+45);
			label11->Size = System::Drawing::Size(40, 20);
			label11->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			label11->BringToFront();

			list->Add(label11);
		}




		this->pictureBox1->Image = img;
		button2->Enabled = 0;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		button2->Enabled = 0;
		button1->Enabled = 1;
		textBox1->Enabled = 1;
		label2->Visible = 0;
		label4->Visible = 0;
		label5->Visible = 0;
		pictureBox1->Visible = 0;
		for (int j = 0; j < list->Count; ++j)
		{
			this->Controls->Remove(list[j]);
		}

		list->Clear();



	}
};
}
