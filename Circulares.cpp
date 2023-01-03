#include<stdlib.h>
#include<stdio.h>

struct circular{
	int valor;
	circular *siguiente;
};

circular *crear(int x){
	circular *t = new circular;
	t->valor = x; 
	return t;} 

	

void insertarPorInicioListaCircular(struct circular **p,int x){
	circular *t = crear(x);
	if (*p){	
		circular *aux = *p;
		for( ; aux->siguiente != *p; aux = aux->siguiente);
			circular *aux2 = t;
			aux2->siguiente = *p;
			aux->siguiente = aux2;
			*p = aux;
	}else{
		*p = t;
		(*p)->siguiente = *p;}
}



void insertarPorFondoListaCircular(struct circular **p, int x)
{
	if (*p)
	{
		struct circular* pUltimo = *p;
		for (; pUltimo->siguiente != *p; pUltimo = pUltimo->siguiente);
		pUltimo->siguiente = crear(x);
		pUltimo->siguiente->siguiente = *p;
	}
	else
	{
		insertarPorInicioListaCircular(p,x);
	}
}






void mostrar(circular *p, char c){
	circular *t = new circular;
	 t = p;
	printf("\n\n\t\tMostrar lista\n\n\t\t%c",c);
	if ((p))
	do{
		printf("->[%i]",t->valor); t=t->siguiente;
	}while(t != p);
	printf("-> P\n\n");} 




int main (){
	int op = -1, x;
	circular *p = NULL;
		while(op){
			system("cls");
			printf("\n\n\t\tMENU BASE DE LISTAS\n");
			printf("\n\n\t\t1.Insertar");
			printf("\n\n\t\t2.Mostrar");
			printf("\n\n\t\t3.Buscar");
			printf("\n\n\t\t4.Eliminar");
			printf("\n\n\t\tSu opcion => "); scanf("%i",&op);
			switch(op){
				case 1: printf("\n\n\t\tValor a insertar "); scanf("%i",&x);
						insertarPorFondoListaCircular(&p,x); 
					   break;
				case 2:mostrar(p,'P');  
				       break;
				case 3: printf("\n\n\t\tValor a buscar "); scanf("%i",&x);
						//buscar(p,x);
					    break;
				case 4: printf("\n\n\tIndique el valor a eliminar "); scanf("%i",&x);
						//eliminar(&p,x); 
						break;	  	  
			}
		printf("\n\n");	system("pause");
		}
	return 0;
}

