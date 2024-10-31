#pragma once
#include "Matrix.h"

namespace lab4 {

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
	private: System::Windows::Forms::TextBox^ Cols;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ Rows;
	private: System::Windows::Forms::Button^ Run;

	private: System::Windows::Forms::Button^ Run_Rand;
	private: System::Windows::Forms::DataGridView^ GridMatrix;




	private: System::Windows::Forms::Button^ CreateMatrix;
	private: System::Windows::Forms::Label^ ResultLabel;
	private: System::Windows::Forms::DataGridView^ ResultMatrix;

	private: System::Windows::Forms::Label^ Max_Col;
	private: System::Windows::Forms::Label^ max_col_label;
	private: System::Windows::Forms::Label^ Num_Max_Row;
	private: System::Windows::Forms::Label^ NumMaxRow;
	private: System::Windows::Forms::Button^ Reset;















	protected:

	protected:
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
			this->Cols = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Rows = (gcnew System::Windows::Forms::TextBox());
			this->Run = (gcnew System::Windows::Forms::Button());
			this->Run_Rand = (gcnew System::Windows::Forms::Button());
			this->GridMatrix = (gcnew System::Windows::Forms::DataGridView());
			this->CreateMatrix = (gcnew System::Windows::Forms::Button());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->ResultMatrix = (gcnew System::Windows::Forms::DataGridView());
			this->Max_Col = (gcnew System::Windows::Forms::Label());
			this->max_col_label = (gcnew System::Windows::Forms::Label());
			this->Num_Max_Row = (gcnew System::Windows::Forms::Label());
			this->NumMaxRow = (gcnew System::Windows::Forms::Label());
			this->Reset = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridMatrix))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultMatrix))->BeginInit();
			this->SuspendLayout();
			// 
			// Cols
			// 
			this->Cols->Location = System::Drawing::Point(109, 12);
			this->Cols->Name = L"Cols";
			this->Cols->Size = System::Drawing::Size(59, 20);
			this->Cols->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Кол-во столбцов";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(191, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Кол-во строк";
			// 
			// Rows
			// 
			this->Rows->Location = System::Drawing::Point(270, 12);
			this->Rows->Name = L"Rows";
			this->Rows->Size = System::Drawing::Size(59, 20);
			this->Rows->TabIndex = 2;
			// 
			// Run
			// 
			this->Run->Location = System::Drawing::Point(15, 321);
			this->Run->Name = L"Run";
			this->Run->Size = System::Drawing::Size(153, 41);
			this->Run->TabIndex = 3;
			this->Run->Text = L"Выполнить";
			this->Run->UseVisualStyleBackColor = true;
			this->Run->Click += gcnew System::EventHandler(this, &MyForm::Run_Click);
			// 
			// Run_Rand
			// 
			this->Run_Rand->Location = System::Drawing::Point(253, 42);
			this->Run_Rand->Name = L"Run_Rand";
			this->Run_Rand->Size = System::Drawing::Size(76, 23);
			this->Run_Rand->TabIndex = 4;
			this->Run_Rand->Text = L"Ранд";
			this->Run_Rand->UseVisualStyleBackColor = true;
			this->Run_Rand->Click += gcnew System::EventHandler(this, &MyForm::Run_Rand_Click);
			// 
			// GridMatrix
			// 
			this->GridMatrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GridMatrix->Location = System::Drawing::Point(15, 71);
			this->GridMatrix->Name = L"GridMatrix";
			this->GridMatrix->Size = System::Drawing::Size(315, 244);
			this->GridMatrix->TabIndex = 5;
			this->GridMatrix->AllowUserToAddRows = false;
			this->GridMatrix->AllowUserToDeleteRows = false;
			// 
			// CreateMatrix
			// 
			this->CreateMatrix->Location = System::Drawing::Point(15, 42);
			this->CreateMatrix->Name = L"CreateMatrix";
			this->CreateMatrix->Size = System::Drawing::Size(104, 23);
			this->CreateMatrix->TabIndex = 8;
			this->CreateMatrix->Text = L"Создать матрицу";
			this->CreateMatrix->UseVisualStyleBackColor = true;
			this->CreateMatrix->Click += gcnew System::EventHandler(this, &MyForm::CreateMatrix_Click);
			// 
			// ResultLabel
			// 
			this->ResultLabel->AutoSize = true;
			this->ResultLabel->Location = System::Drawing::Point(362, 15);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(62, 13);
			this->ResultLabel->TabIndex = 9;
			this->ResultLabel->Text = L"Результат:";
			// 
			// ResultMatrix
			// 
			this->ResultMatrix->ReadOnly = true;
			this->ResultMatrix->AllowUserToAddRows = false;
			this->ResultMatrix->AllowUserToDeleteRows = false;
			this->ResultMatrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ResultMatrix->Location = System::Drawing::Point(365, 71);
			this->ResultMatrix->Name = L"ResultMatrix";
			this->ResultMatrix->Size = System::Drawing::Size(315, 244);
			this->ResultMatrix->TabIndex = 10;
			// 
			// Max_Col
			// 
			this->Max_Col->AutoSize = true;
			this->Max_Col->Location = System::Drawing::Point(498, 34);
			this->Max_Col->Name = L"Max_Col";
			this->Max_Col->Size = System::Drawing::Size(33, 13);
			this->Max_Col->TabIndex = 11;
			this->Max_Col->Text = L"None";
			// 
			// max_col_label
			// 
			this->max_col_label->AutoSize = true;
			this->max_col_label->Location = System::Drawing::Point(362, 34);
			this->max_col_label->Name = L"max_col_label";
			this->max_col_label->Size = System::Drawing::Size(133, 13);
			this->max_col_label->TabIndex = 12;
			this->max_col_label->Text = L"Максимальный столбец:";
			// 
			// Num_Max_Row
			// 
			this->Num_Max_Row->AutoSize = true;
			this->Num_Max_Row->Location = System::Drawing::Point(362, 47);
			this->Num_Max_Row->Name = L"Num_Max_Row";
			this->Num_Max_Row->Size = System::Drawing::Size(122, 13);
			this->Num_Max_Row->TabIndex = 13;
			this->Num_Max_Row->Text = L"Среднего ариф. строк:";
			// 
			// NumMaxRow
			// 
			this->NumMaxRow->AutoSize = true;
			this->NumMaxRow->Location = System::Drawing::Point(498, 47);
			this->NumMaxRow->Name = L"NumMaxRow";
			this->NumMaxRow->Size = System::Drawing::Size(33, 13);
			this->NumMaxRow->TabIndex = 14;
			this->NumMaxRow->Text = L"None";
			// 
			// Reset
			// 
			this->Reset->Location = System::Drawing::Point(605, 330);
			this->Reset->Name = L"Reset";
			this->Reset->Size = System::Drawing::Size(75, 23);
			this->Reset->TabIndex = 15;
			this->Reset->Text = L"Сброс";
			this->Reset->UseVisualStyleBackColor = true;
			this->Reset->Click += gcnew System::EventHandler(this, &MyForm::Reset_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->ClientSize = System::Drawing::Size(707, 379);
			this->Controls->Add(this->Reset);
			this->Controls->Add(this->NumMaxRow);
			this->Controls->Add(this->Num_Max_Row);
			this->Controls->Add(this->max_col_label);
			this->Controls->Add(this->Max_Col);
			this->Controls->Add(this->ResultMatrix);
			this->Controls->Add(this->ResultLabel);
			this->Controls->Add(this->CreateMatrix);
			this->Controls->Add(this->GridMatrix);
			this->Controls->Add(this->Run_Rand);
			this->Controls->Add(this->Run);
			this->Controls->Add(this->Rows);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Cols);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"MyForm";
			this->Text = L"4lab";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridMatrix))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultMatrix))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void Run_Rand_Click(System::Object^ sender, System::EventArgs^ e) {
	int row = GridMatrix->RowCount;
	int col = GridMatrix->ColumnCount;
	Matrix m = user_input(row, col, 1);
	int max_col_or_row = m.columns < m.rows ? m.rows : m.columns;
	int min_col_or_row = m.columns > m.rows ? m.rows : m.columns;
	for (int x = 0; x < m.rows; x++) {
		for (int y = 0; y < m.columns; y++) {
			if (m.columns <= m.rows) GridMatrix->Rows[y]->Cells[x]->Value = m.matrix[x * (min_col_or_row)+y];
			else GridMatrix->Rows[x]->Cells[y]->Value = m.matrix[x * (max_col_or_row)+y];
		}
	}
}

