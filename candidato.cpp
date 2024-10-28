#include "Candidato.h"

Candidato::Candidato() {
	
}

void Candidato::setNombre(string n)
{
	nombre = n;
}

string Candidato::getNombre()
{
	return nombre;
}

void Candidato::setPartido(string prd)
{
	partido = prd;
}

string Candidato::getPartido()
{
	return partido;
}

void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Partido: " << partido << endl;
}
