#ifndef pedido_h
#define pedido_h

#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include "mueble.h"
#include "mesa.h"

using namespace std;

class pedido:public mueble{
	private:
		list <Mesa> Mesa_;
	public:
		pedido();
		inline void addpedido(Mesa mesa){listadoPedidos_.push_back(Mesa);};
		inline int size(){return listadoPedidos_.size();};
		bool deletePedido(string modelo);
		bool deletePedido(Mesa mesa);
		void write();

}

#endif