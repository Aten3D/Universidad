#include <stdio.h>
#include <stdlib.h>

int main(){
	int **M, nFil, nCol;
	printf("Introduce el numero de filas\n");
	scanf("%i", &nFil);
	printf("Introduce el numero de columnas\n");
	scanf("%i", &nCol);
	reserva (**M, nFil, nCol) ;
	rellena (**M, nFil, nCol) ;
	ordena  (**M, nFil, nCol) ;
	libera  (**M, nFil, nCol) ;
}