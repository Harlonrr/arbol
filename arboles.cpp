#include <iostream>
using namespace std;

struct nodo {
    int value;
    nodo *izq;
    nodo *der;
}; 

nodo *raiz, *aux, *aux2; 

int posicionar(){
    if(aux->value < aux2->value){
        if(aux2->izq == NULL){
            aux2->izq = aux;
        } else {
            aux2 = aux2->izq;
            posicionar();
        }
    } else {
        if(aux2->der == NULL){
            aux2->der = aux;
        } else {
            aux2 = aux2->der;
            posicionar();
        }
    }
}

int registrar(){
    aux = ((struct nodo *) malloc (sizeof(struct nodo)));
    cout<<"Cual es el valor: "<<endl;
    cin>>aux->value;
    aux->izq = NULL;
    aux->der = NULL;
    if(!raiz){
        raiz = aux;
    } else {
        aux2 = raiz;
        posicionar();
    }
}

void mostrarInOden(nodo *raiz) {
    if (raiz != NULL) {
        mostrarInOden(raiz->izq);
        cout << raiz->value << " ";
        mostrarInOden(raiz->der);
        
    }
}

int main(){
    int opc=0;
    do {
        cout<<"1. Registrar"<<endl;
        cout<<"2. mostrarInOden"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1: 
            registrar();
            break;
        case 2:
            cout << "Mostrando el arbol en orden: ";
            mostrarInOden(raiz);
            cout << endl;
            break;
        }

    } while(opc!=5);
}
