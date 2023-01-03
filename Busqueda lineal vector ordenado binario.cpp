#include<stdlib.h> //SOLO SIRVE PARA VECTORES ORDENADOS
#include<iostream>

int main(){
	int v[5] = {3,14,17,50,90},numero,k;
	
	
	printf("Ingrese el numero a buscar: ");
	scanf("%i",&numero);
	
	int i=0;
	int j=5-1; //5 representa el tamño del vector
	
	do{
		   k = ((i+j)/2); //se suman las posiciones para hallar la mitad del vector
		 if(v[k]<=numero) //se compara, si la parte del vector es menor que el numero i aumenta
									 		i = k+1;                      //Van aumentando en conjunto, hasta que llegan al numero 
		 if(v[k]>=numero)
		   								j = k-1;	//se compara si el vector es mayor que el numero j disminuye 	
	}while(i<=j);
	
	printf("El elemento %d esta en la posicion %d\n",v[k],k+1);

	printf("\n\n");
	system("pause");
	return 0;
}

