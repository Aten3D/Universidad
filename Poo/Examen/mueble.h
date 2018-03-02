#ifndef mueble_h
#define mueble_h
#include <string>

using namespace std;

class Mueble{
	private:
		int id_;
		string nombre_;
		string modelo_;
		string fecha_;
		string color_;

	public:
		Mueble(
			int id,
			string nombre,
			string modelo,
			string fecha,
			string color
			);

		int getid(){return id_;};
		string getnombre(){return nombre_;};
		string getmodelo(){return modelo_;};
		string getfecha(){return fecha_;};
		string getcolor(){return color_;};
		int setid(int id);
		string setnombre(string nombre);
		string setmodelo(string modelo);
		string setfecha(string fecha);
		string setcolor(string color);

};

#endif