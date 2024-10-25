#include "mesa.h"

Mesa::Mesa() {
   nombre = "";
   terminalCI = 0;
   cantidadVotantes = 0;
}

void Mesa::SetNombre(string n) {
   nombre = n;
}

string Mesa::GetNombre() {
   return nombre;
}

void Mesa::SetTerminalCI(int tCI) {
   terminalCI = tCI;
}

int Mesa::GetTerminalCI() {
   return terminalCI;
}

void Mesa::SetCanditadVotantes(int cv) {
   cantidadVotantes = cv;
}

int Mesa::GetCantidadVotantes() {
   return cantidadVotantes;
}

void Mesa::NuevoVotante(Estudiante est) {

   cantidadVotantes++;

   est.ProcesarVotos();

   votantes.Insertar(est);
}

void Mesa::ListarVotantes() {

   cout<<" \n Votantes de: "<<nombre<<endl;

   Cola<Estudiante> colaAux;
   Estudiante estudianteAux;

   colaAux = votantes;

   while (true) {

      if (colaAux.Vacia()) {

         break;
      }

      colaAux.Remover(estudianteAux);
      
      cout<<"\n   >  Nombre: "<<estudianteAux.GetNombre()<<endl;
      cout<<"      Cedula: "<<estudianteAux.GetCedula()<<endl;
      cout<<"      Votos: "<<endl;
      estudianteAux.ListarVotos();

   }
}

void Mesa::EliminarVotante( string ci ) {

   Estudiante estudianteAux;
   Cola<Estudiante> colaAux;
   int n = cantidadVotantes;

   bool encontrado = false;

   for ( int i = 0; i < n; i++ ) {

      votantes.Remover(estudianteAux);

      // Al encontrar al estudiante disminuimos el contador de votantes
      if ( estudianteAux.GetCedula() == ci ) {
         
         encontrado = true;
         cantidadVotantes--;

         cout<<"\n Estudiante "<<estudianteAux.GetNombre()<<" eliminado de "<<nombre<<endl;

      } else {

         // en caso de que el estudiante no sea el consultado, se agrega nuevamente
         colaAux.Insertar(estudianteAux);
      }

   }

   // rellenamos la cola original
   for ( int j = 0; j < cantidadVotantes; j++ ) {

      colaAux.Remover(estudianteAux);
      votantes.Insertar(estudianteAux);
   }

   if ( !encontrado ) {
      
      cout<<"\n No se encontro al estudiante con la identificacion CI "<<ci<<endl;
   }

}
