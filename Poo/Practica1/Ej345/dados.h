#ifndef dado_h
#define dado_h
class Dados{
private: 
	int d1_;
	int d2_;
	int l1_;
	int l2_;
	int t1_;
	int t2_;
	int ultimosd1_[5];
	int ultimosd2_[5];

public:
	Dados();
	int getDado1();
	int getDado2();
	bool setDado1(int x);
	bool setDado2(int y);
	int getSuma();
	void lanzamiento();
	int getDiferencia();
	float getmedia1();
	float getmedia2();
	int getLanzamientos1();
	int getLanzamientos2();
	void getUltimos1(int* ultimosd1);
	void getUltimos2(int* ultimosd2);
};

#endif