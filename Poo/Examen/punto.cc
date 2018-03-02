#include "punto"
#include <list>
using namespace std;

Punto::Punto(int x,int y){
	x_=x;
	y_=y;
}

Punto Punto::operator=(const Punto &punto){
	x_=punto.x_;
	y_=punto.y_;
	return *this;
}


Punto operator+(const Punto &punto1, const Punto &punto2){
	return Punto(punto1.x_+punto2.x_, punto1.y_+punto2_y_);
}

Punto operator+(const Punto &punto, int valor){
	return Punto(punto.getx()+valor,punto.gety()+valor);
}

Punto operator+(int valor,const Punto &punto){
	return Punto(valor+punto.getx(),valor+punto.gety());
}

Punto Punto::operator++(void){
	++x_;
	++y_;

	return *this
}

Punto Punto::operator++(int){
	Punto aux = *this;
	x_++;
	y_++;

	return aux;
}


