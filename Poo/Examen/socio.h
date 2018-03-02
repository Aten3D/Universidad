#ifndef pene_E
#define pene_E
#include <string>
#include <iostream>
#include "Persona.h"

class Socio:public Persona{
	private:
		int _donativo;
	public:
		Socio(string nombre="",string apellidos="",edad="");
		int getDonativo()const{return _donativo;};
		void setDonativo(int donativo)const{donativo=_donativo;};
		Socio(Socio const &s);
		Socio operator=(const Socio &s);
		friend istream &operator>>{istream &i, Socio &s};
		friend ostream &operator<<(ostream &o, Socio &o);
}