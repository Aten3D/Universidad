#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int es_sufijo(char *cadena,char *sufijo){
	int i,n,m;
	char *ptr;
	ptr=strstr(cadena,sufijo);
    i=strlen(ptr);
    n=strlen(cadena);
    m=strlen(sufijo);
    n=n-m;
    if (i==n) return 1;
    else return 0;
}

int main(){
    char cadena[100];
    char sufijo[50];
    printf("Introduce la palabra\n");
    scanf("%s",cadena);
    printf("Introduce el sufijo\n");
    scanf("%s",sufijo);
    if (es_sufijo(cadena,sufijo)==1){
    	printf("Es sufijo\n");
    }
    else printf("No es sufijo\n");
}