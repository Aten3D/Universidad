#ifndef crupier_h
#define crupier_h
#include <string>
#include "persona.h"

using namespace std;

class Crupier:public Persona{
	private:
		string codigo_;

	public:
		Crupier(
		string DNI,
		string codigo,
		string Nombre="",
		string Apellidos="",
		string Direccion="",
		string Localidad="",
		string Provincia="",
		string Pais="");
		string getCodigo();
		void setCodigo(string codigo);

};
#endif