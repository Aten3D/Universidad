#ifndef persiana_h
#define persiana_h
#include <iostream>
#include <string>
using namespace std;

class persona{
private:
	string DNI_;
	string Nombre_;
	string Apedillos_;
	string Direccion_;
	string Localidad_;
	string Provincia_;
	string Pais_;

public:
	Persona(
		string DNI;
		string Nombre=" ";
		string Apellidos=" ";
		string Direccion=" ";
		string Localidad=" ";
		string Provincia=" ";
		string Pais=" ";
		);
	string getDNI();
	string getNombre();
	string getApellidos();
	string getDireccion();
	string getLocalidad();
	string getProvincia();
	string getPais();
	void setDNI();
	void setNombre();
	void setApellidos();
	void setDireccion();
	void setLocalidad();
	void setProvincia();
	void setPais();
	void setApellidosyNombre();
};

#endif