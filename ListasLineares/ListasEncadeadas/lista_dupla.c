#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct est {
    int chave;
    struct est * prox;
} NO;

typedef struct est2 {
    int chave;
    struct est2 * prox;
    struct est2 * ant;
} NO2;

typedef struct list {
    NO * cab;
}lista_circular;

typedef struct list2 {
    NO2 * inicio;
}lista_dupla;

//lista dupla, s/cabeça, s/circularidade
//ex.1: Dado um elemento p garantidamente existente, mover p para início.
void moveParaFrente(lista_dupla * l, NO2 * p) {
    //se o p for o início da lista, não fazer nada
    if(p == l->inicio) return;

    //atualiza o prox do anterio para ser o prox do atual
    p->ant->prox = p->prox;
    //atualiza o anterior do prox do atual se existir prox
    if(p->prox) p->prox->ant = p->ant;
    
    //atualiza o prox do atual
    p->prox = l->inicio;
    //atualiza o anterior do atual
    p->ant = NULL;

    //atualiza o anterior do inicio
    l->inicio->ant = p;
    //atualiza o ponteiro do inicio da lista para p
    l->inicio = p;

    return;
}

//ex.2: dada uma lsta dupla, circular e com cabeça, faça uma cópia simples sem circularidade e sem cabeça
NO* copiaSemples(lista_circular * l) {
    NO* resp = NULL;
    NO* ultimo = NULL;

    //iterador da lista (começa no prox da cabeça da lista)
    NO* p = l->cab->prox;

    while(p != l->cab) {
        NO * novo = (NO*) malloc(sizeof(NO));
        novo->chave = p->chave;
        if(ultimo) ultimo->prox = novo;
        else resp = novo;

        novo->prox = NULL;
        ultimo = novo;
        
        p = p->prox;
    }

    return resp;
}

int main() {
    return 0;
}