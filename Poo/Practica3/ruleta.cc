#include "ruleta.h"
#include <list>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

Ruleta::Ruleta(Crupier crupier) : crupier_(crupier){
	setBanca(1000000);
	bola_=-1;
	crupier_=crupier;
	srand(time(NULL));
}

bool Ruleta::setBanca(int banca){
	if(banca>0){
		banca_=banca;
		return true;
	}
	else{
		return false;
	}
}

bool Ruleta::setBola(int bola){
	if((bola>-1)&&(bola<37)){
		bola_=bola;
		return true;
	}
	else{
		return false;
	}
}

void Ruleta::setCrupier(Crupier crupier){
	crupier_=crupier;
}

void Ruleta::addJugador(Jugador jugador){
	ifstream f;
	jugadores_.push_back(jugador);
	f.open((jugador.getDNI()+".txt").c_str());
	if(f.is_open()){
		ofstream ofile((jugador.getDNI()+".txt").c_str());
	}
}

int Ruleta::deleteJugador(Jugador jugador){
	list<Jugador>::iterator i;
	if(jugadores_.empty()){
		return -1;
	}
	for(i=jugadores_.begin() ; i!=jugadores_.end() ; i++){
		if((*i).getDNI()==jugador.getDNI()){
			jugadores_.erase(i);
			return 1;
		}
	}
	return -2;
		
}



int Ruleta::deleteJugador(string DNI){
	list<Jugador>::iterator i;
	if(jugadores_.empty()){
		return -1;
	}
	for(i=jugadores_.begin(); i!=jugadores_.end();i++){
		if((*i).getDNI()==DNI){
			jugadores_.erase(i);
			return 1;
		}
	}
	return -2;
}



void Ruleta::escribeJugadores(){
	ifstream f;

	f.open("jugadores.txt");
	if(!f.is_open()){
		ofstream f("jugadores.txt");
	}
}

void Ruleta::leeJugadores(){
	ifstream f;
	string l;
	Jugador aux("auxDNI","auxCodigo");
	jugadores_.clear();
	f.open("jugadores.txt");
	if(f.is_open()){
		while(getline(f,l,',')){
			aux.setDNI(l);
			getline(f, l, ',');
			aux.setCodigo(l);
			getline(f, l, ',');
			aux.setNombre(l);
			getline(f, l, ',');
			aux.setApellidos(l);
			getline(f, l, ',');
			aux.setDireccion(l);
			getline(f, l, ',');
			aux.setLocalidad(l);
			getline(f, l, ',');
			aux.setProvincia(l);
			getline(f, l, ',');
			aux.setPais(l);
			getline(f, l, '\n');
			aux.setDinero(atoi(l.c_str()));
			jugadores_.push_back(aux);
		}
		f.close();
	}

	else{
		cout<<"No se ha podido abrir el archivo jugadores.txt"<<endl;
		}

}

void Ruleta::giraRuleta(){
	int bola;
	bola=rand()%37;
	setBola(bola);
}

void Ruleta::getPremios(){
	list<Jugador>::iterator i;
	list<Apuesta> aux;
	list<Apuesta>::iterator j;

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++){
		ifstream ifile(((*i).getDNI()+".txt").c_str(), ios::in);
		(*i).setApuestas();
		aux = (*i).getApuestas();
		for(j=aux.begin(); j!=aux.end(); j++){
        if((*j).tipo==1){
          if(getBola()==atoi(((*j).valor).c_str())){
            (*i).setDinero((*i).getDinero()+((*j).cantidad)*35); 
            setBanca(getBanca()-((*j).cantidad)*35);
            }
           else{
            (*i).setDinero((*i).getDinero()-((*j).cantidad)); 
                   setBanca(getBanca()+((*j).cantidad));
           }
         }
   
        else if((*j).tipo==2){
         int b=getBola();

         if(b==0){
           (*i).setDinero((*i).getDinero()-(*j).cantidad);
                  setBanca(getBanca()+((*j).cantidad));
               }        

         else{
             if((b==2)||(b==4)||(b==6)||(b==8)||(b==10)||(b==11)||(b==13)||(b==15)||(b==17)||(b==20)||(b==22)||(b==24)||(b==26)||(b==28)||(b==29)||(b==31)||(b==33)||(b==35)){
              
                if((*j).valor=="negro")  {
                 (*i).setDinero((*i).getDinero()+(*j).cantidad);
                        setBanca(getBanca()-((*j).cantidad));
                           }
             
                else {
                  (*i).setDinero((*i).getDinero()-(*j).cantidad);
                          setBanca(getBanca()+((*j).cantidad));   
                   }
                }

             else{
              if((*j).valor=="rojo") { (*i).setDinero((*i).getDinero()+(*j).cantidad);
                        setBanca(getBanca()-((*j).cantidad));
                           }
             
                else {
                  (*i).setDinero((*i).getDinero()-(*j).cantidad);
                          setBanca(getBanca()+((*j).cantidad));   
                   }
                 }
              }
           }
     

     else if((*j).tipo==3){
          if(getBola()==0){
              (*i).setDinero((*i).getDinero()-(*j).cantidad);
                  setBanca(getBanca()+((*j).cantidad));
               }        
           else{
               if(getBola()%2==0){
                   if((*j).valor=="par")  {
                     (*i).setDinero((*i).getDinero()+(*j).cantidad);
                        setBanca(getBanca()-((*j).cantidad));
                           }
             
                else {
                  (*i).setDinero((*i).getDinero()-(*j).cantidad);
                          setBanca(getBanca()+((*j).cantidad));   
                   }
                }  
              else{
                 if((*j).valor=="impar")  {
                 (*i).setDinero((*i).getDinero()+(*j).cantidad);
                        setBanca(getBanca()-((*j).cantidad));
                           }
             
                else {
                  (*i).setDinero((*i).getDinero()-(*j).cantidad);
                          setBanca(getBanca()+((*j).cantidad));   
                   }
                }

             }
       }

   else if((*j).tipo==4){
          if(getBola()==0){
              (*i).setDinero((*i).getDinero()-(*j).cantidad);
                  setBanca(getBanca()+((*j).cantidad));
               }        
           else{
               if(getBola()<=18){
                   if((*j).valor=="bajo")  {
                     (*i).setDinero((*i).getDinero()+(*j).cantidad);
                        setBanca(getBanca()-((*j).cantidad));
                           }
             
                else {
                  (*i).setDinero((*i).getDinero()-(*j).cantidad);
                          setBanca(getBanca()+((*j).cantidad));   
                   }
                }  
              else{
                 if((*j).valor=="alto")  {
                 (*i).setDinero((*i).getDinero()+(*j).cantidad);
                        setBanca(getBanca()-((*j).cantidad));
                           }
             
                else {
                  (*i).setDinero((*i).getDinero()-(*j).cantidad);
                          setBanca(getBanca()+((*j).cantidad));   
                   }
                }

             }
}
		}
	}

}