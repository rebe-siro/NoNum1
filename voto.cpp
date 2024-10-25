#include "voto.h"

Voto::Voto() {
   cargo = "";
   voto = "";
}

void Voto::SetCargo(string c) {
   cargo = c;
}

string Voto::GetCargo() {
   return cargo;
}

void Voto::SetVoto(string v) {
   voto = v;
}

string Voto::GetVoto() {
   return voto;
}

