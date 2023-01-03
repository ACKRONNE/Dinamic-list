#include<stdlib.h>
#include<stdio.h>

struct pila{
	int valor;
	struct pila *prox;
};

int vacio(struct pila*p){
	return(p == NULL); 
}
int tope(struct pila *p){
	if (!(vacio(p))) /*devuelve el valor tope si la lista no esta vacia*/
	return (p->valor);
	return 0;
}
void apilar(struct pila **p,int x){
	struct pila*t = new struct pila;
	t->valor = x;
	t->prox = (*p);
	(*p) = t;
}
void desapilar(struct pila **p){
	struct pila *t = *p;
	*p=(*p)->prox;
	delete(t);
}
void imprimir(pila **p){
	/*imprime cada elemento de manera recursiva para luego rearmar la pila original*/
	int x;
		if (*p){
			x = tope(*p);
			desapilar(p);
			printf("%i|",x);
			imprimir(p);
			apilar(p,x);
		}
}
void mostrar(pila **p){
	printf("\n\n\tTope->|");
	imprimir(p);
	if (vacio(*p)) printf("NULL|");
	printf("<-Fondo \n\n");
}
int contar(struct pila **p){
	int x,total = 0;
	 if(!(vacio(*p))){
	 	x = tope(*p);
	 	desapilar(p);
	 	
	 	total = contar( p);
	 	
	 	apilar(p,x);
	 	return total +1;
	}
}
int buscar(pila **p,int n){
	int x,esta = 0;
	if(!(vacio(*p))){
		x = tope(*p);
		if(x==n) return 1;
		desapilar(p);
		
		esta = buscar(p,n);
		
		apilar(p,x);
		return esta;
	}
	return 0;
}
void eliminar(pila **p,int n){
	int x;
	if(!vacio(*p)){
		x=tope(*p);
		if(x==n){
			desapilar(p);
			printf("Numero [%i] eliminado",n);
		}
		else 
		  desapilar(p);
		  eliminar(p,n);
		  apilar(p,x);
	}
}

void alfinal(pila **z,int y){
	int k;
	if(!(vacio(*z))){
		k = tope(*z);
		desapilar(z);
		alfinal(z,y);
		apilar(z,k);
	}
	else apilar(z,y);
}

void voltear(pila **a){
	int k;
	if(!(vacio(*a))){
		k = tope(*a);
		desapilar(a);
		voltear(a);
		alfinal(a,k);
	}
}

void colocar(pila **d,int y){
	int k;
	 if(!(vacio(*d)))
	  if(tope(*d)>=y)
	  	apilar(d,y);
	  else {
	  	k= tope(*d);
		desapilar(d);
		colocar(d,y);
		apilar(d,k);  	
	  }
	else apilar(d,y);  
}
void ordenar(pila **q){
	int m;
	if (!(vacio(*q))){
		m = tope(*q);
		desapilar(q);
		ordenar(q);
		colocar(q,m);
	}
}

int main(){
	int  op = -1; int x= 0;
	struct pila *p = NULL;
	
	while (op){
		system("cls");
		printf("\tMENU DE PILAS\n");
		printf("\n\t1. Apilar un elemento");
		printf("\n\t2. Mostrar pila");
		printf("\n\t3. Desapilar");
		printf("\n\t4. Contar");
		printf("\n\t5. Buscar elemento");
		printf("\n\t6. Eliminar Elemento");
		printf("\n\t7. Voltear");
		printf("\n\t8. Ordenar");
		printf("\n");
		printf("\t0. Salir");
		printf("\n\n");
		printf("\t\t Indique opcion  ");
		scanf("%i",&op);
		switch(op){
			case 1: printf("\tElemento a apilar "); scanf("%i",&x);
				    apilar(&p,x);break;
			case 2: mostrar(&p); break;
			case 3: desapilar(&p);break;
			case 4: int z; z=contar(&p); printf("\tHay %i elementos",z); break;
			case 5: printf("\tNumero a buscar: "); scanf("%i",&x);
					printf("\tEl valor [%i] ",x);
					if (!buscar(&p,x)) printf(" NO ");
					printf(" esta en la pila");
					break;
			case 6: printf("\tNumero a eliminar: "); scanf("%i",&x);		
					eliminar(&p,x);
					break;
			case 7: voltear(&p); break;		
			case 8: ordenar(&p); break;	
		}
		system("pause");
	}
	system("pause");
	return 0;
}

