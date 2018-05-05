#include <stdio.h>

int div (int a, int b) {
if(b > a) {
return 0;
}
else {
return div(a-b, b) + 1;
}
}

int main(int argc, char const *argv[]){
	int a=4, b=2;
	printf("El resultado de la resta es: %i\n",div(a,b));
	return 0;
}