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
	int status;
	
	for(int i=0; i<2; i++)
	{
		pid = fork();
		switch (pid)
		{
			case -1:
			{
				perror("fork error");
				printf("errno value = %i.\n", errno);
				exit(EXIT_FAILURE);
			}
			case 0:
			{
				if(i==0)
				{
					if (openGnomeCalculator(argv[1]) == EXIT_FAILURE)//se llama a la fucion que va a comprobar si se ha abierto la calculadora como se que queria
					{
						perror("exec <./Ejercicio6a> <gnome-calculator> <gedit> <file1> ... <fileN> error");
						printf("errno value = %i\n", errno);
						exit(EXIT_FAILURE);
					}
				}
				if(i==1)
				{
					if (openGedit(argv[2]) == EXIT_FAILURE)//se llama a la fucion que va a comprobar si se ha abierto gedit como se que queria
					{
						perror("exec <./Ejercicio6a> <gnome-calculator> <gedit> <file1> ... <fileN> error");
						printf("errno value = %i\n", errno);
						exit(EXIT_FAILURE);
					}
				}
				exit(EXIT_SUCCESS);
			}
		}
	}
	while(pid=wait(&status)!=-1);
	return(EXIT_SUCCESS);
}

int openGnomeCalculator(char *args)//la funcion abre la calculadora de gnome  y retorna si se ha podido o no abrir el programa
{
	if(execlp(args, args, NULL)==-1)
	{
		return(EXIT_FAILURE);
	}
	else
	{
		return(EXIT_SUCCESS);
	}
}

int openGedit(char **args)//la funcion abre el editor de textos gedit y retorna si se ha podido o no abrir el programa
{
	if (execvp(args[2], &args[2])==-1)
	{
		return(EXIT_FAILURE);
	}
	else
	{
		return(EXIT_SUCCESS);
	}
}