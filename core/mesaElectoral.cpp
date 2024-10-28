#include "MesaElectoral.h"

using namespace std;

void MesaElectoral::registrarCandidato(const Candidato& candidato) {
    candidatos.push_back(candidato);
    cout << "Candidato " << candidato.getNombre() << " registrado exitosamente." << endl;
}

void MesaElectoral::mostrarCandidatos() const {
    if (candidatos.empty()) {
        cout << "No hay candidatos registrados." << endl;
    } else {
        cout << "Lista de candidatos registrados:" << endl;
        for (const auto& candidato : candidatos) {
            candidato.mostrarInformacion();
            cout << "-------------------------" << endl;
        }
    }
}