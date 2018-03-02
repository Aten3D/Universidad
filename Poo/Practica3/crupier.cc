#include "crupier.h"
#include "persona.h"
#include <string>

using namespace std;

Crupier::Crupier(string DNI,string codigo,string Nombre,string Apellidos,string Direccion,string Localidad ,
				string Provincia,string Pais)
				:Persona(DNI,Nombre,Apellidos,Direccion,Localidad,Provincia,Pais){
	codigo_=codigo;
}

string Crupier::getCodigo(){
	return codigo_;
}

void Crupier::setCodigo(string codigo){
	codigo_=codigo;
}