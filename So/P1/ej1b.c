#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void) 
{
    pid_t pid;
    int status, childpid, n;
    printf("Introduzca el numero de hijos a crear\n");
    scanf("%i",&n);
    for (int i = 0; i < n; ++i){//este for es el secreto del ejercicio

   	 pid = fork(); 

   	 switch(pid)
   	 {
    	    case -1:
    	        {
   				perror("fork error");
     	    	printf("errno value= %d\n", errno); 
    	        exit(EXIT_FAILURE); 
            //return (-1);
            }
        	case 0: /* proceso hijo */
        	    {
        	    printf("Proceso hijo %d; padre = %d\n", getpid(), getppid()); 
            	break;
            	}
       		 default:
            	{
            	    while (pid!=wait(&status));
            	    exit(EXIT_SUCCESS);
            	}
    }
}
}