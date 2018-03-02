#include <sys/types.h> //Para estructura pid_t 
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Para fork()
#include <errno.h>

int main(void) 
{
    pid_t pid;
    int status, childpid;
	int a= 5;
	int *p;
    p=&a;
for (int i = 0; i < 10; ++i){

    pid = fork(); 

    switch(pid)
    {
        case -1:
            perror("fork error");
            printf("errno value= %d\n", errno); exit(EXIT_FAILURE); 
            //return (-1);
            
        case 0: /* proceso hijo */
			a=10;
            printf("Proceso hijo %d; padre = %d, p=%p, a=%d \n", getpid(), getppid(),&a, *p); 
            exit(i);
    }
}
            sleep(0.1);
            printf("Proceso %d; padre = %d, p=%p , a=%d\n", getpid(), getppid(),&a, *p);

exit(EXIT_SUCCESS); //return 0;
}
