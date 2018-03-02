#include "figura.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

figura::figura(string nombre,int aristas,float area){
	nombre_=nombre;
	aristas_=aristas;
	area_=area;
}

bool figura::setposicion(){
	ifstream file;
	string line;
	struct posicion aux;
	file.open("pene.txt");
	if(file.is_open()){
		while(getline(file,line,',')){
			aux.x=atoi(line.c_str());
			getline(file,line,'\n');
			aux.y=atoi(line.c_str());
			posicion_.push_back(aux);
		}
		file.close();
		return true;
	}
	else{
		cout<<"Eres subnormal o que te pasa"<<endl;
		return false;
	}
}

