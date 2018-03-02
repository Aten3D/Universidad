#include <iostream>
#include <cstdlib>
#include "dados.h"

int main(){
	Dados d;
	int x,y;
	d.lanzamiento();
	std::cout<<"Lanzamos los dados \n";
	std::cout<<"Dado1 = "<< d.getDado1()<<"\n";
	std::cout<<"Dado2 = "<< d.getDado2()<<"\n";
	std::cout<<"Suma = "<< d.getSuma()<<"\n";
	std::cout<<"\nModifique el valor de los dados:\n";
	std::cout<<"Dado1=";
	std::cin>>x;
	std::cout<<"Dado2=";
	std::cin>>y;
	std::cout<<"\n";
	d.setDado1(x);
	d.setDado2(y);
	std::cout<<"Modificamos los valores de los dados \n";
	std::cout<<"Dado1 = "<< d.getDado1()<<"\n";
	std::cout<<"Dado2 = "<< d.getDado2()<<"\n";
	std::cout<<"Suma = "<< d.getSuma()<<"\n";
	std::cout<<"Diferencia = "<< d.getDiferencia()<<"\n";

}