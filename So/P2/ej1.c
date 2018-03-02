#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *imp(void *c){
	char *aux=(char*)c;
	for (int i = 0; i < strlen(c); i++){
		printf("%c\n",aux[i]);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t h1,h2;
	char c1[]= "Hola", c2[]= "mundo";

	pthread_create(&h1,NULL,imp,(void*)&c1);
	pthread_create(&h2,NULL,imp,(void*)&c2);
	pthread_join(h1,NULL);
	pthread_join(h2,NULL);

	printf("\nFin del programa\n");
	exit(0);
}