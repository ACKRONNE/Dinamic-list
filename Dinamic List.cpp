#include<stdlib.h> //Menu basico de manejo de listas
#include<stdio.h>

struct lista{
	int valor;
	lista *prox;
};

void insertar(lista **cab,int x){
	lista *t = new lista;
	t->valor = x;
	t->prox = *cab;
	*cab = t;
	printf("\n\n\t\tValor insertado por cabeza %i",x);
}
void mostrar(lista *z,char c){
	lista *t = z;
	printf("\n\n\t\tMostrar lista\n\n\t\t%c",c);
	while(t){
		printf("->[%i]",t->valor);
		t=t->prox;
	}
	printf("-> NULL\n\n");
}
void eliminar(lista **k,int x){ //elimina la primera vez
	lista *t = *k;
	if (t)
	 if(t->valor==x){
	 		*k=(*k)->prox;
	 		delete(t);
	 		printf("\n\n\t\tValor[%i]eliminado como cabeza ",x);
	 		return;
	 } else {
	 	while((t->prox)&&(t->prox->valor != x)) t=t->prox;
	 	if(t->prox){
	 			lista*aux=t->prox;
	 			t->prox = t->prox->prox;
	 			delete(aux);
	 			printf("\n\n\t\tValor [%i] eliminado en lista",x);
	 			return;
		 } }
	 printf("\n\n\t\tValor [%i] NO encontrado en lista",x);}
int buscar(lista *p,int x){ 
	lista *t=p; 				//devuelve 0 o 1 
	while((t)&&(t->valor!=x)) 
		t=t->prox;
	return(t!=NULL); }
	
int buscar2(lista *p,int x){ 
	lista *t=p; int contador = 0; //devuelve cuantas veces 
	while(t){
		if(t->valor==x) contador++;
		t=t->prox;}
	return(contador); }
	
void eliminarepetidos(lista *p){ //elimina la ultima vez
	int s;
	lista *t=p;
	while((t)&&(t->prox)){
		s=buscar(t->prox,t->valor);
		while(s){
			eliminar(&t->prox,t->valor); s--;}
		t=t->prox;}}
void eliminarepetidos2(lista *p){	// elimina todas las veces que lo encuentra
	lista *t=p, *aux,*temp;
	while((t)&&(t->prox)){
		aux=t;
		while(aux->prox){
			if(aux->prox->valor==t->valor){
				temp=aux->prox;
				aux->prox=aux->prox->prox; 
				delete temp;
			}
			else 
				aux=aux->prox;
		}
	 t=t->prox;	
	}
}
int primo(int x){
	int contador;
		for(int i = 1; i<=x;i++)
		  if((x%i) == 0) contador ++;
		  if ((contador > 2) || (x < 2)) return 0; else return 1;}
		  
void eliminarprimo(lista **p){
	lista *t = *p, *aux; 
	int s;
	while(t){
		 s = primo(t->valor);
		 printf(" ",s); //esta linea no sirve para nada, el programa me da error si no la pongo 
		 if(s == 1){
		 	eliminar(p,t->valor);
			 t=*p;}
		 else t=t->prox;
	}
}	   
void eliminarepetidos_2(lista *p){	
	int s; 
	lista *t=p, *aux,*temp;
	while((t)&&(t->prox)){
		aux=t;
		while(aux->prox){
			if(aux->prox->valor==t->valor){
				temp=aux->prox;
				aux->prox=aux->prox->prox; 
				delete temp;
			}
			else 
				aux=aux->prox;
		}
	 t=t->prox;	
	}
}
lista *crear(int x){
	lista *t = new lista;
	t->valor = x; /*crea una casilla la inicializa y devuelve el puntero*/
	t->prox = NULL;
	return t;
}
void insertarporf(lista **cab,int x){
	lista *p = *cab, *aux=p;
	if(!(p))
		*cab = crear(x);
	else{
	 	while((aux)&&(aux->prox)) aux = aux->prox; //ultima casilla
	 	 aux->prox=crear(x);
	 } 
	printf("\n\n\t\tValor insertado por cabeza %i",x);
	
}
void swap(int *x,int *y){
	int c = *x;
	*x = *y;
	*y = c; }

