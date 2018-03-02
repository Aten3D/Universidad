#include <cstdlib>
#include <ctime>
#include "dados.h"

	Dados::Dados(){
 	
 		srand(time(NULL));
 		d1_=1;
 		d2_=1;
 		l1_=0; //numero de lanzamientos
 		l2_=0;
 		t1_=0; //suma de los valores del dado
 		t2_=0;


	}

	int Dados::getDado1(){//Retorna el valor del dado de la parte privada

		return d1_;

	}


	int Dados::getDado2(){//Igual que la anterior

		return d2_;

	}

	void Dados::lanzamiento(){//Asigna el valor a los dos dados

		d1_=(rand()%6)+1;
		d2_=(rand()%6)+1;

		ultimosd1_[getLanzamientos1()%5]=d1_;
		ultimosd1_[getLanzamientos2()%5]=d2_;

		l1_++;
		l2_++;

		t1_+=d1_;
		t2_+=d2_;


	}

	bool Dados::setDado1(int x){//Pide al usuario que introduzca por pantalla un valor comprendido entre 1 y 6 y comprueba si este es correcto

		if(1<=x && x<=6){
			d1_=x;

			ultimosd1_[getLanzamientos1()%5]=d1_;
			l1_++;
			t1_+=d1_;
			
			return true;
		}
		return false;

	}

	bool Dados::setDado2(int y){//Igual que la anterior

		if(1<=y && y<=6){
			d2_=y;

			ultimosd2_[getLanzamientos2()%5]=d2_;
			l2_++;
			t2_+=d2_;

			return true;
		}
		return false;

	}

	int Dados::getSuma(){

		return d1_+d2_;
	}

	int Dados::getDiferencia(){
		if(d1_>d2_) return d1_-d2_;
		else return d2_-d1_;
	}

	int Dados::getLanzamientos1(){
		return l1_;
	}

	int Dados::getLanzamientos2(){
		return l2_;
	}

	float Dados::getmedia1(){
		if(l1_){
			return (float)t1_/(float)l1_;
		}
		else {
			return 0;
		}
	}

	float Dados::getmedia2(){
		if(l2_){
			return (float)t2_/(float)l2_;
		}
		else {
			return 0;
		}
	}

	void Dados::getUltimos1(int* ultimosd1){
		for(int i=0;i<5;i++){
			ultimosd1[i]=ultimosd1_[i];
		}
	}

	void Dados::getUltimos2(int* ultimosd2){
		for(int i=0;i<5;i++){
			ultimosd2[i]=ultimosd2_[i];
		}
	}