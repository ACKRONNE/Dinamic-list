#include<stdlib.h>
#include<iostream>

int buscador(int v[],int b);

int main(){
	int i,numero,v[5] = {2,1,4,5,3};
	
	printf("Introduzca el numero que desea encontrar: ");
	scanf("%i",&numero);
	
		i = buscador(v,numero);
		printf("\tresultado: %i",i+1);
		
	printf("\n\n");
	system("pause");
	return 0;
}

int buscador(int v[5],int numero){
	int k = 1,result = -2;
	do 
		if(v[k]==numero) result = k;
		else 
			k++;
	while((result==-2)&&(k<5));
	return result;
	}

