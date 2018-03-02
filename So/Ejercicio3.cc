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
	
	print("Soy %s , mi pid es %d, y mi suma es %d\n",nombre,getpid(),suma);
	
	exit(suma);
}

	int main(){
		
		pid=fork();
		
		if(pid==0){//HIJO1 (>òwó)> Andrés del futuro intenta entender esto <(òwó<)
				esperar(0,"HIJO1");
		}
		
		pid=fork();

		if(pid==0){//HIJO2
				pid=fork();
					esperar(0,"NIETO1");
				pid=fork();
					esperar(5,"HIJO2");
		}
		
		esperar(5,"PADRE");
	
	}