private: System::Void CreateMatrix_Click(System::Object^ sender, System::EventArgs^ e) {
	if(Cols->TextLength == 0 || Rows->TextLength == 0) MessageBox::Show(this, "Вы не задали кол-во строк или столбцов", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else {
		int col = System::Convert::ToInt32(Cols->Text);
		int row = System::Convert::ToInt32(Rows->Text);
		if (col < 1 || row < 1) MessageBox::Show(this, "Кол-во строк или столбцов меньше 1 ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else if (col > 100 || row > 100) MessageBox::Show(this, "Кол-во строк или столбцов превышает максимальное значение (50) ", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else {
			GridMatrix->RowCount = row;
			GridMatrix->ColumnCount = col;
			ResultMatrix->RowCount = row;
			ResultMatrix->ColumnCount = col;
			for (int x = 0; x < row; x++) {
				for (int y = 0; y < col; y++) {
					GridMatrix->Rows[x]->Cells[y]->Value = 0;
				}
			}
		}
	}
}
double* manualFiling(int r, int c) {
	double* a = new double[r * c];
	int i = 0;
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			a[i] = System::Convert::ToDouble(GridMatrix->Rows[x]->Cells[y]->Value);
			i++;
		}
	}
	return a;
}

private: System::Void Run_Click(System::Object^ sender, System::EventArgs^ e) {
		int row = GridMatrix->RowCount;
		int col = GridMatrix->ColumnCount;
		Matrix m = *(init_matrix(manualFiling(row, col), row, col));
		Max_Col->Text = System::Convert::ToString(search_max_cols(&m));
		NumMaxRow->Text = System::Convert::ToString(sdr_arf(&m));
		sort_matrix(&m, search_max_cols(&m));
		int max_col_or_row = m.columns < m.rows ? m.rows : m.columns;
		int min_col_or_row = m.columns > m.rows ? m.rows : m.columns;
		for (int x = 0; x < m.rows; x++) {
			for (int y = 0; y < m.columns; y++) {
				if (m.columns >= m.rows) ResultMatrix->Rows[x]->Cells[y]->Value = m.matrix[x * (max_col_or_row)+y];
				else ResultMatrix->Rows[x]->Cells[y]->Value = m.matrix[x * (min_col_or_row)+y];
			}
		}
}
private: System::Void Reset_Click(System::Object^ sender, System::EventArgs^ e) {
		int row = GridMatrix->RowCount;
		int col = GridMatrix->ColumnCount;
		for (int x = 0; x < row; x++) {
			for (int y = 0; y < col; y++) {
				GridMatrix->Rows[x]->Cells[y]->Value = 0;
				ResultMatrix->Rows[x]->Cells[y]->Value = 0;
			}
		}
}
};
}