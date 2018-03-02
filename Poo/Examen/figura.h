#ifndef figura_h
#define figura_h
#include <string>
#include <list>
#include <fstream>
using namespace std;

struct posicion{
	int x;
	int y;
};

class figura{
	private:
		string nombre_;
		int aristas_;
		float area_;
		list<posicion> posicion_; 
	public:
		figura(
			string nombre="",
			int aristas=0,
			float area=0
			);

		string getnombre(){return nombre_;};
		void setnombre(string nombre){nombre_=nombre;};
		int getaristas(){return aristas_;};
		void setaristas(int aristas){aristas_=aristas;};
		int getarea(){return area_;};
		void setarea(int area){area_=area;};
		list<posicion> getposicion(){return posicion_;};
		bool setposicion();
		

};
#endif