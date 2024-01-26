#pragma once

#include <fstream> // Add this line for file operations

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO; // Add this line for System::IO namespace

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
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::RichTextBox^ richTextBox1;

    protected:

    private:

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(12, 181);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(91, 23);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Save to file";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // richTextBox1
            // 
            this->richTextBox1->Location = System::Drawing::Point(12, 24);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(458, 151);
            this->richTextBox1->TabIndex = 1;
            this->richTextBox1->Text = L"";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(482, 253);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->button1);
            this->Name = L"Form1";
            this->Text = L"2 savarankiškas darbas";
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        //MessageBox::Show("Mygtukas buvo paspaustas!", "Pranešimas");

        String^ turinys = richTextBox1->Text;
        try {
            StreamWriter^ rasymoSrautas = gcnew StreamWriter("text.txt");
            rasymoSrautas->WriteLine(turinys);
            rasymoSrautas->Close();
            MessageBox::Show("Data successfully saved to file.", "File saved");
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error:\n" + ex->Message, "Important information");
        }
    }
    };
};
