#ifndef counter_h
#define counter_h
#include <list>

using namespace std;

class Contador{
	
	private:
		int counter_,min_,max_;
		list <int> i_;
		void save(int i){i_.push_front(i);}
	
	public:
		Contador(int min=0,int max=1000,int counter=0);
		inline int get(){return counter_;};//usamos inline para acelerar el programa ya que se mantiene cargada esa funcion
		Contador operator=(const Contador &o);
		Contador operator=(const int &o);
		Contador operator++(void);
		Contador operator++(int);
		Contador operator--(void);
		Contador operator--(int);
		friend Contador operator+(const int &n, const Contador &o);//Friend nos permite acceder a los elementos de la clase contador sean o no publicos
		friend Contador operator+(const Contador &o,const int &n);
		friend Contador operator-(const int &n, const Contador &o);
		friend Contador operator-(const Contador &o,const int &n);
		bool undo(int e=1);


};

#endif