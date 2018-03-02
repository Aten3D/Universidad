#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>

#include "pedido.h"
#include "mesa.h"
#include "mueble.h"

using namespace std; 

bool Pedido::deletePedido(string modelo){
	list <Mesa>::iterator i;

	for (int i=Mesas_.begin(); i!=Mesas.end(); ++i){
		if(modelo==i->getModelo()){
			Mesas_.erase(i);
			return true;
		}
	}
	return false;
};

bool Pedido::deletePedido(Mesa mesa){

	list<Mesa>::iterator i;

	for (int i=Mesas.begin(); i!=Mesas_.end(); ++i){
		if (mesa.getmodelo()==i->getmodelo()){
			Mesas_.erase(i);
			return true:
		}
	}
	return true;
}

void Pedido::write(){
	string d= "salida.txt":
	list <Mesa>::iterator i;
	ínt i=1;

	ofstream f;
	f.open(d.c_str());

	for (int i=Mesas_.begin(); i!=Mesas_.end(); ++i){
		f<<i<<","<<
	}
}