#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int array[5];
pthread_mutex_t lock;
//esta variable almacena entre semaforos, si esta o no, vacio alguno de los huecos del buffer
sem_t hueco;

void lectura(){
	int i;
	printf("\tVector = {%d, %d, %d, %d, %d}\n", array[0], array[1], array[2], array[3], array[4]);
}

void *incrementarValor(){
	pthread_mutex_lock(&lock);

	int i, pos, aux = 0;

	//Buscamos un hueco de forma aleatoria
	do{
		pos = rand()%5;
		if(array[pos] == 0)
			aux++;
	}while(aux == 0);


	array[pos]++;

	printf("Incluimos +1 al hueco %d\n", pos);
	lectura();

	//Tras sumar un valor, metemos en la var de semaforos "hueco" un +1 indicando que hay hueco
	sem_post(&hueco);
	pthread_mutex_unlock(&lock);
}

void *decrementarValor(){
	//Comenzamos quitando un valor de la var de semaforos "hueco", indicando que ya no queda mas sitio
	sem_wait(&hueco);
	pthread_mutex_lock(&lock);

	int i, pos, aux = 0,maxitem=20;
	//Buscamos un hueco de forma aleatoria
	do{
		pos = rand()%5;
		if(array[pos] != 0)
			aux++;
	}while(aux == 0);

	if(array[pos]!=0)
	array[pos]--;

	printf("Borramos 1 al hueco %d\n", pos);
	lectura();

	pthread_mutex_unlock(&lock);
	
}

int main(int argc, char const *argv[]){
	int i, n;
	srand(time(NULL));

	printf("Cuantas veces se van a realizar intercambios de valor?\n");
	scanf("%d", &n);

	pthread_t tid_Mas[n];
	pthread_t tid_Menos[n];

	for (i = 0; i < n; ++i){
		pthread_create(&tid_Mas[n], NULL, (void*) incrementarValor, NULL);
		pthread_create(&tid_Menos[n], NULL, (void*) decrementarValor, NULL);
		pthread_join(tid_Mas[n], NULL);
		pthread_join(tid_Menos[n], NULL);	
	}

	pthread_mutex_destroy(&lock);
	sem_destroy(&hueco);
	
	return 0;
}