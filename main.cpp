#include "instituto.h"
#include "menu.h"
#include <iostream>

using namespace std;

int main() {

   // Variables
   int entradaMenu;
   bool cerrarPrograma = false;

   // Objetos 
   Instituto instituto = Instituto();
   Menu      menu = Menu();

   while(!cerrarPrograma) { // ciclo en espera por entrada del usuario

      entradaMenu = menu.MostrarMenu(); 

      switch (entradaMenu) {
      
         case 1: // Crear mesa
         
            instituto.NuevaMesa();
            break;

         case 2:

            instituto.ProcesarVotante();
            break;

         case 3:

            instituto.ListarMesas();
            break;

         case 4:

            instituto.ListarVotantes();
            break;

         case 5:

            instituto.EliminarMesa();
            break;

         case 6:

            instituto.EliminarEstudiante();
            break;

         case 0: // Salir

            cerrarPrograma = true;
            break;

         default:
            break;
      }
   }

   return 0;
}
