#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <iostream>
#include "core/General/Pila.h"
#include "voto.h"
#include "menu.h"

using namespace std;

class Estudiante {

   private:
      string nombre, cedula;
      Pila<Voto> votos; 
      
   public:
      Estudiante();

      void   SetNombre(string n);
      string GetNombre();

      void   SetCedula(string ci);
      string GetCedula();

      int   TerminalCedula(); // retorna el ultimo digito de la cedula
      
      void  ProcesarVotos();
      void  ListarVotos();

};

#endif
