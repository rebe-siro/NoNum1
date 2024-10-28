#ifndef MESAELECTORAL_H
#define MESAELECTORAL_H

#include <vector>
#include <string>
#include "candidato.h"

using namespace std;

class Mesa {

   private:
   	std::vector<Candidato> candidatos;

   public:
    // Constructor
    MesaElectoral() = default;

    // MÃ©todo para registrar un candidato
    void registrarCandidato(const Candidato& candidato);

    // MÃ©todo para mostrar todos los candidatos
    void mostrarCandidatos() const;
      
};

#endif // MESA_ELECTORAL_H_
