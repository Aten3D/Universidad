#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <time.h>

void * suma(int *id){
	int *v=(int*)malloc(sizeof(int)*2);
	v[0]=rand()%9;
	v[1]=rand()%9;
	printf("Los valores del hilo %d son %d y %d\n",*id,v[0],v[1]);
	pthread_exit(v);
}

int main(int argc,char** argv){
	if(argc==1){
		printf("ERROR DE SINTAXIS\n");
		exit(0);
	}

	srand(time(NULL));
	int n=atoi(argv[1]);
	int i,error=0,id,sum=0;
	pthread_t hilos[n];
	int *r;

	for (int i = 0; i < n; ++i){
		id=i;
		pthread_create(&hilos[i],NULL,(void*)suma,&id);
		pthread_join(hilos[i],(void**)&r);
		sum+= r[0]+r[1];
	}
	printf("El valor final es %d\n",sum);
	return 0;

}