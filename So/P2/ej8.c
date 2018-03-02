#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#define tam 5
#define maxitem 20

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int v[5]={0,0,0,0,0};
int count=0;

void* consumidor(){
	int pos=0,item=0;
	while(item<=maxitem){
		usleep(rand()%10000);
		pthread_mutex_lock(&mutex);
		if (count!=0){
			v[pos]=rand()%100;
			printf("Se consume %d en %d\n",v[pos],pos);
			pos=(pos+1)%tam;
			count--;
			item++;
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

void* productor(){
		int pos=0,item=0;
	while(item<=maxitem){
		usleep(rand()%10000);
		pthread_mutex_lock(&mutex);
		if (count!=0){
			v[pos]=rand()%100;
			printf("Se produce %d en %d\n",v[pos],pos);
			pos=(pos+1)%tam;
			count++;
			item++;
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}


int main() {
	srand(time(NULL));
	pthread_t t1,t2;



	for(int i=0;i<tam;i++) printf("v[%d]=%d\n",i,v[i]);
	
	pthread_create(&t1, NULL, (void *)productor, NULL);
	pthread_create(&t2, NULL, (void *)consumidor, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	for(int i=0;i<tam;i++) printf("v[%d]=%d\n",i,v[i]);

return 0;
}