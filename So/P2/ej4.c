#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>


void * cuenta(char*f0){
	FILE *f;

	char c;
	int*nlineas=malloc(sizeof(int));
	*nlineas=1;
	f=fopen(f0,"r");
	while((c=fgetc(f))!=EOF) if(c=='\n') (*nlineas)++;

	printf("El numero de lineas es %d\n",*nlineas);

	fclose(f);
	pthread_exit(nlineas);
}

int main(int argc, char *argv[]){
	if(argc==1){
		printf("ERROR DE SINTAXIS\n");
		exit(0);
	}
	int nficheros=argc-1;
	int suma=0,error=0;
	void *r;
	pthread_t hilos[nficheros];

	for(int i=0;i<nficheros;i++){
		pthread_create(&hilos[i],NULL,(void*)cuenta,argv[i+1]);
		error=pthread_join(hilos[i],&r);
		if (error!=0)printf("Error en pthread_join\n");
		suma+=*(int*)r;
	}
	printf("\nEl numero de lineas de todos los ficheros es %d\n",suma);
	return 0;
}
