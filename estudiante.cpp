#include "estudiante.h"

Estudiante::Estudiante() {

}

void Estudiante::SetNombre(string n) {
   nombre = n;
}

string Estudiante::GetNombre() {

   return nombre; 
}

void Estudiante::SetCedula(string ci) {
   cedula = ci;
}

string Estudiante::GetCedula() {

   return cedula; 
}

int Estudiante::TerminalCedula() {

   char ultimoDigito = cedula[cedula.length() - 1];
   int i = ultimoDigito - '0'; // transformamos el digito a entero

   return i;
}

void Estudiante::ProcesarVotos() {

   // creamos los puestos a votar
   Voto presidente;
   Voto secretario;
   Voto voceroA;
   Voto voceroB;

   // ingresamos los cargos
   presidente.SetCargo("Presidente");
   secretario.SetCargo("Secretario");
   voceroA.SetCargo("Vocero A");
   voceroB.SetCargo("Vocero B");

   // los agregamos a la pila en orden
   
   votos.Insertar(voceroB); 
   votos.Insertar(voceroA); 
   votos.Insertar(secretario); 
   votos.Insertar(presidente); 

   Pila<Voto> votosAux;

   while(true) {

      // imprimimos las opciones al usuario
      cout<<"\n Por que cargo desea votar?\n";
      cout<<"\n 1 - "<<presidente.GetCargo();
      cout<<"\n 2 - "<<secretario.GetCargo();
      cout<<"\n 3 - "<<voceroA.GetCargo();
      cout<<"\n 4 - "<<voceroB.GetCargo()<<endl;

      string cargoElegido;

      cout<<"\n > Ingrese el numero: ";
      getline(cin, cargoElegido);

      Menu menu;

      if (!menu.esNumero(cargoElegido)) {

         cout<<"\n\n Opcion Invalida: La entrada solo puede ser un numero!\n"; 

      } else {
         
         int cantidadVotos = votos.Contar();

         if ( stoi(cargoElegido) < 1 || stoi(cargoElegido) >  cantidadVotos ) {

            cout<<"\n\n Opcion Invalida: Escoja uno de los cargos que son mostrados!\n"; 

         }  else {
            Voto votoAux;

            int cantidadCargos = votos.Contar();

            for (int i = 1; i <= cantidadCargos; i++ ) {

               votos.Remover(votoAux);

               if ( i == stoi(cargoElegido) ) {
                   
                  string valorVoto;

                  cout<<"\n > Ingrese su voto para el cargo de "<<votoAux.GetCargo()<<": ";
                  getline(cin, valorVoto);

                  votoAux.SetVoto(valorVoto);
               }

               // asignamos temporalmente a una pila auxiliar
               votosAux.Insertar(votoAux);
            }

            // reordenamos la pila original
            for ( int j = 0; j < cantidadCargos; j++ ) {

               votosAux.Remover(votoAux);
               votos.Insertar(votoAux);

            }

            string procesarOtro; 

            // preguntamos si desea procesar otro
            while( true ) {

               cout<<"\n > Desea procesar otro voto? s/n: ";
               getline(cin, procesarOtro);

               if ( procesarOtro == "s" || procesarOtro == "n" ) {
                  break;
               }

               cout<<"\n\n Ingrese una opcion valida!\n";
               cout<<" Escriba 's' para SI, 'n' para NO.\n";
            }

            // si no quiere procesar otro entonces terminamos el ciclo
            if ( procesarOtro == "n" ) {
               break;
            }

         }


      }

   }

   cout<<"\n Votos procesados satisfactoriamente!\n";
}

void Estudiante::ListarVotos() {

   int cantidadVotos = votos.Contar();

   Pila<Voto> votosAux;
   Voto votoAux;

   for ( int i = 0; i < cantidadVotos; i++ ) {

      votos.Remover(votoAux);

      string voto = votoAux.GetVoto();

      if ( !voto.empty() ) {

         cout<<"\n       - Cargo: "<<votoAux.GetCargo()<<endl;
         cout<<"         Voto: "<<voto<<endl;
      }

   }

   // reordenamos la pila de votos original
   for ( int j = 0; j < cantidadVotos; j++ ) {

      votosAux.Remover(votoAux);

      votos.Insertar(votoAux);
   }
}
