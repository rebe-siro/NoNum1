#include "menu.h"
#include <iostream>
#include <string>

Menu::Menu() {}

bool Menu::esNumero(string& cadena) {

   for (char c : cadena) {
      if (!std::isdigit(c)) {
         return false;
      }
   }

   return true;
}

int Menu::MostrarMenu() {

   string entrada; 

   while(true) {

      cout<<"\n 1 - Crear Mesa\n";
      cout<<" 2 - Procesar Votante\n";
      cout<<" 3 - Listar Mesas\n";
      cout<<" 4 - Listar Votantes\n";
      cout<<" 5 - Eliminar Mesa\n";
      cout<<" 6 - Eliminar Votante\n";

      cout<<"\n 0 - Salir\n";

      cout<<"\n > Ingrese una opcion: ";
      getline(cin, entrada);

      if (esNumero(entrada)) {

         if ( stoi(entrada) >=0 && stoi(entrada) < 7 ) {

            break;

         } else {
            cout<<"\n\n Opcion Invalida: Opcion nro."<<entrada<<" no existe!\n";
         }

      } else {

         cout<<"\n\n Opcion Invalida: La entrada solo puede ser un numero!\n";
      }


   }

   return stoi(entrada);
}
