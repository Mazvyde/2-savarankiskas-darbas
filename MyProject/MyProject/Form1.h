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

    private: System::String^ failo_vardas = "";

    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::MenuStrip^ menuStrip1;
    private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;

    private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

    protected:

    private:

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->menuStrip1->SuspendLayout();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->Location = System::Drawing::Point(489, 172);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(143, 40);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Save";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // richTextBox1
            // 
            this->richTextBox1->Location = System::Drawing::Point(12, 31);
            this->richTextBox1->Name = L"richTextBox1";
            this->richTextBox1->Size = System::Drawing::Size(458, 227);
            this->richTextBox1->TabIndex = 1;
            this->richTextBox1->Text = L"";
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->Location = System::Drawing::Point(489, 218);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(143, 40);
            this->button2->TabIndex = 4;
            this->button2->Text = L"Close";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
            // 
            // menuStrip1
            // 
            this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
            this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(666, 28);
            this->menuStrip1->TabIndex = 5;
            this->menuStrip1->Text = L"menuStrip1";
            // 
            // aboutToolStripMenuItem
            // 
            this->aboutToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
            this->aboutToolStripMenuItem->Size = System::Drawing::Size(67, 24);
            this->aboutToolStripMenuItem->Text = L"About";
            this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click_1);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(666, 279);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->richTextBox1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->menuStrip1);
            this->DoubleBuffered = true;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"Form1";
            this->Text = L"2 savarankiškas darbas";
            this->TopMost = true;
            this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ turinys = richTextBox1->Text;
        try {
            StreamWriter^ rasymoSrautas = gcnew StreamWriter("text.txt");
            rasymoSrautas->WriteLine(turinys);
            rasymoSrautas->Close();
            MessageBox::Show("Text successfully saved to file.", "File saved");
            richTextBox1->Clear();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error\n" + ex->Message, "Important information");
        }
    }

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    private: System::Void aboutToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
        MessageBox::Show("This program saves your text to file named text.txt. \n If you want to close this program click OK and ten Close",
            "About", MessageBoxButtons::OK);
    }
    }
    ;}
