#include <sys/types.h> //Para estructura pid_t 
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>

void esperar(int seg, char *nombre){
	
	int suma,childpid,status;
	
	sleep(seg);
	
	suma=getpid()%10;
	
	while((childpid=wait(&status))>0){
		if(WIFEXITED(status)>0) 
			suma += WEXITSTATUS(status);
	}
	
	printf("Soy %s , mi pid es %d, y mi suma es %d\n",nombre,getpid(),suma);
	
	exit(suma);
}

int main(){
	pid_t pid;
	int status,chilpid,n;
	printf("Introduzca el numero de hijos a crear\n");
	scanf("%i",&n);
	for (int i = 0; i < n; ++i){
		pid=fork();
		if (pid==0){
			esperar(0,"hijo");
		}
	}
	esperar(2,"Padre");
	}