#include<iostream>
#include<stdlib.h>
using namespace std;

// Pilha
struct itemfila{
	int valor;
	struct itemfila *prox;
}*prim,*ult,*aux;

void enfileirar(int v);
void desinfileirar();
int primeiroFila();

main(){
	int op,v,primeiro;
	do{
		cout << "1 - enfileirar\n";
		cout << "2 - desinfileirar\n";
		cout << "3 - primeiro da fila\n";
		cout << "4 - sair\n";
		cin >> op;
		switch(op){
			case 1:
				cout << "Digite um valor: ";
				cin >> v;
				enfileirar(v);
				break;
			case 2:
				 desinfileirar();
				break;
			case 3:
				primeiro = primeiroFila();
				if(primeiro != -1){
					cout << "Primeiro da fila: " << primeiro << "\n";
				} else{
					cout << "fila vazia\n";
				}	
				break;
		}
	}while(op != 4);
}

void enfileirar(int v){
	aux = (struct itemfila *) malloc(sizeof(struct itemfila));
	if(prim == NULL){
		prim = aux;
	} else{
		ult->prox = aux;
	}
	ult = aux;
	ult->valor = v;
	cout << "Item enfileirado\n";
}

void desinfileirar(){
	if(prim != NULL){
		aux = prim;
		if(prim == ult){
			prim = ult = NULL;
		} else{
			prim = prim->prox;			
		}
		cout << "Item desifileirado: " << aux->valor << "\n";
		free(aux);
	} else{
		cout << "Fila vazia\n";
	}
}

int primeiroFila(){
	if(prim != NULL){
		return(prim->valor);
	} else{
		return (-1);
	} 
}
