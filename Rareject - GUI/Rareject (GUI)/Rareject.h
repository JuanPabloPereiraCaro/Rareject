#pragma once

#include "VentanaProcesos.h"
#include "VentanaOpcionesAvanzadas.h"
#include "VentanaAcercaDe.h"
#include "VentanaModulos.h"
#include <msclr\marshal.h>

namespace RarejectGUI {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	public ref class Rareject : public System::Windows::Forms::Form
	{

	public:
		Rareject(void)
		{
			InitializeComponent();

		}
	protected:
		~Rareject()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btnProcesos;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtRuta;
	private: System::Windows::Forms::Button^  btnBuscar;
	private: System::Windows::Forms::Button^  btnInyectar;
	private: System::Windows::Forms::TextBox^  txtPID;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnOpcionesAvanzadas;
	private: System::Windows::Forms::Button^  btnCerrar;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblCloseInject;
	private: System::Windows::Forms::Label^  lblTimerStatus;
	private: System::Windows::Forms::Label^  lblTiempoEspera;
	private: System::Windows::Forms::Button^  btnAcercaDe;
	private: System::ComponentModel::IContainer^  components;
	private: bool currentCheckState = false;
	private: bool currentCBTimerState = false;
	private: System::Windows::Forms::Button^  btnModulos;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: Point offset;
	private: System::Windows::Forms::Timer^  tmInyeccion;
	private: bool dragging;
	private: HANDLE Proceso;
	private: const char *NOMBRE_DLL;
	private: int Tiempo_Restante, Tiempo_Transcurrido;


