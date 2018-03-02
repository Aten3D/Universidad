#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){
	key_t clave;
	pid_t pid;
	int status, chilpid,n;
	int ID;
	int t=0,i=0;
	int *counter=NULL;

	clave=ftok("/bin/ls",24);

	printf("Introduce el numero de procesos que quieres\n");
	scanf("%i",&n);

	ID=shmget(clave,sizeof(int)*1,0777|IPC_CREAT);
printf("e\n");
	if(ID==-1){
		printf("Id no disponible\n");
		exit(0);
	}
	counter=(int*)shmat(ID,(char*)0,0);
printf("4\n");
	if(counter==NULL){
		printf("Memoria no disponible\n");
		exit(0);
	}
	for (int i = 0; i < n; ++i){
		pid=fork();
		switch(pid)
		{
			case -1:
			{
				printf("ERROR\n");
				exit(EXIT_FAILURE);
			}
			case 0:
			{printf("5\n");
				counter[i]=0;
				printf("3\n");
				printf("Hijo %i= %i; Padre: %i \n",i+1,getpid(),getppid());

				while(counter[i]!=getpid()){printf("7\n");
					counter[i]++;
					printf("3\n");
				}
				i++;
				exit(EXIT_SUCCESS);
			}
			default:
			{printf("34\n");
				while(pid!=wait(&status));
				t=t+counter[i];
				printf("Se incrementa el counter en %i quedandose %i\n",counter[i],t);
			}

		}
	}
	printf("3\n");
	shmdt((char*)counter);
	shmctl(ID,IPC_RMID,(struct shmid_ds*)NULL);
	return(EXIT_SUCCESS);
}