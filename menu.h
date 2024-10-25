#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*
 * MENU_H
 *
 *  Esta clase se encarga de desplegar las opciones al usuario, asi como leer
 *  y validar las entradas del mismo.
 *
 * */

class Menu {

   private:

   public:
      Menu();
      bool esNumero(string& cadena);
      int MostrarMenu(); 
};
#endif