	void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Rareject::typeid));
				 this->btnProcesos = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->txtRuta = (gcnew System::Windows::Forms::TextBox());
				 this->btnBuscar = (gcnew System::Windows::Forms::Button());
				 this->btnInyectar = (gcnew System::Windows::Forms::Button());
				 this->txtPID = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->btnOpcionesAvanzadas = (gcnew System::Windows::Forms::Button());
				 this->btnCerrar = (gcnew System::Windows::Forms::Button());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->lblCloseInject = (gcnew System::Windows::Forms::Label());
				 this->lblTimerStatus = (gcnew System::Windows::Forms::Label());
				 this->lblTiempoEspera = (gcnew System::Windows::Forms::Label());
				 this->btnAcercaDe = (gcnew System::Windows::Forms::Button());
				 this->btnModulos = (gcnew System::Windows::Forms::Button());
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->tmInyeccion = (gcnew System::Windows::Forms::Timer(this->components));
				 this->SuspendLayout();
				 // 
				 // btnProcesos
				 // 
				 this->btnProcesos->BackColor = System::Drawing::Color::Black;
				 this->btnProcesos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->btnProcesos->ForeColor = System::Drawing::Color::Cyan;
				 this->btnProcesos->Location = System::Drawing::Point(15, 191);
				 this->btnProcesos->Name = L"btnProcesos";
				 this->btnProcesos->Size = System::Drawing::Size(139, 34);
				 this->btnProcesos->TabIndex = 3;
				 this->btnProcesos->Text = L"Buscar proceso";
				 this->btnProcesos->UseVisualStyleBackColor = false;
				 this->btnProcesos->Click += gcnew System::EventHandler(this, &Rareject::btnProcesos_Click);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->BackColor = System::Drawing::SystemColors::MenuText;
				 this->label4->ForeColor = System::Drawing::Color::Cyan;
				 this->label4->Location = System::Drawing::Point(12, 130);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(37, 13);
				 this->label4->TabIndex = 4;
				 this->label4->Text = L"- PID :";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->BackColor = System::Drawing::SystemColors::MenuText;
				 this->label5->Cursor = System::Windows::Forms::Cursors::Arrow;
				 this->label5->ForeColor = System::Drawing::Color::Cyan;
				 this->label5->Location = System::Drawing::Point(12, 100);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(65, 13);
				 this->label5->TabIndex = 5;
				 this->label5->Text = L"- Ruta DLL: ";
				 // 
				 // txtRuta
				 // 
				 this->txtRuta->Enabled = false;
				 this->txtRuta->Location = System::Drawing::Point(93, 97);
				 this->txtRuta->Name = L"txtRuta";
				 this->txtRuta->Size = System::Drawing::Size(216, 20);
				 this->txtRuta->TabIndex = 6;
				 this->txtRuta->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 // 
				 // btnBuscar
				 // 
				 this->btnBuscar->BackColor = System::Drawing::Color::Black;
				 this->btnBuscar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->btnBuscar->ForeColor = System::Drawing::Color::Cyan;
				 this->btnBuscar->Location = System::Drawing::Point(171, 191);
				 this->btnBuscar->Name = L"btnBuscar";
				 this->btnBuscar->Size = System::Drawing::Size(139, 34);
				 this->btnBuscar->TabIndex = 7;
				 this->btnBuscar->Text = L"Buscar DLL";
				 this->btnBuscar->UseVisualStyleBackColor = false;
				 this->btnBuscar->Click += gcnew System::EventHandler(this, &Rareject::btnBuscar_Click);
				 // 
				 // btnInyectar
				 // 
				 this->btnInyectar->BackColor = System::Drawing::Color::Black;
				 this->btnInyectar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->btnInyectar->ForeColor = System::Drawing::Color::Cyan;
				 this->btnInyectar->Location = System::Drawing::Point(170, 326);
				 this->btnInyectar->Name = L"btnInyectar";
				 this->btnInyectar->Size = System::Drawing::Size(139, 33);
				 this->btnInyectar->TabIndex = 8;
				 this->btnInyectar->Text = L"Inyectar";
				 this->btnInyectar->UseVisualStyleBackColor = false;
				 this->btnInyectar->Click += gcnew System::EventHandler(this, &Rareject::btnInyectar_Click);
				 // 
				 // txtPID
				 // 
				 this->txtPID->Enabled = false;
				 this->txtPID->Location = System::Drawing::Point(93, 127);
				 this->txtPID->Name = L"txtPID";
				 this->txtPID->Size = System::Drawing::Size(61, 20);
				 this->txtPID->TabIndex = 9;
				 this->txtPID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->BackColor = System::Drawing::SystemColors::MenuText;
				 this->label1->ForeColor = System::Drawing::Color::Cyan;
				 this->label1->Location = System::Drawing::Point(12, 285);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(0, 13);
				 this->label1->TabIndex = 11;
				 this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				 // 
				 // btnOpcionesAvanzadas
				 // 
				 this->btnOpcionesAvanzadas->BackColor = System::Drawing::Color::Black;
				 this->btnOpcionesAvanzadas->Location = System::Drawing::Point(171, 125);
				 this->btnOpcionesAvanzadas->Name = L"btnOpcionesAvanzadas";
				 this->btnOpcionesAvanzadas->Size = System::Drawing::Size(138, 22);
				 this->btnOpcionesAvanzadas->TabIndex = 14;
				 this->btnOpcionesAvanzadas->Text = L"Opciones avanzadas...";
				 this->btnOpcionesAvanzadas->UseVisualStyleBackColor = false;
				 this->btnOpcionesAvanzadas->Click += gcnew System::EventHandler(this, &Rareject::btnOpcionesAvanzadas_Click);
				 // 
				 // btnCerrar
				 // 
				 this->btnCerrar->BackColor = System::Drawing::SystemColors::MenuText;
				 this->btnCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCerrar.BackgroundImage")));
				 this->btnCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
				 this->btnCerrar->Location = System::Drawing::Point(15, 326);
				 this->btnCerrar->Name = L"btnCerrar";
				 this->btnCerrar->Size = System::Drawing::Size(34, 33);
				 this->btnCerrar->TabIndex = 13;
				 this->btnCerrar->UseVisualStyleBackColor = false;
				 this->btnCerrar->Click += gcnew System::EventHandler(this, &Rareject::btnCerrar_Click);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->BackColor = System::Drawing::SystemColors::MenuText;
				 this->label2->ForeColor = System::Drawing::Color::Cyan;
				 this->label2->Location = System::Drawing::Point(168, 266);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(86, 13);
				 this->label2->TabIndex = 15;
				 this->label2->Text = L"- Close on Inject:";
				 // 
				 // lblCloseInject
				 // 
				 this->lblCloseInject->AutoSize = true;
				 this->lblCloseInject->BackColor = System::Drawing::SystemColors::MenuText;
				 this->lblCloseInject->ForeColor = System::Drawing::Color::Yellow;
				 this->lblCloseInject->Location = System::Drawing::Point(253, 266);
				 this->lblCloseInject->Name = L"lblCloseInject";
				 this->lblCloseInject->Size = System::Drawing::Size(57, 13);
				 this->lblCloseInject->TabIndex = 16;
				 this->lblCloseInject->Text = L"INACTIVO";
				 // 
				 // lblTimerStatus
				 // 
				 this->lblTimerStatus->AutoSize = true;
				 this->lblTimerStatus->BackColor = System::Drawing::SystemColors::MenuText;
				 this->lblTimerStatus->ForeColor = System::Drawing::Color::Cyan;
				 this->lblTimerStatus->Location = System::Drawing::Point(168, 245);
				 this->lblTimerStatus->Name = L"lblTimerStatus";
				 this->lblTimerStatus->Size = System::Drawing::Size(107, 13);
				 this->lblTimerStatus->TabIndex = 17;
				 this->lblTimerStatus->Text = L"- Esperar (segundos):";
				 // 
				 // lblTiempoEspera
				 // 
				 this->lblTiempoEspera->AutoSize = true;
				 this->lblTiempoEspera->BackColor = System::Drawing::SystemColors::MenuText;
				 this->lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;
				 this->lblTiempoEspera->Location = System::Drawing::Point(279, 245);
				 this->lblTiempoEspera->Name = L"lblTiempoEspera";
				 this->lblTiempoEspera->Size = System::Drawing::Size(13, 13);
				 this->lblTiempoEspera->TabIndex = 18;
				 this->lblTiempoEspera->Text = L"0";
				 // 
				 // btnAcercaDe
				 // 
				 this->btnAcercaDe->BackColor = System::Drawing::SystemColors::MenuText;
				 this->btnAcercaDe->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAcercaDe.BackgroundImage")));
				 this->btnAcercaDe->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
				 this->btnAcercaDe->ForeColor = System::Drawing::Color::Cyan;
				 this->btnAcercaDe->Location = System::Drawing::Point(55, 326);
				 this->btnAcercaDe->Name = L"btnAcercaDe";
				 this->btnAcercaDe->Size = System::Drawing::Size(34, 33);
				 this->btnAcercaDe->TabIndex = 19;
				 this->btnAcercaDe->UseVisualStyleBackColor = false;
				 this->btnAcercaDe->Click += gcnew System::EventHandler(this, &Rareject::btnAcercaDe_Click);
				 // 
				 // btnModulos
				 // 
				 this->btnModulos->BackColor = System::Drawing::Color::Black;
				 this->btnModulos->Location = System::Drawing::Point(15, 245);
				 this->btnModulos->Name = L"btnModulos";
				 this->btnModulos->Size = System::Drawing::Size(139, 34);
				 this->btnModulos->TabIndex = 20;
				 this->btnModulos->Text = L"Ver m�dulos del proceso";
				 this->btnModulos->UseVisualStyleBackColor = false;
				 this->btnModulos->Click += gcnew System::EventHandler(this, &Rareject::btnModulos_Click);
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->DefaultExt = L"dll";
				 this->openFileDialog1->Filter = L"Biblioteca din�mica (*.dll)|*.dll";
				 // 
				 // tmInyeccion
				 // 
				 this->tmInyeccion->Interval = 1000;
				 // 
				 // Rareject
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::MenuHighlight;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(325, 371);
				 this->Controls->Add(this->btnModulos);
				 this->Controls->Add(this->btnAcercaDe);
				 this->Controls->Add(this->lblTiempoEspera);
				 this->Controls->Add(this->lblTimerStatus);
				 this->Controls->Add(this->lblCloseInject);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->btnOpcionesAvanzadas);
				 this->Controls->Add(this->btnCerrar);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->txtPID);
				 this->Controls->Add(this->btnInyectar);
				 this->Controls->Add(this->btnBuscar);
				 this->Controls->Add(this->txtRuta);
				 this->Controls->Add(this->label5);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->btnProcesos);
				 this->Cursor = System::Windows::Forms::Cursors::Arrow;
				 this->ForeColor = System::Drawing::Color::Cyan;
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->Name = L"Rareject";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Rareject";
				 this->Load += gcnew System::EventHandler(this, &Rareject::Rareject_Load);
				 this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseDown);
				 this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseMove);
				 this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseUp);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }


	VentanaProcesos ^ Vent_Proc;
	VentanaOpcionesAvanzadas ^ Opc_Av;
	VentanaAcercaDe ^ Vent_Acerca;
	VentanaModulos ^ Vent_Modulos;

	private: System::Void Rareject_Load(System::Object^  sender, System::EventArgs^  e) {

		Vent_Proc = gcnew VentanaProcesos(txtPID);

	}

	private: System::Void btnProcesos_Click(System::Object^  sender, System::EventArgs^  e) {

		Vent_Proc->ShowDialog();

	}

	private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {

		//Muestra la ruta en el label correspondiente si se selecciona un archivo dll
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			txtRuta->Text = openFileDialog1->FileName;

		}

	}

	private: System::Void btnOpcionesAvanzadas_Click(System::Object^  sender, System::EventArgs^  e) {
		int currentTBTimerValue = System::Convert::ToInt32(lblTiempoEspera->Text); //Recibe el valor actual indicado al usuario para el tiempo que se tardar� en inyectar la DLL

		/*Inicializa la ventana de opciones avanzadas con los par�metros que ten�amos previamente, como el estado de los checkbox de "Cerrar tras inyectar" o
		"Injection Timer" as� como el valor (segundos) del slider y la TextBox que lo muestra*/
		Opc_Av = gcnew VentanaOpcionesAvanzadas(currentCheckState, currentCBTimerState, currentTBTimerValue);
		Opc_Av->ShowDialog(); //Muestra la ventana de opciones avanzadas

		//Almacena los valores de los checkbox tras cerrar la ventana de opciones avanzadas
		currentCheckState = Opc_Av->currentState;
		currentCBTimerState = Opc_Av->currentCBTimerState;

		if (Opc_Av->cbCloseOnInject->Checked) { //Muestra la palabra ACTIVO en verde si el checkbox de "Cerrar tras inyectar" est� activado

			lblCloseInject->Text = "ACTIVO";
			lblCloseInject->ForeColor = System::Drawing::Color::Green;


		}
		else { //Muestra la palabra INACTIVO en amarillo si el checkbox est� desactivado

			lblCloseInject->Text = "INACTIVO";
			lblCloseInject->ForeColor = System::Drawing::Color::Yellow;


		}

		if (Opc_Av->cbInjectionTimer->Checked) { //Muestra el valor de retardo en el label asociado al timer si el checkbox est� activado

			lblTiempoEspera->Text = System::Convert::ToString(Opc_Av->Tiempo_Segundos);

			if (lblTiempoEspera->Text == "0") { //Se muestra el valor en amarillo si es 0

				lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;

			}
			else { //Si no se muestra en verde

				lblTiempoEspera->ForeColor = System::Drawing::Color::Green;

			}

		}
		else { //Reinicia el formato y valor si el checkbox del timer est� desactivado

			lblTiempoEspera->Text = "0";
			lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;

		}

	}

	private: System::Void btnInyectar_Click(System::Object^  sender, System::EventArgs^  e) {

		//Convertimos las variables a los tipos necesarios a partir de las labels de la interfaz
		marshal_context^ context = gcnew marshal_context();
		DWORD PID = txtPID->Text->Equals("") ? -1 : System::Convert::ToInt32(txtPID->Text);
		NOMBRE_DLL = context->marshal_as<const char*, String>(txtRuta->Text);

		Proceso = OpenProcess(PROCESS_ALL_ACCESS, false, PID);

		if (Proceso && !txtRuta->Text->Equals("") && PID != -1) {

			if (Opc_Av && Opc_Av->Tiempo_Segundos > 0) {

				tmInyeccion = gcnew Timer();

				tmInyeccion->Interval = 1000;

				tmInyeccion->Tick += gcnew System::EventHandler(this, &Rareject::Tick_Increaser);

				int Tiempo_Restante = Opc_Av->Tiempo_Segundos;

				tmInyeccion->Start();

			} else {

				Inyectar();

				if (Opc_Av && Opc_Av->cbCloseOnInject->Checked) {

					this->Close();

				}

			}

		}
		else if (txtRuta->Text->Equals("") && PID == -1) {

			MessageBox::Show("No se han seleccionado la DLL ni el PID del proceso", "Faltan par�metros", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else if (txtRuta->Text->Equals("")) {

			MessageBox::Show("No se ha seleccionado la DLL", "Falta la ruta", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else if (PID == -1) {

			MessageBox::Show("No se ha seleccionado el proceso previamente", "Falta el PID", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else {

			/* Ventanita de error ya que en este caso no habr�a ning�n proceso existente. (En nuestro caso no hace
			falta, ya que gracias a la opci�n de escoger un proceso de la lista de procesos, siempre escogeremos un
			proceso existente)*/
			MessageBox::Show(("No existe  ning�n proceso con PID " + PID), "No existe el proceso", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}

	}

	private: System::Void btnModulos_Click(System::Object^  sender, System::EventArgs^  e) {


		if (Vent_Proc->Proceso_Elegido == false) {

			MessageBox::Show(("No se pueden cargar los m�dulos ya que no hay proceso seleccionado."), "Selecciona un proceso...", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else {

			DWORD PID = System::Convert::ToInt32(txtPID->Text);

			Vent_Modulos = gcnew VentanaModulos(PID);

			Vent_Modulos->ShowDialog();

		}
	}

	private: System::Void btnCerrar_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Close();

	}

	private: System::Void Rareject_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		this->dragging = true;
		this->offset = Point(e->X, e->Y);


	}

	private: System::Void Rareject_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X,
				currentScreenPos.Y - this->offset.Y);
		}

	}

	private: System::Void Rareject_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		this->dragging = false;

	}

	private: System::Void btnAcercaDe_Click(System::Object^  sender, System::EventArgs^  e) {

		Vent_Acerca = gcnew VentanaAcercaDe();

		Vent_Acerca->ShowDialog();

	}

	private: System::Void Tick_Increaser(System::Object^  sender, System::EventArgs^  e) {

		Tiempo_Transcurrido++;

		if (Tiempo_Transcurrido == Opc_Av->Tiempo_Segundos) {

			tmInyeccion->Stop();

			Inyectar();

			if (Opc_Av && Opc_Av->cbCloseOnInject->Checked) {

				this->Close();

			}
			else {

				Opc_Av->Tiempo_Segundos = 0;
				lblTiempoEspera->Text = Convert::ToString(0);
				lblTiempoEspera->ForeColor = Color::Yellow;

			}

		}

	}

	private: System::Void Inyectar() {

		LPVOID LoadLibraryAddress = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

		LPVOID ResMemDLL = VirtualAllocEx(Proceso, NULL, strlen(NOMBRE_DLL), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		WriteProcessMemory(Proceso, ResMemDLL, NOMBRE_DLL, strlen(NOMBRE_DLL), NULL);

		HANDLE HiloRemoto = CreateRemoteThread(Proceso, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddress, ResMemDLL, 0, NULL);

		WaitForSingleObject(HiloRemoto, INFINITE);

		VirtualFreeEx(Proceso, ResMemDLL, strlen(NOMBRE_DLL), MEM_RELEASE);

		CloseHandle(HiloRemoto);
		CloseHandle(Proceso);

	}

};
}