lista *invertir( lista **p){
	lista *inversa = NULL; int x;
	lista *tope = *p;
	x = tope->valor;
	while(tope != NULL){
		insertar(&inversa,tope->valor);
		tope = tope->prox;
	}
	return(inversa);
}
void ordenarintercambio(lista **p){
	lista *t = *p, *aux;
		while((t)&&(t->prox)){
			aux=t;
			  while(aux->prox){
			  	if(aux->prox->valor < t->valor){
			  		aux = aux->prox;
			  		swap(&aux->valor,&t->valor);}
			  	else aux = aux->prox;}
		t=t->prox;	
		}
}
void ordenarinserccion(lista **p){
   lista *t = *p;
   int cont = 1,cursor,aux,k;
   while(t){
      cursor = cont;       aux = t->valor;    k = cursor-1;       
      lista *prev = *p;
      for(int i=0;i<k-1;i++)prev=prev->prox;
      	while(k >= 0 && aux < prev->valor){
      		
         prev->prox->valor=prev->valor;
         
        	 lista *temp=*p;
      		     for(int j=0;j<k-2;j++) temp=temp->prox;            
        	 prev=temp;   ;   k--;}
         
      	 	lista *temp2 = *p;
      			 for(int h=0;h<k;h++)temp2=temp2->prox;
      	 	temp2->valor=aux;
			      	 	
      t=t->prox;
      cont++;   
   }
}
void ordenarburbuja(lista **p){
     lista *actual = *p,*siguiente;
     int t;
     while(actual->prox != NULL){
          siguiente = actual->prox;
          while(siguiente!=NULL){
               if(actual->valor > siguiente->valor){
                    t = siguiente->valor;
                    siguiente->valor = actual->valor;
                    actual->valor = t;}
               siguiente = siguiente->prox;}   
          actual = actual->prox;
          siguiente = actual->prox;
	}
}
int vaciar(lista **p){
	lista *aux = *p;
	(*p)= aux->prox;
	delete(aux);}

int main(){
	int op = -1, x = 0, contador = 0;
	lista *p=NULL;
	while(op){
		system("cls");
		printf("\n\n\t\tMENU BASE DE LISTAS\n");
		printf("\n\n\t\t1.Insertar");
		printf("\n\t\t2.Mostrar");
		printf("\n\t\t3.Eliminar");
		printf("\n\t\t4.Buscar dato ");
		printf("\n\t\t5.Buscar dato y indicar cuantas veces esta");
		printf("\n\t\t6.Eliminar repetidos");
		printf("\n\t\t7.Eliminar repetidos eficiente");
		printf("\n\t\t8.Insertar por final");
		printf("\n\t\t9.Eliminar Primos");
		printf("\n\t\t10.Invertir Lista");
		printf("\n\t\t11.Ordenar Lista por Intercambio");
		printf("\n\t\t12.Ordenar Lista por Burbuja");
		printf("\n\t\t13.Ordenar Lista por Inserccion");
		printf("\n\t\t14.Vaciar Lista");
		printf("\n\t\t0.Salir");
		printf("\n\n\t\tSu opcion => "); scanf("%i",&op);
		
		switch(op){
			case 1:printf("\n\n\t\tValor a insertar "); scanf("%i",&x);
						insertar(&p,x); break;
			case 2:mostrar(p,'P'); break;
			case 3:printf("\n\n\t\tValor a eliminar ");
					 scanf("%i",&x);
					 eliminar(&p,x); break;
			case 4:  printf("\n\nIndique el valor a buscar ");
					 scanf("%i",&x);
					 if (buscar(p,x)) printf("\n\n\t\tEl valor %i esta en la lista");
					 else printf("\n\n\t\tNo esta %i en la lista");
					 break;
			case 5:printf("\n\nIndique el valor a buscar "); scanf("%i",&x); contador = (buscar2(p,x));
					 if (contador) printf("\n\n\t\tEl valor %i esta en la lista %i veces ",x,contador);
					 else printf("\n\n\t\tNo esta %i en la lista");
					 break;
			case 6: eliminarepetidos(p); break;		 		 
			case 7: eliminarepetidos_2(p); break;		 	 			 
			case 8: printf("\n\n\t\tValor a insertar "); scanf("%i",&x); insertarporf(&p,x); break;
			case 9: eliminarprimo(&p); break;
			case 10: mostrar(invertir(&p),'P'); break;
			case 11: ordenarintercambio(&p); break;
			case 12: ordenarburbuja(&p); break;
			case 13: ordenarinserccion(&p);	break;     
			case 14: while(p)vaciar(&p); break;
		}
		printf("\n\n\t\t");
		system("pause");
	}
	return 0;
}
