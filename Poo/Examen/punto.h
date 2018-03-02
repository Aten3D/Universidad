#ifndef punto_h
#define punto_h

class punto{

	private:
		int x_;
		int y_;
	public:	
		punto(
			int x,
			int y
			);
		inline int getx(){return x_;};
		inline int gety(){return y_;};
		inline Punto operator=(const Punto &punto);
		inline friend Punto operator+(const Punto &punto1,const Punto &punto2);
		inline friend Punto operator+(const Punto &punto, int valor);
		inline friend Punto operator+(int valor, const Punto &punto);
		inline Punto operator++(void);
		inline Punto operator++(int);
};

#endif