#include <sys/types.h> //Para estructura pid_t 
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>

int main(void) 
{
    pid_t pid;
    int status, childpid, n, a;
    printf("Introduzca el numero de hijos a crear\n");
    scanf("%i",&n);
	int *p;
    p=&a;
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
			a=10;
            printf("Proceso hijo %d; padre = %d, p=%p, a=%d \n", getpid(), getppid(),&a, *p); 
            exit(EXIT_SUCCESS);
            }
        default:
            {
                while (pid!=wait(&status));

            }
    }
}
printf("\n");    
exit(EXIT_SUCCESS); //return 0;
}
