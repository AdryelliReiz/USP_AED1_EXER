#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
} No;

typedef struct lista {
    No* inicio;
} lista_circ;

typedef struct {
    No* inicio;
    No* sent;
} lista_sent;

void inicializar(lista_sent*l) {
    l->sent = (No*)malloc(sizeof(No*));
    l->inicio = l->sent;
}

void exibir(lista_sent*l) {
    No* p = l->inicio;
    while(p != l->sent) {
        printf("%d", p->chave);
        p = p->prox;
    }
}

void exibirListaCicular(lista_circ*l) {
    No* p = l->inicio;
    while(p) {
        printf("%d", p->chave);
        p = p->prox;

        if(p == l->inicio) break;
    }
}

void excluirPrimeiro(lista_circ*l) {
    if(l->inicio) {
        No* ult = ultimo(l->inicio);
        ult->prox = l->inicio->prox;
        No* aux = l->inicio;
        l->inicio = l->inicio->prox;

        if(l->inicio == aux) 
            l->inicio = NULL; //se ainda for o inicio... deixa o inicio da lista como NULL

        free(aux);
    }
}

No* ultimo(No* inicio) {
    No* ult = NULL;
    No* p = inicio;

    while(p) {
        ult = p;
        p = p->prox;
        if(p == inicio) break;
    }
    return ult;
}


int main() {
    return 0;
}