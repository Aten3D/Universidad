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
    
} params;

int main(){
	int aux=0,k=0,aux2=0,aux3=0;
	params p[nprocesos];

	for(int i=0; i < nprocesos; ++i) {
		p[i].t_com = -1;
   	 	p[i].t_fin = -1;
    	p[i].t_ret = -1;
    	p[i].t_esp = -1;
	}

    strcpy(p[0].nombre, "A");
    p[0].t_ejec = 8;
    p[0].t_lleg = 0;

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

    for(int i=0; i < nprocesos; ++i){
		aux2=aux;
		aux=0;

		for(int j=0; j < nprocesos; ++j) {
			if((p[j].t_esp==-1) && (p[aux2].t_fin >= p[j].t_lleg)) {
				aux3=j;
				if(p[j].t_ejec < p[aux].t_ejec)
					aux=j;
			}
		}
		
		if(p[aux].t_esp!=-1)
			aux=aux3;

        if(i==0) p[aux].t_com = 0;
        else p[aux].t_com = p[aux2].t_fin;
	
        p[aux].t_fin = p[aux].t_com + p[aux].t_ejec;
        p[aux].t_ret = p[aux].t_fin - p[aux].t_lleg;
        p[aux].t_esp = p[aux].t_ret - p[aux].t_ejec;
	
		printf("   %s \t    %d \t\t %d \t   %d \t      %d\n", p[aux].nombre,p[aux].t_com, p[aux].t_fin, p[aux].t_ret, p[aux].t_esp);	
    }
}