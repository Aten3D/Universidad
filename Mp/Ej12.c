#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reserva(int *v,int tam){
	v=(int*)malloc(tam*sizeof(int));
}

void rellena(int *v,int tam){
	for (int i = 0; i < tam; ++i){
		v[i]=rand()%100+1;
	}
}

void impr(int *v,int tam){
	printf("El vector es V={");
	for (int i = 0; i < tam; ++i){
		printf("%i", v[i]);
		if (i!=tam-1){
			printf(",");
		}
	}
	printf("}\n");
}

void impares(){

}

void divisibles(){

}

int main(){
	srand(time(NULL));
	int *v;
	int tam;
	printf("Introduce le tanmaño del vector\n");
	scanf("%d",&tam);
	reserva(v,tam);
	rellena(v,tam);
	impr(v,tam);
	free(v);
}