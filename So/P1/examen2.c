#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define N 10

struct params{
	int *v1;
	int *v2;
	int ind;
	int n;
};

void *pEscalar(struct params *p){
	int i;
	int *multiplicar;
	multiplicar=(int*)malloc(sizeof(int));
	*multiplicar=0;
	 for(i=0;i< p->n;*multiplicar){
	 (*multiplicar)+=p->v1[i]*p->v2[i];
	 }
	 printf("Soy el hilo %d y miu producto escalar es %d\n",p->n,*multiplicar);
	 pthread_exit(multiplicar);
}

int main(){
	srand(time(NULL));
	int v1[N];
	int v2[N];
	int i, nth=3;
	pthread_t thrd[nth];
	struct params sbin[N];
	  printf("Elementos vector1\n");
  for(i=0;i<N;i++) {

    v1[i] = rand()%10;
    printf("V[%d]=%d\n",i,v1[i]);
  }

  printf("Elementos vector2\n");

  for(i=0;i<N;i++) {

    v2[i] = rand()%10;
    printf("V[%d]=%d\n",i,v2[i]);
  }
  	for (int i = 0; i < nth; ++i){
  		sbin[i].v1= &v1[i*N/nth];
  		sbin[i].v2=&v2[i*N/nth];
  		sbin[i].ind=N/nth;
  		sbin[i].n=i;
  		if(N%nth!=0){
  			sbin[nth-i].ind=sbin[i].ind+N%nth;
  		}
  	}

  	for (int i = 0; i < nth; ++i){
  		pthread_create(&thrd[i],NULL,(void*)pEscalar,&sbin[i]);
  		usleep(10000);
  	}

  	int suma_total=0;
  	int *valor_devuelto;

  	for (int i = 0; i < nth; ++i){
  		pthread_join(thrd[i],(void*)&valor_devuelto);
  		suma_total+=*valor_devuelto;
  		usleep(1000);
  	}
  	  printf("La suma total es %d\n",suma_total);
}