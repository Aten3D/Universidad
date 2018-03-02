#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){

	key_t clave;				//Varibles
	pid_t pid;
	int status, childpid, n;
	int ID;
	int *contador=NULL;

	clave=ftok("/bin/ls",3);	//declaracion de llave

	printf("Introduce el numero de procesos que quieres: ");
	scanf("%d",&n);

	ID =shmget(clave,sizeof(int)*1,0777| IPC_CREAT);		//identificador de memoria
	if(ID==-1){
		printf("ID no disponible\n");
		exit(0);
	}

	contador=(int*)shmat(ID,(char*)0, 0);
	if(contador==NULL){
		printf("Memoria no disponible\n");
		exit(0);
	}

	for (int i=0; i<n; i++)
	{
		pid = fork();
		switch(pid)
		{
			case -1:
			{
				printf("\nError\n");
				exit(EXIT_FAILURE);
			}
			case 0:
			{
				printf("Hijo %i = %i; padre = %i.\n", i+1, getpid(), getppid());
				
				for(int j=0; j<100;j++){
					contador[0]++;}

				exit(EXIT_SUCCESS);
			}
			default:
			{
				while (pid!=wait(&status));//con esto espero a que acabe de contar y se imprima el valor
			}
		}
	}
		printf("El valor de la variable es igual a %i.\n", contador[0]);
		shmdt((char*)contador);
		shmctl(ID,IPC_RMID,(struct shmid_ds*)NULL);
		return (EXIT_SUCCESS);
}
