#ifndef VOTO_H
#define VOTO_H

#include <string>

using namespace std;

class Voto {

   private:
      string cargo, voto;
   
   public:
      Voto();

      void   SetCargo(string c);
      string GetCargo();

      void   SetVoto(string v);
      string GetVoto();

      void   ImprimirVoto();
      
};

#endif
