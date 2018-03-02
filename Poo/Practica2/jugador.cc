#include "persona.h"
#include "jugador.h"
#include <list>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Jugador::Jugador(string DNI,string codigoJugador,string Nombre,string Apellidos,string Direccion,string Localidad,
				string Provincia,string Pais)
				:Persona(DNI,Nombre,Apellidos,Direccion,Localidad,Provincia,Pais){
	setCodigo(codigoJugador);
	setDinero(1000);
}

int Jugador::getDinero(){
	return dinero_;
}

string Jugador::getCodigo(){
	return codigoJugador_;
}

void Jugador::setDinero(int dinero){
	dinero_=dinero;
}

void Jugador::setCodigo(string codigoJugador){
	codigoJugador_=codigoJugador;
}

list<Apuesta> Jugador::getApuestas(){
	return apuestas_;
}

bool Jugador::setApuestas(){
	ifstream file;
	string line;
	struct Apuesta aux;
	file.open((getDNI()+".txt").c_str());
	if(file.is_open()){
		while(getline(file,line,',')){
			aux.tipo=atoi(line.c_str());
			getline(file,line,',');
			aux.valor=line;
			getline(file,line,'\n');
			aux.cantidad=atoi(line.c_str());
			apuestas_.push_back(aux);
		}
		file.close();
		return true;
	}
	else{
		cout<<"Error al abrir el fichero"<<endl;
		return false;
	}
}