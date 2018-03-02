#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
int camiseta[5] = {5, 15, 25, 20, 10};

void *comprar(){
	pthread_mutex_lock(&mymutex); 
	int modelo=rand()%5;
	int cantidad=rand()%(camiseta[modelo]);
	camiseta[modelo]-=cantidad;
	pthread_mutex_unlock(&mymutex);
	for (int i = 0; i < 5; ++i) printf("Compra %d\n", camiseta[i]);
	pthread_exit(NULL);
}

void *suministrar(){
	pthread_mutex_lock(&mymutex);
	int modelo=rand()%5;
	int cantidad=rand()%(camiseta[modelo]);
	camiseta[modelo]+=cantidad;
	pthread_mutex_unlock(&mymutex);
	for (int i = 0; i < 5; ++i) printf("Suministra %d\n", camiseta[i]);
	pthread_exit(NULL);
}

int main(){
	srand(time(NULL));
	pthread_t h1,h2;
	int n,m;

	printf("Introduce el numero de clientes: ");
	scanf("%i",&n);
	printf("\nIntroduce el numero de proveedores: ");
	scanf("%i",&m);

	for (int i = 0; i < 5; ++i) printf("Modelo %d, cantidad %d\n", i, camiseta[i]);

	for (int i = 0; i < n; ++i) pthread_create(&h1,NULL,(void*)comprar,NULL);

	for (int i = 0; i < m; ++i) pthread_create(&h2,NULL,(void*)suministrar,NULL);

	for (int i = 0; i < n; ++i) pthread_join(h1,NULL);

	for (int i = 0; i < m; ++i) pthread_join(h2,NULL);

	printf("\n");
	for (int i = 0; i < 5; ++i) printf("Modelo %d, cantidad %d\n", i, camiseta[i]);

return 0;

}