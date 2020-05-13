#pragma once
#include <cmath>

namespace dicret {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form2
	/// </summary>

	typedef struct name {
		int key, visited;
		float cordX, cordY;
		float elX, elY;
		struct name **adres; //адреса всех вершин (Null, если не связан)
	}NewGraph;

	





	public ref class Form2 : public System::Windows::Forms::Form
	{
		int en, **mat;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	public:
		Form2(int n, int **matrix)
		{
			mat = matrix;
			en = n;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ button1;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(10, 10);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(710, 737);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(104, 753);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(229, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Отобразить введённый граф";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			this->button1->Visible = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(83, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ребро графа";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(83, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(322, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Ребро графа из максимального паросочетания";
			this->label2->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(339, 753);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(182, 32);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Ввести новую таблицу";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			this->button2->Visible = 1;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(527, 753);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(193, 32);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Завершить программу";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			this->button3->Visible = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(83, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Вершина графа";
			this->label3->Visible = false;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(743, 797);
			this->ControlBox = false;
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Location = System::Drawing::Point(600, 200);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(765, 848);
			this->MinimumSize = System::Drawing::Size(765, 848);
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Максимальное паросочетание";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



		Graphics^ drowgrahp( NewGraph** graphmas, int** matre, int ex, Bitmap^ img) {
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
					if (matre[a][b]&&a!=b) {
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
		

		int i, j;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		button1->Visible = 0;
		int pW = pictureBox1->Width, pH = pictureBox1->Height;
		Bitmap^ img = gcnew Bitmap(pW, pH);
		int mX = int(pW / 2);
		int mY = int(pH / 2) + 36;    //координаты серидины окна
		Graphics^ graph; //создаем устройство для рисования на поверхности
		const double PI = acos(-1.), alpha = 2*PI/en;

		this->label1->Visible = 1;
		this->label2->Visible = 1;
		this->label3->Visible = 1;













		/*	
		int tr = mX, pl = mY;					//не нужны - чисто запоминалки предыдущих координат для тестового рисунка
		graphMas = new NewGraph*[en];
		for (i = 0; i < en; i++) {
			label1->Text = Convert::ToString(en);
			graphMas[i] = new NewGraph;
			graphMas[i]->cordX = mX - 200 * sin(alpha * i);			//Координаты норм расставляет
			graphMas[i]->cordY = mY - 200 * cos(alpha * i);
			graph->DrawLine(Pens::Black, tr, pl, graphMas[i]->cordX, graphMas[i]->cordY);
			tr = graphMas[i]->cordX;
			pl = graphMas[i]->cordY;
		}*///-затестить рисунок

		

		NewGraph** graphMas = new NewGraph*[en];
		for (i = 0; i < en; i++) {
			graphMas[i] = new NewGraph;
			graphMas[i]->key = i;
			graphMas[i]->visited = 0;
			graphMas[i]->cordX = (float)(mX - 200 * sin(alpha * i));			//Координаты норм расставляет
			graphMas[i]->cordY = (float)(mY - 200 * cos(alpha * i));

			graphMas[i]->elX = (float)(mX - 255 * sin(alpha * i));
			graphMas[i]->elY = (float)(mY - 255 * cos(alpha * i));








			graphMas[i]->adres = new NewGraph * [en];
			for (j = 0; j < en; j++) {
				if (i == j) {
					graphMas[i]->adres[j] = NULL;
				}
				else if (mat[i][j]) {
					graphMas[i]->adres[j] = graphMas[j];
				}
				else {
					graphMas[i]->adres[j] = NULL;
				}
			}
		}
		graph = drowgrahp(graphMas, mat, en, img);



		for (i = 0; i < en; i++) {
			Label^ label11 = gcnew Label;
			label11->Parent = this;
			label11->Text = Convert::ToString(i+1);
			label11->Location = System::Drawing::Point(graphMas[i]->elX, graphMas[i]->elY);
			label11->Size = System::Drawing::Size(40, 20); 
			label11->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			label11->BringToFront();
		}


		this->pictureBox1->Image = img; //присвоение и отображение изображения в PictureBox

		













	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	delete this;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
