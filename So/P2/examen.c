#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NELEM 10
#define NTH 5

typedef struct
{
	int *vec;
	int *vec1;
	int n;
}param;

void* sumar(param* arg){
	int *suma = (int*)malloc(sizeof(int));
	*suma = 0;
	for (int i = 0; i < arg->n; ++i)
	{
		*suma += arg->vec[i] * arg->vec1[i];
	}
	pthread_exit(suma);
}

int main(int argc, char const *argv[])
{
	int v[NELEM],v1[NELEM];
	int sumv = 0;
	int result = 0;
	srand(time(NULL));
	printf("VECTOR:");
	for (int i = 0; i < NELEM; ++i)
	{
		v[i] = rand()%10;
		printf(" %d,", v[i]);
	}
	printf("\n");

	printf("VECTOR1:");
	for (int i = 0; i < NELEM; ++i)
	{
		v1[i] = rand()%10;
		printf(" %d,", v1[i]);
	}
	printf("\n");


	param subarray[NTH];
	for (int i = 0; i < (NTH-1); ++i)
	{
		subarray[i].vec = &v[sumv];
		subarray[i].vec1 = &v1[sumv];
		subarray[i].n = NELEM/NTH;
		sumv += NELEM/NTH;
	}
	subarray[NTH-1].vec = &v[sumv]; 
	subarray[NTH-1].vec1 = &v1[sumv];
	subarray[NTH-1].n = NELEM/NTH + NELEM%NTH;

	pthread_t thr[NTH];
	for (int i = 0; i < NTH; ++i)
	{
		pthread_create(&thr[i], NULL, (void*)sumar, &subarray[i]);
		usleep(10000);
	}
	int *aux;
	for (int i = 0; i < NTH; ++i)
	{
		pthread_join(thr[i], (void**)&aux);
		result += *aux;
		printf("Suma parcial %d: %d\n", i, *aux);
	}

	printf("SUMA TOTAL: %d\n", result);


	return 0;
}