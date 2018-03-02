#include <stdio.h>
#include <string.h>
#define nprocesos 5

typedef struct parametros{
    char nombre[10];
    int t_ejec;
    int t_lleg;  
    int t_com;
    int t_fin;
    int t_ret;
    int t_esp;
	int t_ejecutado;
    
} params;

int main(){
    int aux=0,aux2=0;
    params p[nprocesos]; 
    for(int i=0; i<nprocesos; i++) {
		p[i].t_com = -1;
   	 	p[i].t_fin = -1;
    	p[i].t_ret = -1;
    	p[i].t_esp = -1;
		p[i].t_ejecutado = 0;
	}

    strcpy(p[0].nombre, "A");
    p[0].t_ejec = 8;
    p[0].t_lleg = 0;
    p[0].t_com = 0;
    p[0].t_fin = p[0].t_ejec;
    p[0].t_ret = p[0].t_fin;
    p[0].t_esp = 0;

    strcpy(p[1].nombre, "B");
    p[1].t_ejec = 4;
    p[1].t_lleg = 1;

    strcpy(p[2].nombre, "C");
    p[2].t_ejec = 9;
    p[2].t_lleg = 2;

    strcpy(p[3].nombre, "D");
    p[3].t_ejec = 5;
    p[3].t_lleg = 3;

    strcpy(p[4].nombre, "E");
    p[4].t_ejec = 2;
    p[4].t_lleg = 4;

    printf("\nProceso | t_comienzo | t_final | t_retorno | t_espera\n");
    printf("-------------------------------------------------------\n");
    for(int i=0; i< nprocesos; i++){
		for(int j=0; j< nprocesos; j++) {
			if( (p[j].t_lleg < p[aux].t_lleg) && (p[j].t_ejecutado != p[j].t_ejec) );
		}  
			if(i==0) p[i].t_com = 0;
       		else p[i].t_com = p[i-1].t_fin;
        	p[i].t_fin = p[i].t_com + p[i].t_ejec;
        	p[i].t_ret = p[i].t_fin - p[i].t_lleg;
        	p[i].t_esp = p[i].t_ret - p[i].t_ejec;
			printf("   %s \t    %d \t\t %d \t   %d \t      %d\n", p[i].nombre,p[i].t_com, p[i].t_fin, p[i].t_ret, p[i].t_esp);
    }
}