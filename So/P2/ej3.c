#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <time.h>


typedef struct{
	int in;
	int *v;
	int num;
} params;

void *sum(params *p){
	int i;
	int *suma=malloc(sizeof(int));
	*suma=0;

	for (int i = 0; i <(*p).num; ++i){
		*suma+=(*p).v[i];
	}

	printf("El hilo es %d y su suma %d\n",(*p).in,*suma);
	pthread_exit(suma);
}

int main(int argc, char *argv[]){
	if(argc==1){
	printf("ERROR DE SINTAXIS\n");
	exit(0);
	}

	srand(time(NULL));

	int nH=atoi(argv[1]);
	int nele=10/nH;
	int res=10%nH;

	pthread_t hilos[nH];
	params p[nH];

	int v[10], suma=0;
	void *r;
	int error=0;

	for (int i = 0; i < 10; ++i) v[i]=rand()%9;

	for(int i=0;i<nH;i++){
		p[i].in=i;
		p[i].v=&v[i*nele];
		p[i].num=nele;

		if (i==nele-1) p[i].num+=res;

		pthread_create(&hilos[i],NULL,(void*)sum,&p[i]);
		error=pthread_join(hilos[i],&r);

		if(error!=0) printf("Error en pthread_join\n");

		suma+=*(int*)r;
	}

	printf("Suma=%d\n",suma);
	return 0;
}