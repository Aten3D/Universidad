#ifndef persiana_h
#define persiana_h
#include <string>

class persona{

	private:
		string _nombre;
		string _apellidos;
		int _edad;

	public:
		Persona(
		string nombre="",
		string apellidos="",
		int edad=0,
		);

		Persona(const Persona &p);

		string getNombre();
		string getApellidos();
		int getEdad();
		void setNombre();
		void setApellidos();
		void setEdad();
		void leerPersona();
		void escribirPersona();
};

#endif