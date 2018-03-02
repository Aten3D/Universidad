#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <time.h>


#define TAM 10


struct params{
      int *v1;
      int *v2;
      int ind;
      int n;
};

void *pEscalar(struct params *p) {

  int i;
  int *multiplicar;

  multiplicar = (int*)malloc(sizeof(int));

  *multiplicar = 0;

      for(i=0;i<p->ind;i++) {

        (*multiplicar)+= p->v1[i]*p->v2[i];
      }

  printf("Soy el hilo %d y mi producto escalar es %d\n",p->n,*multiplicar);

  pthread_exit(multiplicar);
}

int main(int argc,char **argv) {

  srand(time(NULL));
  int v1[TAM];
  int v2[TAM];
  int N,i;

  N = atoi(argv[1]);

  pthread_t thrd[N];

  struct params sbin[N];
  printf("Elementos vector1\n");
  for(i=0;i<TAM;i++) {

    v1[i] = rand()%10;
    printf("V[%d]=%d\n",i,v1[i]);
  }

  printf("Elementos vector2\n");

  for(i=0;i<TAM;i++) {

    v2[i] = rand()%10;
    printf("V[%d]=%d\n",i,v2[i]);
  }

  for(i=0;i<N;i++) {

    sbin[i].v1 = &v1[i*TAM/N];
    sbin[i].v2 = &v2[i*TAM/N];
    sbin[i].ind = TAM/N;
    sbin[i].n = i;

    if(TAM%N!=0) {

        sbin[N-1].ind = sbin[i].ind+TAM%N;
     }
  }


  for(i=0;i<N;i++) {

    pthread_create(&thrd[i],NULL,(void*)pEscalar,&sbin[i]);
    usleep(1000);
  }

  int suma_total=0;
  int *valor_devuelto;

  for(i=0;i<N;i++) {

    pthread_join(thrd[i],(void*)&valor_devuelto);
    suma_total+=*valor_devuelto;
    usleep(1000);
  }
  
  printf("La suma total es %d\n",suma_total);
}
