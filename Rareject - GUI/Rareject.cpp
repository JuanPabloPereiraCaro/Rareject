/*----------------------------------------------------------------------*/
/* - Realizado por: Juan Pablo Pereira Caro & Diego Rodríguez Vicente   */
/* - Clase: 2º DAM - IES TEIS                                           */
/* - Año: 2018                                                          */
/* ---> Proyecto de fin de grado <---                                   */
/*----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool Inyectar(DWORD PID, char *NOMBRE_DLL);

int main() {

	string NOMBRE_DLL;
	int PID, OPCION_ESCOGIDA;

	cout << "|--------------------------------------------------------|\n\n";
	cout << "|    Juan Pablo Pereira Caro y Diego Rodriguez Vicente   |\n\n";
	cout << "|                       Rareject v.0.0.1                 |\n\n";
	cout << "|--------------------------------------------------------|\n\n";
	cout << "|---------------------MENU PRINCIPAL---------------------|\n\n";
	cout << "|* 1. Inyectar DLL                                       |\n\n";
	cout << "|* 99. Salir                                             |\n\n";
	cout << "|--------------------------------------------------------|\n\n";
	cout << "|-> Introduce la opcion escogida:";
	cin >> OPCION_ESCOGIDA;
	cout << "|                                                        |\n\n";
	cout << "|--------------------------------------------------------|\n\n";

	if (OPCION_ESCOGIDA == 1) {

		cout << "- Introduce el PID del programa:";
		cin >> PID;
		cout << "- Introduce el nombre del DLL:";
		cin >> NOMBRE_DLL;

		TCHAR ruta[MAX_PATH];
		GetFullPathName((NOMBRE_DLL.c_str()), MAX_PATH, ruta, NULL);

		Inyectar(PID, ruta);

	}



}

bool Inyectar(DWORD PID, char *NOMBRE_DLL) {

	HANDLE Proceso = OpenProcess(PROCESS_ALL_ACCESS, false, PID); 

	if (Proceso) { 

		LPVOID LoadLibraryAddress = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

		LPVOID ResMemDLL = VirtualAllocEx(Proceso, NULL, strlen(NOMBRE_DLL), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		WriteProcessMemory(Proceso, ResMemDLL, NOMBRE_DLL, strlen(NOMBRE_DLL), NULL);

		HANDLE HiloRemoto = CreateRemoteThread(Proceso, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddress, ResMemDLL, 0, NULL);

		WaitForSingleObject(HiloRemoto, INFINITE);

		VirtualFreeEx(Proceso, ResMemDLL, strlen(NOMBRE_DLL), MEM_RELEASE);

		CloseHandle(HiloRemoto);
		CloseHandle(Proceso);

		return true;

	} else {

		/* En caso de que nunca se entre en el while significará que el HANDLE de Proceso devuelve un objeto a NULL */
		cout << "- Error en la selección de proceso, por favor inténtalo de nuevo...";
	}

	return false;
}