
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int n, r; //n numero introducido por el usuario y r numero random que genera el programa
	
	srand(time(NULL));
	r = (rand() % 10)+1;
	cout << "Adivina el número\n";
	while ((n<1) || (n>10))//comprueba si el numero introducido esta entre 1 y 10
	{
		cout << "Introduzce un número del 1 al 10\n";
		cin >> n;
	}
	while (r!=n) //continua hasta que se encuentre el numero aleatorio
	{
		if (r>n)
		{
			cout << "Introduzce un número mayor: \n";
		}
		else
		{
			cout << "Introduzca un número menor: \n";
		}
		cin >> n;
	}

	cout << "Has acertado\n";
}