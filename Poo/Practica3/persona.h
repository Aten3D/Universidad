#ifndef persiana_h
#define persiana_h
#include <iostream>
#include <string>
using namespace std;

class Persona{
private:
	string DNI_;
	string Nombre_;
	string Apellidos_;
	string Direccion_;
	string Localidad_;
	string Provincia_;
	string Pais_;

public:
	Persona(
		string DNI,
		string Nombre="",
		string Apellidos="",
		string Direccion="",
		string Localidad="",
		string Provincia="",
		string Pais="");
	string getDNI();
	string getNombre();
	string getApellidos();
	string getDireccion();
	string getLocalidad();
	string getProvincia();
	string getPais();
	string getApellidosyNombre();
	void setDNI(string DNI);
	void setNombre(string Nombre);
	void setApellidos(string Apellidos);
	void setDireccion(string Direccion);
	void setLocalidad(string Localidad);
	void setProvincia(string Provincia);
	void setPais(string Pais);

};

#endif