#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int es_sufijo=0,i,n,m;
    char cadena[100];
    char sufijo[50];
    char *ptr;
    printf("Introduce la palabra\n");
    scanf("%s",cadena);
    printf("Introduce el sufijo\n");
    scanf("%s",sufijo);
    printf("%s, %s, %i\n",cadena, sufijo, es_sufijo);
    ptr=strstr(cadena,sufijo);
    i=strlen(ptr);
    n=strlen(cadena);
    m=strlen(sufijo);
    n=n-m;
    printf("%i %i %i\n",i,n,m);
    if (i==n){
    	printf("Es sufijo\n");
    }
} 