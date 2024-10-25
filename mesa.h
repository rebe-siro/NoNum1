#ifndef MESA_H
#define MESA_H

#include <string>
#include "core/General/Cola.h"
#include "estudiante.h"

using namespace std;

class Mesa {

   private:
      
      int    terminalCI, cantidadVotantes;
      string nombre;
      Cola<Estudiante> votantes;

   public:

      Mesa();

      void  SetTerminalCI(int tCI);
      int   GetTerminalCI();

      void   SetNombre(string n);
      string GetNombre();

      void SetCanditadVotantes(int cv);
      int  GetCantidadVotantes();

      void NuevoVotante(Estudiante est);
      void ListarVotantes();
      void EliminarVotante(string ci);
};

#endif
