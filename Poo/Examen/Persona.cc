#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Persona.h"

	Persona:Persona(string nombre,string apellidos,int edad){
		_nombre=nombre;
		_apellidos=apellidos;
		_edad=edad;
	}

	Persona:Persona(const Persona &p){
		_nombre=p._nombre;
		_apellidos=p._apellidos;
		_edad=p._edad;
	}

	string Persona::getNombre(){return _nombre;}
	string Persona::getApellidos(){return _apellidos;}
	int Persona::getEdad(){return _edad;}
	void Persona::setNombre(){}
	void Persona::setApellidos(){}
	void Persona::setNombre(){}
	
	void Persona::leerPersona(){

	}

	void Persona::escribirPersona(){

	}

