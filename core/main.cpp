#include "candidato.h"
#include "mesaElectoral.h"
#include <iostream>

using namespace std;

int main() {
	MesaElectoral mesa;
    int opcionInicial;
    
    // Menú inicial
    cout << "Bienvenido al sistema de gestión de la mesa electoral." << endl;
    cout << "1. Entrar al sistema de gestión de candidatos" << endl;
    cout << "2. Salir" << endl;
    cout << "Elige una opción: ";
    cin >> opcionInicial;

    if (opcionInicial == 1) {
        int opcion;
        do {
            cout << "\n--- Menú de gestión de candidatos ---" << endl;
            cout << "1. Registrar candidato" << endl;
            cout << "2. Mostrar candidatos" << endl;
            cout << "3. Salir" << endl;
            cout << "Elige una opción: ";
            cin >> opcion;

            switch(opcion) {
                case 1: {
                    string nombre, partido;

                    cout << "Nombre del candidato: ";
                    cin.ignore(); // Limpiar el buffer de entrada
                    getline(cin, nombre);
                    cout << "Partido del candidato: ";
                    getline(cin, partido);

                    Candidato candidato(nombre, partido);
                    mesa.registrarCandidato(candidato);
                    break;
                }
                case 2:
                    mesa.mostrarCandidatos();
                    break;
                case 3:
                    cout << "Saliendo del sistema de gestión de candidatos." << endl;
                    break;
                default:
                    cout << "Opción no válida. Intenta de nuevo." << endl;
            }
        } while (opcion != 3);
    } else if (opcionInicial == 2) {
        cout << "Saliendo del programa." << endl;
    } else {
        cout << "Opción no válida. Terminando el programa." << endl;
    }

    return 0;
}