#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>


typedef struct{
	int n;
	int *fil;
	int *col;
}params;


void * mfila(params *p){
	int *v=malloc(sizeof(int));
	*v=0;
	for (int i = 0; i < 3; ++i){
		*v+=p->fil[i] * p->col[i];
	}
	pthread_exit(v);
}

int main(){ 
	int m[3][3]={{2,3,1},{6,4,3},{1,3,6}};
	int v[3]={8,2,3},sol[3];
	int nh=3,error=0;
	pthread_t hilos[nh];
	params p[nh];
	void*r;

	for (int i = 0; i < nh; ++i){	
	p[i].n=i;
	p[i].fil=&m[i][0];
	p[i].col=v;

	pthread_create(&hilos[i],NULL,(void*)mfila,&p[i]);
	error=pthread_join(hilos[i],&r);
	if(error!=0) printf("Error en pthread_join\n");
	sol[i]=*(int*)r;
	}

	for(int i = 0; i < nh; ++i) printf("Solucion[%d]=%d\n",i,sol[i]);
	return 0;
}