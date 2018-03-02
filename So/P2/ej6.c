#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>

int count=0;

void *counter(){
	for (int i = 0; i < 100; ++i) count++;
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]){
	if (argc==1){
		printf("~ERROR~ Introduce el numero de hilos ~ERROR~\n");
		exit(0);
	}

	int nhilos=atoi(argv[1]);
	int error,suma=0;
	pthread_t hilos[nhilos];

	for (int i = 0; i < nhilos; ++i){
		pthread_create(&hilos[i],NULL,(void*)counter,NULL);
		error=pthread_join(hilos[i],NULL);
	}

	printf("\nLa varible counter es %d\n",count);

	return 0;
}