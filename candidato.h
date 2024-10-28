#ifndef CANDIDATO_H_
#define CANDIDATO_H_
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Clse para representar a un candidato

class Candidato {
	private:
		strign nombre;
		string partido;
		
	public:
		Candidato();
		void setNombre (string n);
		string getNombre ();
		void setPartido (string prd);
		string getPartido ();
		
		void mostrarInformacion() const {
		cout << "Nombre: " << nombre << endl;
        cout << "Partido: " << partido << endl;
		}
};

#endif /* CANDIDATO_H_ */

