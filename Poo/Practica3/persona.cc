#include "persona.h"
#include <string>

using namespace std;

Persona::Persona(
		string DNI,
		string Nombre,
		string Apellidos,
		string Direccion,
		string Localidad,
		string Provincia,
		string Pais){
	DNI_=DNI;
	Nombre_=Nombre;
	Apellidos_=Apellidos;
	Direccion_=Direccion;
	Localidad_=Localidad;
	Provincia_=Provincia;
	Pais_=Pais;
}

string Persona::getDNI(){
	return DNI_;
}

string Persona::getNombre(){
	return Nombre_;
}

string Persona::getApellidos(){
	return Apellidos_;
}

string Persona::getApellidosyNombre(){
	return getApellidos()+", "+getNombre();
}

string Persona::getDireccion(){
	return Direccion_;
}

string Persona::getLocalidad(){
	return Localidad_;
}

string Persona::getProvincia(){
	return Provincia_;
}

string Persona::getPais(){
	return Pais_;
}

void Persona::setDNI(string DNI){
	DNI_ = DNI;
}

void Persona::setNombre(string Nombre){
	Nombre_ = Nombre;
}

void Persona::setApellidos(string Apellidos){
	Apellidos_ = Apellidos;
}

void Persona::setDireccion(string Direccion){
	Direccion_ = Direccion;
}

void Persona::setLocalidad(string Localidad){
	Localidad_ = Localidad;
}

void Persona::setProvincia(string Provincia){
	Provincia_ = Provincia;
}

void Persona::setPais(string Pais){
	Pais_ = Pais;
}





































