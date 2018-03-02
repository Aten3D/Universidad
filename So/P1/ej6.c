#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	pid_t pid;
	int n, status;
	int variable = 0;
	
	printf("\nIntroduce el numero de hijos que quieres crear: ");//Todos los procesos comparten en mismo padre y la variable variable no se modifica debido
	scanf("%i", &n);											 //a que no se comparte la memoria entre lo procesos
	printf("\nProceso %i.\n", getpid());
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
				variable = variable+1;
				exit(EXIT_SUCCESS);
			}
			default:
			{
				while (pid!=wait(&status));
				printf("El valor de la variable es igual a %i.\n", variable);
			}
		}
	}
		return (EXIT_SUCCESS);
}