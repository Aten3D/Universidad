#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(){
	pid_t pid;
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
        	    printf("Proceso hijo %i; padre = %i.\n", getpid(), getppid()); 
            	exit(EXIT_SUCCESS);
            	}
       		 default:
            	{
            	    sleep(30);//esto pone a dormir al proceso y se vuelve zombie
					exit(EXIT_SUCCESS);
            	}
	}
	exit(EXIT_SUCCESS);
}

