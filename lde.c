#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
	struct nodo* atras;

}nodo;


nodo* primero = NULL;
nodo* ultimo = NULL;

void insertar();
void recorrerPU();
void recorrerUP();
void modificar();
void eliminar();

int main(){

	
	insertar();

	recorrerPU();
	eliminar();
	recorrerPU();
	return 0;
}

void insertar(){

	nodo* nuevo=(nodo*)malloc(sizeof(nodo));
	printf("Ingrese el nuevo dato: ");
	scanf("%d",&nuevo->dato);

	if(primero==NULL){
		primero=nuevo;
		primero->siguiente=NULL;
		primero->atras=NULL;
		ultimo=nuevo;
	}else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		nuevo->atras=ultimo;
		ultimo=nuevo;
	}
}


void recorrerPU(){

	nodo* actual=(nodo*)malloc(sizeof(nodo));

	actual=primero;

	if(primero!=NULL){
		while(actual!=NULL){
			printf("%d \n ",actual->dato);
			actual=actual->siguiente;
		}
		
	}else{
		printf("La lista está vacía.\n  " );
	}

}


void recorrerUP(){

	nodo* actual=(nodo*)malloc(sizeof(nodo));
	actual=ultimo;

	if(ultimo!=NULL){

		while(actual!=NULL){
			printf("%d \n",actual->dato);
			actual=actual->atras;
		}

	}else{
		printf("La lista se encuentra vacía. \n");

	}


}


void modificar(){

	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual=primero;
	int nodoPorBuscar=0, encontro=0;


	if(primero!=NULL){
		printf("\nIngrese el número a buscar: ");
		scanf("%d",&nodoPorBuscar);

		while(actual!=NULL && encontro!=1){

			if(actual->dato==nodoPorBuscar){
				printf("\nEl nodo fue encontrado.");
				printf("\nIngrese un nuevo valor para el nodo: ");
				scanf("%d",&actual->dato);
				encontro=1;

			}
			actual=actual->siguiente;

		}

		if(encontro==0){
			printf("\nEl nodo no se encontró.");
		}



	}else{
		printf("\nLa lista está vacía.");
	}


}


void eliminar(){
	nodo* actual=(nodo*)malloc(sizeof(nodo));
	nodo* anterior=(nodo*)malloc(sizeof(nodo));
	anterior=NULL;
	actual=primero;
	int nodoPorBuscar=0,encontro=0;

	if(primero!=NULL){
		printf("\nIngrese el número del nodo a eliminar;");
		scanf("%d",&nodoPorBuscar);
		while(actual!=NULL && encontro!=1){
			if(actual->dato==nodoPorBuscar){

				if(actual==primero){

					if(primero->siguiente!=NULL){

						primero=primero->siguiente;
					}
					
					primero->atras=NULL;

				}else if(actual==ultimo){

					anterior->siguiente=NULL;
					ultimo=anterior;


				}else{
					anterior->siguiente=actual->siguiente;
					actual->siguiente->atras=anterior;
				}			

				printf("\nEl nodo fue eliminado con exito.");

			}
			anterior=actual;
			actual=actual->siguiente;


		}


	}else{
		printf("\nLa lista está vacía.");

	}

}

