#include "instituto.h"

Instituto::Instituto() {}

void Instituto::MostrarTerminales() {

   cout<<"\n Terminales disponibles: ";

   for (int i = 0; i < contador; i++) {

      cout<<tcDisponibles[i];

      if ( i < contador - 1 ) {
         cout<<", ";
      }

   }

   cout<<"\n";
}

bool Instituto::OcuparTerminal(int n) {

   bool encontrado = false;
   int posicion = 0;

   int t;

   // Buscamos la posicon del numero en el arreglo
   for (int i = 0; i < contador; i++) {

      if ( n == tcDisponibles[i] ) {

         posicion = i;
         encontrado = true;
         t = tcDisponibles[i];
         break;
      }

   }

   // removemos al numero escogido para que ya no se le muestre al usuario
   if (encontrado) {

      for (int j = posicion; j < contador; j++) {
         tcDisponibles[j] = tcDisponibles[j + 1];

         if ( j + 1 == contador ) {

            tcDisponibles[j] = t; 
         }
      }

      contador--;
   }


   return encontrado;
}

void Instituto::DesocuparTerminal(int t) {

   int n = sizeof(tcDisponibles) / sizeof(tcDisponibles[0]);
   int posicion;

   bool mismaPosicion = false;

   // buscamos la posicion del numero
   for ( int i = 0; i < n; i++ ) {

      if ( tcDisponibles[i] == t && i != t ) {
         posicion = i;
      }

      /* if (tcDisponibles[i] == t && i == t ) { */
      /*    mismaPosicion = true; */
      /* } */
   }

   if ( t == 9 ) {

      contador++;

   } else {

      // reubicamos su posicion

      int reserva;


      for (int j = posicion; j > 0; j-- ) {

         if ( j <= t && tcDisponibles[j - 1] < tcDisponibles[j] && j <= contador ) {
         
            break;
         }

         reserva = tcDisponibles[j - 1];
         tcDisponibles[ j - 1 ] = tcDisponibles[j];

         tcDisponibles[j] = reserva;
      }

      contador++;
   }
}

void Instituto::NuevaMesa() {

   string nombreMesa, terminalCI;
   Menu menu = Menu();

   while(true) {

      // Pedimos al usuario el nombre de la mesa
      cout<<"\n > Ingrese el nombre de la mesa: ";
      getline(cin, nombreMesa);
      
      if ( ValidarNombreMesaUnico(nombreMesa) ) {
      
         cout<<"\n La mesa con el nombre "<<nombreMesa<<" ya existe!"<<endl;

      } else {

         // Mostramos los numeros de cedula disponibles al usuario, de los cuales debe escoger uno para la nueva mesa
         MostrarTerminales();

         cout<<"\n > Ingrese el terminal de la cedula para los votantes: ";
         getline(cin, terminalCI);

         cout<<endl;

         if (!menu.esNumero(terminalCI) || terminalCI.length() > 1) {

            cout<<"\n La terminal de cedula debe ser un unico numero entre 0 y 9!\n";

         } else {

            if (!OcuparTerminal(stoi(terminalCI))) {

               cout<<"\n Las cedulas que terminan en "<<terminalCI<<" ya estan en uso por otra mesa!\n";

            } else {

               // Creamos el objeto mesa
               Mesa nuevaMesa = Mesa();
               nuevaMesa.SetNombre(nombreMesa);
               nuevaMesa.SetTerminalCI(stoi(terminalCI));
               

               // Agremamos la nueva mesa a la lista
               listaMesas.InsComienzo(nuevaMesa);
               break;
            }

         }
      }
      
   }
   
}

void Instituto::ListarMesas() {

   int cantidadMesas = listaMesas.Contar();
   Lista<Mesa> auxiliar;
   Mesa mesaAux;
   
   auxiliar = listaMesas;

   if (listaMesas.Vacia()) {

      cout<<"\n No hay mesas registardas, Presiona 1 para crear una nueva mesa...\n\n"; 
   }

   for ( int i = 0; i < cantidadMesas; i++ ) {

      auxiliar.EliComienzo(mesaAux);

      cout<<"\n *  Nombre: "<<mesaAux.GetNombre()<<endl;
      cout<<"    Cedulas que terminan en: "<<mesaAux.GetTerminalCI()<<endl;
      cout<<"    Votantes: "<<mesaAux.GetCantidadVotantes()<<endl;
   }
}

void Instituto::ProcesarVotante() {

   string nombre, ci;
   int cantidadMesas = listaMesas.Contar();

   if (listaMesas.Vacia() || !listaMesas.ObtProx(listaMesas.ObtPrimero())) {

      cout<<"\n Deben registrarse 2 mesas de votacion como minimo!";
      cout<<"\n Presiona 1 para crear una nueva mesa.\n";

   } else {

      // pedimos los datos del estudiante
      
      while ( true ) {

         cout<<"\n > Ingrese nombre del estudiante: ";
         getline(cin, nombre);

         cout<<"\n > Ingrese cedula del estudiante (Ej: 27138607): ";
         getline(cin, ci);

         // Validamos que la cedula posea el formato correcto
         regex ciPatron("^[0-9]{7,8}$"); 
         
         if (regex_match(ci, ciPatron)) {

            break;
         }

         cout<<"\n Ingrese la cedula en el formato valido! Ejemplo: 28505465."<<endl;

      }

      // creamos el objeto del estudiante
      Estudiante estudiante = Estudiante();

      estudiante.SetNombre(nombre);
      estudiante.SetCedula(ci);

      // buscamos la mesa a la cual va a asignarse el estudiante
      
      Mesa mesaActual = Mesa();

      Lista<Mesa> auxiliar;

      listaMesas.pasarListaAux(listaMesas,auxiliar);

      bool mesaAsignada = false;

      while(true) {

         auxiliar.EliComienzo(mesaActual); 

         if (estudiante.TerminalCedula() == mesaActual.GetTerminalCI()) {

            cout<<"\n Fue asignado a la mesa: "<<mesaActual.GetNombre()<<endl;

            mesaActual.NuevoVotante(estudiante);

            mesaAsignada = true;
         }

         listaMesas.InsComienzo(mesaActual);

         if (auxiliar.Vacia()) {
            break;
         }

      }

      // si no existe una mesa con la terminal de cedula del estudiante, avisar al usuario
      if ( !mesaAsignada ) {

         cout<<"\n No existe una mesa con la terminal de cedula "<<estudiante.TerminalCedula()<<" para el estuditante "<<estudiante.GetNombre()<<"."<<endl;
         cout<<"\n Debe esperar a que una mesa se abra.\n";
      }
    
   }
  
}

