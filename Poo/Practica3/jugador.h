#ifndef jugador_h
#define jugador_h
#include "persona.h"
#include <string>
#include <list>
#include <fstream>

using namespace std;

struct Apuesta{
	int tipo;
	string valor;
	int cantidad;
};

class Jugador:public Persona{
	private:
		int dinero_;
		string codigoJugador_;
		list<Apuesta> apuestas_;
	public:
		Jugador(
		string DNI,
		string codigoJugador,
		string Nombre="",
		string Apellidos="",
		string Direccion="",
		string Localidad="",
		string Provincia="",
		string Pais=""
		);
		int getDinero();
		string getCodigo();
		void setDinero(int dinero);
		void setCodigo(string codigoJugador);
		list<Apuesta> getApuesta
		s();
		bool setApuestas();
};
#endif