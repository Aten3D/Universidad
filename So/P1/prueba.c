#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <time.h>


struct params{
	int in;
	int *v;
	int *v1;
	int num;
};

void *pEscalar(struct params *p){
	int i;
	int *multiplicar;
	multiplicar=(int*)malloc(sizeof(int));
	*multiplicar=0;
	 for(i=0;i< p->num;*multiplicar){
	 (*multiplicar)+=p->v[i]*p->v1[i];
	 }
	 printf("Soy el hilo %d y mi producto escalar es %d\n",p->num,*multiplicar);
	 pthread_exit(multiplicar);
}

int main(int argc, char *argv[]){

	srand(time(NULL));

	int nH=5;
	int nele=10/nH;
	int res=10%nH;

	pthread_t hilos[nH];
	struct params p[nH];

	int v[10], v1[10], suma=0;
	void *r;
	int error=0;

	for (int i = 0; i < 10; ++i) v[i]=rand()%9;
	for (int i = 0; i < 10; ++i) v1[i]=rand()%9;

	for(int i=0;i<nH;i++){
		p[i].in=i;
		p[i].v=&v[i*nele];
		p[i].v1=&v1[i*nele];
		p[i].num=nele;

		if (i==nele-1) p[i].num+=res;

		pthread_create(&hilos[i],NULL,(void*)pEscalar,&p[i]);
		error=pthread_join(hilos[i],&r);

		if(error!=0) printf("Error en pthread_join\n");

		suma+=*(int*)r;
	}

	printf("Suma=%d\n",suma);
	return 0;
}