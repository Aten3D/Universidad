#ifndef ruleta_h
#define ruleta_h
#include <list>
#include "crupier.h"
#include "jugador.h"
#include <string>
using namespace std;

class Ruleta{
	private:
		int banca_;
		int bola_;
		list<Jugador> jugadores_;
		Crupier crupier_;
	public:
		Ruleta(Crupier crupier);
		int getBanca(){return banca_;};
		bool setBanca(int banca);
		int getBola(){return bola_;};
		bool setBola(int bola);
		Crupier getCrupier(){return crupier_;};
		void setCrupier(Crupier crupier);
		list<Jugador> getJugadores(){return jugadores_;};
		void addJugador(Jugador jugador);
		int deleteJugador(Jugador jugador);
		int deleteJugador(string DNI);
		void escribeJugadores();
		void leeJugadores();
		void giraRuleta();
		void getPremios();
};
#endif