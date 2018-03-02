#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int i, status;
	FILE *file;
	
	if(argc != 2)
	{
		printf("\nPor favor siga la siguiente estructura: ./Ejercicio7 <nombreFichero>\n\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(argv[1], "w");
		pid = fork();
		for(i=0; i<5; i++)
		{
			switch(pid)
			{
				case -1:
				{
					perror("ERROR\n");
					printf("Errno value = %i\n", errno);
					exit(EXIT_FAILURE);
				}
				case 0:
				{
					fputs("+++++\n", file);
					printf("Añadimos un padre\n");
					fflush(file);
					sleep(1);
					break;
				}
				default:
				{
					fputs("-----\n", file);
					printf("Añadimos un hijo\n");
					fflush(file);
					sleep(2);
				}
			}
		}
	}
			printf("Ejecutando...\n");
			exit(EXIT_SUCCESS);		
}