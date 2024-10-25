#ifndef INSTITUTO_H
#define INSTITUTO_H 

#include <regex>
#include "mesa.h"
#include "menu.h"
#include <cstdio>
#include <string>
#include "core/General/Lista.h"

/*
 * INSTITUTO_H
 *
 * La clase Instituto es aquella que contiene la lista de las mesas
 * de votacion y los metodos asociados a esta.
 *
 * */

class Instituto {

   private:

      int contador = 10;
      int tcDisponibles[10] = {0,1,2,3,4,5,6,7,8,9}; // terminal de cedulas disponibles
      Lista<Mesa> listaMesas;

   public:
      Instituto();
      void MostrarTerminales(); // imprime los terminales de cedulas al usuario
      bool OcuparTerminal(int n); // elimina el numero de la lista cuando es usado en una mesa
      void DesocuparTerminal(int t); // Agrega nuevamente el terminal de cedula de una mesa eliminada
      void NuevaMesa();
      void ListarMesas();
      void ProcesarVotante(); // Este metodo ingresa el votante en la mesa correspondiente segun su ci
      void ListarVotantes(); // Este metodo permite seleccionar mesa y listar sus estudiantes.
      bool ValidarNombreMesaUnico(string nombreMesa);
      void EliminarMesa();
      void EliminarEstudiante();
};

#endif
