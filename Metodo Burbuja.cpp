#include<stdlib.h> //Ordenamiento Burbuja
#include<iostream>

/*Vamos comparando elementos adyacentes y empujamos los valores mas livianos hacia 
arriba (quedando los mas pesados abajo)*/

#define N 6

void swap(int *f, int *g);

int main(){
	int i,j,v[N] = {3,4,5,2,6,8};
	
	for (i=N-1;i>0;i--)
	 		for (j=0;j<i;j++)
	 			if(v[j]>v[j+1])
	 				swap(&v[j],&v[j+1]);
	 				
	 for (i=0;i<N;i++)
	  printf("%d ",v[i]);		

	printf("\n\n");
	system("pause");
	return 0;
}

void swap (int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}



