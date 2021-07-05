#include<stdlib.h>
#include<stdio.h>

struct lista{
	int valor;
	lista *prox;
};

void insertar(lista **ini,int x){
	lista *t = new lista;
	t->valor = x;
	t->prox = *ini;
	*ini = t;
}
void mostrar(lista *ini){
	lista *t = ini;
	while(t){
		printf("[%i]->",t->valor);
		t=t->prox;
	}
	printf("NULL");
}
void mostrarl(lista *p,char c){
	printf("\n\nLista %c ->",c);
	mostrar(p);
}
void swap(int *x,int *y){
	int c = *x;
	*x = *y;
	*y = c; 
}
void eliminar(lista **k,int x){
	lista *t=*k;
	if(t)
		if(t->valor==x){
			*k=(*k)->prox;
			delete(t);
			return;
		} else {
			while((t->prox)&&(t->prox->valor != x)) t=t->prox;
			 if(t->prox){
			 	lista *aux = t->prox;
			 	t->prox = t->prox->prox;
			 	delete(aux);
			 	return;
			 }
		}
}
int buscar(lista *p,int x){
	lista *t=p;
	 while((t)&&(t->valor!=x))
	  t=t->prox;
	  return(t!=NULL);
}
int comunes(lista *A,lista *B){
	lista *a=A,*b;
	int cont = 0;
	while(a){
		b=B;
		while(b){
			if(a->valor == b->valor) {
				cont++; break;
			}
			b=b->prox;
		}
	 	a=a->prox;
	} 
	return cont;
}
void eliminarcomunes(lista **A,lista **B){
	lista *a=*A,*b;
	int num = 0;
		while(a){
			b=*B;
			 while(b)
			  if (a->valor == b->valor){
			  		num = b->valor;
			  		while (buscar(*A,num))eliminar(A,num);
			  		while (buscar(*B,num))eliminar(B,num);
			  		a=*A; break;//se inicializan de nuevo porque no se sabe donde queda el apuntador
			  }			  
			  else {
			    b = b->prox;}
		a = a->prox;	    
		}	
}
void mezclar(lista **A,lista **B){ //Intercala numeros y eso
	lista *a = *A,*b = *B,*t = *A;
	if(!(a))	return; //si A esta vacio no hay nada que hacer
	if(!(b)){
		/*B esta vacio pero A no lo esta: Muevo B a A y dejo A en nulo*/
		*B = *A;
		*A = NULL;
		return;
	}
	while((a)&&(b)){
		*A=(*A)->prox;
		a->prox = b->prox;
		b->prox = a;
		a = *A;
		if(b->prox->prox)
	   	b = b->prox->prox;
	   else	{
	   b = b->prox; break;} //se acaba B pero no A   
	} 
	if(a){
		while((b)&&(b->prox)) b=b->prox;
		b->prox = a;
		*A=NULL;
	}//si se acaba A pero no B no pasa nada 
}

void separar(lista **a,lista **b, int paridad){
	lista *ca=*a, *cb=*b, *t;
	int x;
	while(ca){
		if(ca->valor%2==paridad){
			x=ca->valor;
			eliminar(a,x);
			insertar(a,x);	
		}else 
			ca = ca->prox;	
	}
}
void parimpar(lista **a, lista **b){
	separar(a,b,0);
	separar(b,a,1);
}

void ordenar(lista *a){
	/*Por metodo Burbuja*/
	lista *p=a, *ult=NULL;
	int cont=1;
	while((p)&&(cont)){
		p=a; cont=0;
		 while((p)&&(p->prox!=ult)){
		 	if((p->valor)>(p->prox->valor)){
		 		swap(&p->valor,&p->prox->valor);
		 		cont++;
			 }
			p=p->prox; 
		 }
		ult=p; 
	}
}
int comunes(lista *a,lista*b){
	lista *A=a, *B=b, *Aux;
	lista *Auxa=NULL, *Auxb=NULL;
	int cont=0,n=0;
	while (A){
		insertar(&Auxa,A->valor);
		eliminarepetidos(Auxa);
		A=A->prox;
    }
    while (B){
    	insertar(&Auxb,B->valor);
    	eliminarepetidos(Auxb);
    	B=B->prox;
	}
    imprimir(&Auxa);
    imprimir(&Auxb);
	while (Auxa){
		Aux=Auxb;	
		while (Aux){
			if (Auxa->valor==Aux->valor){
				cont++;
			}
		Aux=Aux->prox;
		}
		Auxa=Auxa->prox;
	};	
	return cont;
}
int main(){
	int op=-1,x=0,n;
	lista *A=NULL,*B=NULL;
	while(op){
		system("cls");
		printf("\n\n\t\tMANEJO DE DOS LISTAS\n\n");
		printf("\t1.insertar en A\n");
		printf("\t2.insertar en B\n");
		printf("\t3.mostrar listas\n");
		printf("\t4.contar elementos comunes\n");
		printf("\t5.eliminar elementos comunes\n");
		printf("\t6.mezclar 2 listas\n");
		printf("\t7.pares en A, impares en B\n");
		printf("\t8.ordenar listas\n");
		printf("\t0.salir\n\n");
		printf("\tOPCION -> ");
		scanf("%i",&op);
		switch(op){
			case 1: printf("\n\nIndique dato a insertar en A: ");
						scanf("%i",&x);
		    			insertar(&A,x); 
		    			break;
			case 2: printf("\n\nIndique dato a insertar en B: ");
						scanf("%i",&x);			
						insertar(&B,x); 
						break;
			case 3: mostrarl(A,'A');			
					  mostrarl(B,'B'); 
					  break;
			case 4: printf("A y B tienen en comun %i  elementos",comunes(A,B));
					  break;	
			case 5: printf("Eliminando elementos comunes ");
					  eliminarcomunes(&A,&B);
					  break;
			case 6: mezclar(&A,&B);
					  break;
			case 7: parimpar(&A,&B);
					  break;		  		  		  	 
			case 8: ordenar(A);ordenar(B);
					  break;
			case 9: comunes(A,B);
		}
	printf("\n\n");
	system("pause");	
	}
	return 0;
}

