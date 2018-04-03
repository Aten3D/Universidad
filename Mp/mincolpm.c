/**
@mainpage owo
owo
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
@file mincolpm.c
@brief Funcion principal mincol
@author doragonsitoretrasado
@date hoy
@version 69
Este fichero contiene el codigo de las siguientes funciones:
@li Reservar Matriz
@li Rellenar Matriz
@li Imprime  Matriz
@li Liberar  Matriz
@li Minimo columna
*/

int **reservarMemoria(int nFil, int nCol);
void rellenaMatriz(int **matriz, int nFil, int nCol);
void imprimeMatriz(int **matriz, int nFil, int nCol);
int *minCol(int **matriz, int nFil, int nCol);
void liberarMemoria(int ***matriz, int **minColArray, int nFil);

int main(){
	int **matrix, *minColArray, nFil, nCol;
	srand(time(NULL));

	printf("POR FAVOR, INTRODUZCA EL NÚMERO DE FILAS DE LA MATRIZ: ");
	scanf("%d", &nFil);
	printf("A CONTINUACIÓN, EL NÚMERO DE COLUMNAS DE DICHA MATRIZ: ");
	scanf("%d", &nCol);

	matrix = reservarMemoria(nFil, nCol);

	rellenaMatriz(matrix, nFil, nCol);

	imprimeMatriz(matrix, nFil, nCol);

	minColArray = minCol(matrix, nFil, nCol);

	printf("LOS VALORES MÁS PEQUEÑOS DE CADA COLUMNA SON: ");

	for (int i = 0; i < nCol; i++){
		printf("%d", *(minColArray + i));
		if(i < nCol - 1) printf(", ");
	}
	printf(".\n");

	liberarMemoria(&matrix, &minColArray, nFil);

	return 0;
}

/**
@fn reservarMemoria
@brief prueba
hase cosas nasis
@param nFil numero de filas
@return matriz auxiliar
*/
int **reservarMemoria(int nFil, int nCol){
	int **auxMatrix = (int**) malloc(nFil * sizeof(int*));

	for (int i = 0; i < nFil; i++)
		*(auxMatrix + i) = (int*) malloc(nCol * sizeof(int));

	return auxMatrix;
}

void rellenaMatriz(int **matriz, int nFil, int nCol){
	printf("ASIGNAMOS UN VALOR ENTRE 1 Y 20 A CADA POSICION DE LA MATRIZ:\n");
	for(int i = 0; i < nFil; i++)
		for (int j = 0; j < nCol; j++)

¿ +3		*(*(matriz+i)+j) = rand()%20 + 1;
}

void imprimeMatriz(int **matriz, int nFil, int nCol){
	printf("LA MATRIZ (%dx%d) HA QUEDADO:\n", nFil, nCol);
	for(int i = 0; i < nFil; i++){
		for (int j = 0; j < nCol; j++)
			printf("M[%d][%d]: %d 	", i, j, *(*(matriz+i)+j));
		printf("\n");
	}
}

int *minCol(int **matriz, int nFil, int nCol){
	int *auxMinCol = (int*) malloc(nCol * sizeof(int));

	for(int i = 0; i < nCol; i++){
		*(auxMinCol + i) = *(*(matriz)+i);
		for (int j = 0; j < nFil; j++)
			if(*(*(matriz+j)+i) < *(auxMinCol + i)) *(auxMinCol + i) = *(*(matriz+j)+i);
	}
	return auxMinCol;
}

void liberarMemoria(int ***matriz, int **minColArray, int nFil){
	for(int i = 0; i < nFil; i++)
		free((*matriz)[i]);
	free(*matriz);
	(*matriz) = NULL;

	free(*minColArray);
	(*minColArray) = NULL;
}
