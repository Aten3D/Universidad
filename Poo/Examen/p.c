#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){
	pid_t pid;
	int n,status;
	int variable=0;
	printf("Introduce el numero de his que crear:\n");						
	scanf("%i",&n);
	printf("Proceso %i\n",getpid());
	for (int i = 0; i < n; ++i){
		pid=fork();
		switch(pid){
			case -1:
			{
				printf("Error\n");
				exit(EXIT_FAILURE);
			}
			case 0:
			{
				printf("Hijo %i: %i ; Padre=%i\n",i+1,getpid(),getppid());
				variable=variable+1;
				exit(EXIT_SUCCESS);
			}
			default:
			{
				while(pid!=wait(&status));
				printf("El valor de la variable es igual a %i\n",variable);
			}
		}
	}
	return (EXIT_SUCCESS);
}