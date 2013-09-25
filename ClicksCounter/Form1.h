#pragma once

namespace ClicksCounter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  numClicksTextbox;
	private: System::Windows::Forms::RichTextBox^  clickRateTextbox;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numClicksTextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->clickRateTextbox = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->numClicksTextbox, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->clickRateTextbox, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 214)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(362, 469);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(3, 257);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(356, 209);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Click!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// numClicksTextbox
			// 
			this->numClicksTextbox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numClicksTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numClicksTextbox->Location = System::Drawing::Point(3, 3);
			this->numClicksTextbox->Name = L"numClicksTextbox";
			this->numClicksTextbox->ReadOnly = true;
			this->numClicksTextbox->Size = System::Drawing::Size(356, 121);
			this->numClicksTextbox->TabIndex = 1;
			this->numClicksTextbox->Text = L"";
			// 
			// clickRateTextbox
			// 
			this->clickRateTextbox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clickRateTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->clickRateTextbox->Location = System::Drawing::Point(3, 130);
			this->clickRateTextbox->Name = L"clickRateTextbox";
			this->clickRateTextbox->ReadOnly = true;
			this->clickRateTextbox->Size = System::Drawing::Size(356, 121);
			this->clickRateTextbox->TabIndex = 2;
			this->clickRateTextbox->Text = L"";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(362, 469);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		// Kenneth: User added property for the Form1 class here
	private: System::DateTime timeAtStart;

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 static int numClicks=0;
				 static float clickRate=0.0;
				 if(numClicks==0)
				 {
					 timeAtStart = System::DateTime::Now;
				 }

				 numClicks++;

				 System::DateTime timeAtClick = System::DateTime::Now;
				 long long timeSinceStart = timeAtClick.Ticks - timeAtStart.Ticks;
				 //  Ticks are measured in 100 nanosecond intervals
				 clickRate = (float)numClicks / ((float)timeSinceStart/10000000);

				 numClicksTextbox->Text = numClicks.ToString() + " clicks";
				 clickRateTextbox->Text = clickRate.ToString() + " clicks per second";

				 //  Changes the background color of the clickRateTextbox based on clickRate
				 if(clickRate>=7.0)
				 {
					 clickRateTextbox->BackColor = Color::OrangeRed;
				 }
				 else if(clickRate>=6.5)
				 {
					 clickRateTextbox->BackColor = Color::Yellow;
				 }
				 else
				 {
					 clickRateTextbox->BackColor = Color::Azure;
				 }
			 }
};
}

