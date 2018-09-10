#pragma once
#include "Students.h"

namespace StudentManager {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	private: Students students;
	public:
		MainForm(void)
		{
			InitializeComponent();
			//Pre-select combobox
			cbSearchFilter->SelectedIndex = 0;
			//read data from file
			students.ReadFile();
			//update table
			updateGridView(students.GetStudentList());
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  lblStudentName;
	private: System::Windows::Forms::TextBox^  txtStudentName;

	private: System::Windows::Forms::Label^  lblStudentDateOfBirth;
	private: System::Windows::Forms::TextBox^  txtStudentDateOfBirth;

	private: System::Windows::Forms::Label^  lblStudentID;
	private: System::Windows::Forms::TextBox^  txtStudentID;

	private: System::Windows::Forms::Label^  lblStudentScore;
	private: System::Windows::Forms::TextBox^  txtStudentScore;

	private: System::Windows::Forms::Label^  lblStudentClass;
	private: System::Windows::Forms::TextBox^  txtStudentClass;

	private: System::Windows::Forms::Button^  btnUpdate;
	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::Button^  btnAdd;

	private: System::Windows::Forms::TextBox^  txtSearchKeywords;
	private: System::Windows::Forms::ComboBox^  cbSearchFilter;
	private: System::Windows::Forms::GroupBox^  grpSearch;
	private: System::Windows::Forms::Button^  btnSearch;
	private: System::Windows::Forms::GroupBox^  grpInfo;

	private: System::Windows::Forms::DataGridView^  dgvStudents;

	private: System::Windows::Forms::Label^  lblSearchFilter;
	private: System::Windows::Forms::Label^  lblKeywords;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  clmnIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  clmnName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  clmnClass;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  clmnDateOfBirth;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  clmnId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  clmnScore;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->lblStudentName = (gcnew System::Windows::Forms::Label());
			this->txtStudentName = (gcnew System::Windows::Forms::TextBox());
			this->lblStudentDateOfBirth = (gcnew System::Windows::Forms::Label());
			this->txtStudentDateOfBirth = (gcnew System::Windows::Forms::TextBox());
			this->lblStudentID = (gcnew System::Windows::Forms::Label());
			this->txtStudentID = (gcnew System::Windows::Forms::TextBox());
			this->lblStudentScore = (gcnew System::Windows::Forms::Label());
			this->txtStudentScore = (gcnew System::Windows::Forms::TextBox());
			this->lblStudentClass = (gcnew System::Windows::Forms::Label());
			this->txtStudentClass = (gcnew System::Windows::Forms::TextBox());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->txtSearchKeywords = (gcnew System::Windows::Forms::TextBox());
			this->cbSearchFilter = (gcnew System::Windows::Forms::ComboBox());
			this->grpSearch = (gcnew System::Windows::Forms::GroupBox());
			this->lblKeywords = (gcnew System::Windows::Forms::Label());
			this->lblSearchFilter = (gcnew System::Windows::Forms::Label());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->grpInfo = (gcnew System::Windows::Forms::GroupBox());
			this->dgvStudents = (gcnew System::Windows::Forms::DataGridView());
			this->clmnIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmnName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmnClass = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmnDateOfBirth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmnId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmnScore = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpSearch->SuspendLayout();
			this->grpInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudents))->BeginInit();
			this->SuspendLayout();
			//
			// lblStudentName
			//
			this->lblStudentName->AutoSize = true;
			this->lblStudentName->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentName->Location = System::Drawing::Point(35, 25);
			this->lblStudentName->Name = L"lblStudentName";
			this->lblStudentName->Size = System::Drawing::Size(48, 17);
			this->lblStudentName->TabIndex = 0;
			this->lblStudentName->Text = L"họ tên";
			//
			// txtStudentName
			//
			this->txtStudentName->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStudentName->Location = System::Drawing::Point(89, 22);
			this->txtStudentName->Name = L"txtStudentName";
			this->txtStudentName->Size = System::Drawing::Size(204, 24);
			this->txtStudentName->TabIndex = 1;
			//
			// lblStudentDateOfBirth
			//
			this->lblStudentDateOfBirth->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblStudentDateOfBirth->AutoSize = true;
			this->lblStudentDateOfBirth->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentDateOfBirth->Location = System::Drawing::Point(345, 27);
			this->lblStudentDateOfBirth->Name = L"lblStudentDateOfBirth";
			this->lblStudentDateOfBirth->Size = System::Drawing::Size(70, 17);
			this->lblStudentDateOfBirth->TabIndex = 0;
			this->lblStudentDateOfBirth->Text = L"ngày sinh";
			//
			// txtStudentDateOfBirth
			//
			this->txtStudentDateOfBirth->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtStudentDateOfBirth->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStudentDateOfBirth->Location = System::Drawing::Point(421, 25);
			this->txtStudentDateOfBirth->Name = L"txtStudentDateOfBirth";
			this->txtStudentDateOfBirth->Size = System::Drawing::Size(142, 24);
			this->txtStudentDateOfBirth->TabIndex = 2;
			//
			// lblStudentID
			//
			this->lblStudentID->AutoSize = true;
			this->lblStudentID->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentID->Location = System::Drawing::Point(31, 53);
			this->lblStudentID->Name = L"lblStudentID";
			this->lblStudentID->Size = System::Drawing::Size(52, 17);
			this->lblStudentID->TabIndex = 0;
			this->lblStudentID->Text = L"mã SV";
			//
			// txtStudentID
			//
			this->txtStudentID->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStudentID->Location = System::Drawing::Point(89, 50);
			this->txtStudentID->Name = L"txtStudentID";
			this->txtStudentID->Size = System::Drawing::Size(204, 24);
			this->txtStudentID->TabIndex = 3;
			//
			// lblStudentScore
			//
			this->lblStudentScore->AutoSize = true;
			this->lblStudentScore->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentScore->Location = System::Drawing::Point(43, 81);
			this->lblStudentScore->Name = L"lblStudentScore";
			this->lblStudentScore->Size = System::Drawing::Size(40, 17);
			this->lblStudentScore->TabIndex = 0;
			this->lblStudentScore->Text = L"điểm";
			//
			// txtStudentScore
			//
			this->txtStudentScore->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStudentScore->Location = System::Drawing::Point(89, 78);
			this->txtStudentScore->Name = L"txtStudentScore";
			this->txtStudentScore->Size = System::Drawing::Size(204, 24);
			this->txtStudentScore->TabIndex = 5;
			//
			// lblStudentClass
			//
			this->lblStudentClass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblStudentClass->AutoSize = true;
			this->lblStudentClass->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStudentClass->Location = System::Drawing::Point(386, 59);
			this->lblStudentClass->Name = L"lblStudentClass";
			this->lblStudentClass->Size = System::Drawing::Size(29, 17);
			this->lblStudentClass->TabIndex = 0;
			this->lblStudentClass->Text = L"lớp";
			//
			// txtStudentClass
			//
			this->txtStudentClass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->txtStudentClass->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtStudentClass->Location = System::Drawing::Point(421, 53);
			this->txtStudentClass->Name = L"txtStudentClass";
			this->txtStudentClass->Size = System::Drawing::Size(142, 24);
			this->txtStudentClass->TabIndex = 4;
			//
			// btnUpdate
			//
			this->btnUpdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUpdate->Location = System::Drawing::Point(608, 23);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(92, 22);
			this->btnUpdate->TabIndex = 100;
			this->btnUpdate->Text = L"CẬP NHẬP";
			this->btnUpdate->UseVisualStyleBackColor = true;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &MainForm::btnUpdate_Click);
			//
			// btnDelete
			//
			this->btnDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDelete->Location = System::Drawing::Point(608, 50);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(92, 23);
			this->btnDelete->TabIndex = 100;
			this->btnDelete->Text = L"XÓA";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MainForm::btnDelete_Click);
			//
			// btnAdd
			//
			this->btnAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdd->Location = System::Drawing::Point(608, 78);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(92, 23);
			this->btnAdd->TabIndex = 100;
			this->btnAdd->Text = L"THÊM";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MainForm::btnAdd_Click);
			//
			// txtSearchKeywords
			//
			this->txtSearchKeywords->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSearchKeywords->Location = System::Drawing::Point(89, 22);
			this->txtSearchKeywords->Name = L"txtSearchKeywords";
			this->txtSearchKeywords->Size = System::Drawing::Size(204, 24);
			this->txtSearchKeywords->TabIndex = 6;
			//
			// cbSearchFilter
			//
			this->cbSearchFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbSearchFilter->FormattingEnabled = true;
			this->cbSearchFilter->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"tên", L"lớp", L"mã SV" });
			this->cbSearchFilter->Location = System::Drawing::Point(421, 21);
			this->cbSearchFilter->Name = L"cbSearchFilter";
			this->cbSearchFilter->Size = System::Drawing::Size(142, 25);
			this->cbSearchFilter->TabIndex = 7;
			//
			// grpSearch
			//
			this->grpSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->grpSearch->Controls->Add(this->lblKeywords);
			this->grpSearch->Controls->Add(this->lblSearchFilter);
			this->grpSearch->Controls->Add(this->txtSearchKeywords);
			this->grpSearch->Controls->Add(this->cbSearchFilter);
			this->grpSearch->Controls->Add(this->btnSearch);
			this->grpSearch->Location = System::Drawing::Point(11, 128);
			this->grpSearch->Name = L"grpSearch";
			this->grpSearch->Size = System::Drawing::Size(706, 61);
			this->grpSearch->TabIndex = 100;
			this->grpSearch->TabStop = false;
			this->grpSearch->Text = L"tìm kiếm";
			//
			// lblKeywords
			//
			this->lblKeywords->AutoSize = true;
			this->lblKeywords->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblKeywords->Location = System::Drawing::Point(26, 25);
			this->lblKeywords->Name = L"lblKeywords";
			this->lblKeywords->Size = System::Drawing::Size(57, 17);
			this->lblKeywords->TabIndex = 3;
			this->lblKeywords->Text = L"từ khóa";
			//
			// lblSearchFilter
			//
			this->lblSearchFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblSearchFilter->AutoSize = true;
			this->lblSearchFilter->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSearchFilter->Location = System::Drawing::Point(355, 24);
			this->lblSearchFilter->Name = L"lblSearchFilter";
			this->lblSearchFilter->Size = System::Drawing::Size(60, 17);
			this->lblSearchFilter->TabIndex = 3;
			this->lblSearchFilter->Text = L"tìm theo";
			//
			// btnSearch
			//
			this->btnSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSearch->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSearch->Location = System::Drawing::Point(608, 22);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(92, 25);
			this->btnSearch->TabIndex = 100;
			this->btnSearch->Text = L"TÌM KIẾM";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MainForm::btnSearch_Click);
			//
			// grpInfo
			//
			this->grpInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->grpInfo->Controls->Add(this->lblStudentName);
			this->grpInfo->Controls->Add(this->txtStudentName);
			this->grpInfo->Controls->Add(this->lblStudentScore);
			this->grpInfo->Controls->Add(this->btnAdd);
			this->grpInfo->Controls->Add(this->txtStudentScore);
			this->grpInfo->Controls->Add(this->btnDelete);
			this->grpInfo->Controls->Add(this->lblStudentDateOfBirth);
			this->grpInfo->Controls->Add(this->btnUpdate);
			this->grpInfo->Controls->Add(this->lblStudentClass);
			this->grpInfo->Controls->Add(this->txtStudentID);
			this->grpInfo->Controls->Add(this->txtStudentDateOfBirth);
			this->grpInfo->Controls->Add(this->lblStudentID);
			this->grpInfo->Controls->Add(this->txtStudentClass);
			this->grpInfo->Location = System::Drawing::Point(11, 11);
			this->grpInfo->Name = L"grpInfo";
			this->grpInfo->Size = System::Drawing::Size(706, 111);
			this->grpInfo->TabIndex = 100;
			this->grpInfo->TabStop = false;
			this->grpInfo->Text = L"thông tin";
			//
			// dgvStudents
			//
			this->dgvStudents->AllowUserToAddRows = false;
			this->dgvStudents->AllowUserToDeleteRows = false;
			this->dgvStudents->AllowUserToResizeRows = false;
			this->dgvStudents->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgvStudents->BackgroundColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::DodgerBlue;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvStudents->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvStudents->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvStudents->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->clmnIndex,
					this->clmnName, this->clmnClass, this->clmnDateOfBirth, this->clmnId, this->clmnScore
			});
			this->dgvStudents->Location = System::Drawing::Point(11, 195);
			this->dgvStudents->Name = L"dgvStudents";
			this->dgvStudents->ReadOnly = true;
			this->dgvStudents->Size = System::Drawing::Size(706, 292);
			this->dgvStudents->TabIndex = 100;
			this->dgvStudents->CellMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::dgvStudents_CellMouseDoubleClick);
			//
			// clmnIndex
			//
			this->clmnIndex->HeaderText = L"STT";
			this->clmnIndex->Name = L"clmnIndex";
			this->clmnIndex->ReadOnly = true;
			this->clmnIndex->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->clmnIndex->Width = 50;
			//
			// clmnName
			//
			this->clmnName->HeaderText = L"TÊN";
			this->clmnName->Name = L"clmnName";
			this->clmnName->ReadOnly = true;
			this->clmnName->Width = 150;
			//
			// clmnClass
			//
			this->clmnClass->HeaderText = L"LỚP";
			this->clmnClass->Name = L"clmnClass";
			this->clmnClass->ReadOnly = true;
			this->clmnClass->Width = 70;
			//
			// clmnDateOfBirth
			//
			this->clmnDateOfBirth->HeaderText = L"NGÀY SINH";
			this->clmnDateOfBirth->Name = L"clmnDateOfBirth";
			this->clmnDateOfBirth->ReadOnly = true;
			this->clmnDateOfBirth->Width = 120;
			//
			// clmnId
			//
			this->clmnId->HeaderText = L"MÃ SV";
			this->clmnId->Name = L"clmnId";
			this->clmnId->ReadOnly = true;
			//
			// clmnScore
			//
			this->clmnScore->HeaderText = L"ĐIỂM";
			this->clmnScore->Name = L"clmnScore";
			this->clmnScore->ReadOnly = true;
			//
			// MainForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 499);
			this->Controls->Add(this->dgvStudents);
			this->Controls->Add(this->grpInfo);
			this->Controls->Add(this->grpSearch);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(744, 538);
			this->Name = L"MainForm";
			this->Text = L"QUẢN LÍ SINH VIÊN";
			this->grpSearch->ResumeLayout(false);
			this->grpSearch->PerformLayout();
			this->grpInfo->ResumeLayout(false);
			this->grpInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStudents))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion
	/// <summary>
	/// Update data table
	/// </summary>
	/// <param name="stList">List to updates</param>
	/// <returns></returns>
	private: System::Void updateGridView(List<StudentContainer^>^ stList) {
		dgvStudents->Rows->Clear();
		for (int i = 0; i < stList->Count; i++) {
			StudentContainer^ current = stList[i];
			DataGridViewRow^ row = gcnew DataGridViewRow();
			row->CreateCells(this->dgvStudents,
				i,
				current->Name,
				current->Class,
				current->DateOfBirth.ToShortDateString(),
				current->ID,
				current->Score);
			this->dgvStudents->Rows->Add(row);
		}
	}
	/// <summary>
	/// Double click on any row to view their data
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void dgvStudents_CellMouseDoubleClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e) {
		//Console::WriteLine(e->RowIndex);
		//TODO: Display selected

		//read data from list and display them on textboxes
		int index = dgvStudents->CurrentRow->Index;
		txtStudentID->Text = dgvStudents->Rows[index]->Cells["clmnId"]->Value->ToString();
		txtStudentClass->Text = dgvStudents->Rows[index]->Cells["clmnClass"]->Value->ToString();
		txtStudentDateOfBirth->Text = dgvStudents->Rows[index]->Cells["clmnDateOfBirth"]->Value->ToString();
		txtStudentName->Text = dgvStudents->Rows[index]->Cells["clmnName"]->Value->ToString();
		txtStudentScore->Text = dgvStudents->Rows[index]->Cells["clmnScore"]->Value->ToString();
	}
	/// <summary>
	/// Add new student on btnAdd clicked
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {

		String^ stName = txtStudentName->Text;
		String^ stID = txtStudentID->Text;
		String^ stClass = txtStudentClass->Text;
		double stScore;
		DateTime stDateOfBirth;
		//validate data
		if (stName->Length < 3) {
			MessageBox::Show(L"Tên quá ngắn!");
			return;
		}
		if (stID->Length < 3) {
			MessageBox::Show(L"Mã SV quá ngắn!");
			return;
		}
		if (!DateTime::TryParse(txtStudentDateOfBirth->Text, stDateOfBirth)) {
			MessageBox::Show(L"Lỗi định dạng ngày tháng!");
			return;
		}
		if (!double::TryParse(txtStudentScore->Text, stScore)) {
			MessageBox::Show(L"Lỗi định dạng điểm, chỉ nhập số thực!");
			return;
		}
		if (stScore > 10.0 || stScore < 0.0) {
			MessageBox::Show(L"0 > điểm < 10!");
			return;
		}
		if (students.FindStudents(stID, BY_ID, false)->Count > 0) {
			MessageBox::Show(L"SV mã " + stID + L" đã tồn tại!");
			return;
		}
		students.AddStudent(StudentContainer(stName, stDateOfBirth, stID, stClass, stScore));
		updateGridView(students.GetStudentList());
		students.WriteFile();
	}
	/// <summary>
	/// Delete selected student
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) {
		//get student list
		List<StudentContainer^>^ stList = students.GetStudentList();
		//if list is empty, exit
		if (dgvStudents->SelectedRows->Count < 1)
			return;
		//get selected student on table
		int index = dgvStudents->CurrentRow->Index;
		String^ stID = dgvStudents->Rows[index]->Cells[4]->Value->ToString();

		//find student in list base on selected student's ID
		List<StudentContainer^>^ resultList = students.FindStudents(stID, BY_ID, false);
		//no result
		if (resultList->Count < 1)
			return;
		//then remove it
		stList->Remove(resultList[0]);
		updateGridView(students.GetStudentList());
		students.WriteFile();
	}
	/// <summary>
	/// Update selected student
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void btnUpdate_Click(System::Object^  sender, System::EventArgs^  e) {
		//get student list
		List<StudentContainer^>^ stList = students.GetStudentList();
		//return if list is empty
		if (dgvStudents->SelectedRows->Count < 1)
			return;

		//get selected student on table
		int index = dgvStudents->CurrentRow->Index;
		String^ stID = dgvStudents->Rows[index]->Cells[4]->Value->ToString();

		//find student in list base on selected student's ID
		List<StudentContainer^>^ resultList = students.FindStudents(stID, BY_ID, false);
		//no result
		if (resultList->Count < 1)
			return;

		StudentContainer^ editingStudent = gcnew StudentContainer();
		StudentContainer^ selectedStudent = resultList[0];

		editingStudent->Name = txtStudentName->Text;
		editingStudent->Class = txtStudentClass->Text;
		editingStudent->ID = txtStudentID->Text;
		//validate data
		if (editingStudent->Name->Length < 3) {
			MessageBox::Show(L"Tên quá ngắn!");
			return;
		}
		if (editingStudent->ID->Length < 3) {
			MessageBox::Show(L"Mã SV quá ngắn!");
			return;
		}
		if (!DateTime::TryParse(txtStudentDateOfBirth->Text, editingStudent->DateOfBirth)) {
			MessageBox::Show(L"Lỗi định dạng ngày tháng!");
			return;
		}
		if (!double::TryParse(txtStudentScore->Text, editingStudent->Score)) {
			MessageBox::Show(L"Lỗi định dạng điểm, chỉ nhập số thực!");
			return;
		}
		if (editingStudent->Score > 10.0 || editingStudent->Score < 0.0) {
			MessageBox::Show(L"0 > điểm < 10!");
			return;
		}
		/*if (students.FindStudents(editingStudent->ID, BY_ID, false)->Count > 0) {
			MessageBox::Show(L"SV mã " + stID + L" đã tồn tại!");
			return;
		}*/
		//update data
		selectedStudent->Name = editingStudent->Name;
		selectedStudent->ID = editingStudent->ID;
		selectedStudent->Class = editingStudent->Class;
		selectedStudent->DateOfBirth = editingStudent->DateOfBirth;
		selectedStudent->Score = editingStudent->Score;

		updateGridView(students.GetStudentList());
		students.WriteFile();
	}
	/// <summary>
	/// Search for student base on Name/Class/ID
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e) {
		SearchMethod sm = SearchMethod::BY_NAME;
		Boolean wrappedAround = false;
		switch (cbSearchFilter->SelectedIndex)
		{
			case 0:
				sm = SearchMethod::BY_NAME;
				wrappedAround = true;
				break;
			case 1:
				sm = SearchMethod::BY_CLASS;
				wrappedAround = true;
				break;
			case 2:
				sm = SearchMethod::BY_ID;
				wrappedAround = false;
				break;
			default:
				break;
		}

		List<StudentContainer^>^ resultList = students.FindStudents(txtSearchKeywords->Text, sm, wrappedAround);
		updateGridView(resultList);
	}
	};
}