void Instituto::ListarVotantes() {

   ListarMesas();

   if (listaMesas.Vacia()) {
      return;
   } 

   int cantidadMesas = listaMesas.Contar();
   string nombreMesa;

   cout<<"\n > Ingrese el nombre de la mesa a consultar: ";
   getline(cin, nombreMesa);

   Lista<Mesa> auxiliar;
   Mesa mesaAux;
   bool mesaEncontrada = false;

   listaMesas.pasarListaAux(listaMesas, auxiliar);

   for ( int i = 0; i < cantidadMesas; i++ ) {
   
      auxiliar.EliComienzo(mesaAux);
   
      if ( mesaAux.GetNombre() == nombreMesa ) {

         mesaEncontrada = true;

         if ( mesaAux.GetCantidadVotantes() == 0 ) {

            cout<<"\n La mesa "<<mesaAux.GetNombre()<<" no posee ningun votante!"<<endl;
            cout<<" Para agregar un nuevo votante presione 2."<<endl;

         } else {

            mesaAux.ListarVotantes();
         }


      }

      listaMesas.InsComienzo(mesaAux);
   }
   
   if (!mesaEncontrada) {
   
      cout<<"\n No existe la mesa: "<<nombreMesa<<endl;
   }

}

bool Instituto::ValidarNombreMesaUnico(string nombreMesa) {

   bool encontrado = false;

   if (listaMesas.Vacia()) {
      return encontrado;
   }

   Lista<Mesa> listaAux;
   Mesa mesaAux;

   int cantidadMesas = listaMesas.Contar();

   listaMesas.pasarListaAux(listaMesas, listaAux);

   for (int i = 0; i < cantidadMesas; i++) {

      listaAux.EliComienzo(mesaAux);

      if (mesaAux.GetNombre() == nombreMesa) {

         encontrado = true;
      }

      listaMesas.InsComienzo(mesaAux);
   }

   return encontrado;
}

void Instituto::EliminarMesa() {

   ListarMesas();

   if (listaMesas.Vacia()) {
      return;
   }

   int cantidadMesas = listaMesas.Contar();
   bool mesaEncontrada = false;

   string nombreMesa;

   cout<<"\n > Ingrese el nombre de la mesa a eliminar: ";
   getline(cin, nombreMesa);

   Lista<Mesa> auxiliar;
   Mesa mesaAux;

   listaMesas.pasarListaAux(listaMesas, auxiliar);

   for ( int i = 0; i < cantidadMesas; i++ ) {

      auxiliar.EliComienzo(mesaAux);

      if ( mesaAux.GetNombre() != nombreMesa) {

         listaMesas.InsComienzo(mesaAux);

      } else {

         mesaEncontrada = true;
         DesocuparTerminal(mesaAux.GetTerminalCI());
      }
   }

   if (!mesaEncontrada) {

      cout<<"\n No existe la mesa: "<<nombreMesa<<endl;

   } else {

      cout<<"\n Mesa "<<nombreMesa<<" eliminada satisfactoriamente!"<<endl;
   }
}


void Instituto::EliminarEstudiante() {

   ListarMesas();

   if (listaMesas.Vacia()) {
      return;
   }

   int cantidadMesas = listaMesas.Contar();
   bool mesaEncontrada = false;

   string nombreMesa;

   cout<<"\n > Ingrese el nombre de la mesa a consultar: ";
   getline(cin, nombreMesa);

   Lista<Mesa> auxiliar;
   Mesa mesaAux;

   listaMesas.pasarListaAux(listaMesas, auxiliar);

   for ( int i = 0; i < cantidadMesas; i++ ) {

      auxiliar.EliComienzo(mesaAux);

      if ( mesaAux.GetNombre() == nombreMesa ) {

         mesaEncontrada = true;

         if ( mesaAux.GetCantidadVotantes() == 0 ) {
            
            cout<<"\n La mesa "<<mesaAux.GetNombre()<<" no posee ningun votante!"<<endl;
            cout<<" Para agregar un nuevo votante presione 2."<<endl;

         } else {

            string ci; // cedula del estudiante a eliminar

            mesaAux.ListarVotantes();

            while( true ) {

               cout<<"\n > Ingrese cedula del estudiante a eliminar (Ej: 27138607): ";
               getline(cin, ci);

               // Validamos que la cedula posea el formato correcto
               regex ciPatron("^[0-9]{7,8}$"); 

               if (regex_match(ci, ciPatron)) {

                  break;
               }

               cout<<"\n Ingrese la cedula en el formato valido! Ejemplo: 28505465."<<endl;

            }

            mesaAux.EliminarVotante(ci);

         }
      }

      listaMesas.InsComienzo(mesaAux);
   }

   if (!mesaEncontrada) {

      cout<<"\n No existe la mesa: "<<nombreMesa<<endl;

   } 
}
