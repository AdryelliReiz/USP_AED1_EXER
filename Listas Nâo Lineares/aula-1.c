#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s {
    int chave;
    struct s * esq;
    struct s * dir;
} NO;

NO* buscaOrdenada(NO* raiz, int ch) {
    NO* atual = raiz;

    while(atual) {
        if(atual->chave == ch) return atual;

        if(atual->chave > ch) {
            atual = atual->esq;
        } else atual = atual->dir;
    }

    return NULL;
}


int main() {
    NO* raiz = (NO*) malloc(sizeof(NO));
    raiz->chave = 0;
    raiz->esq = NULL;
    raiz->dir = NULL;

    //por aux
    NO* aux = (NO*) malloc(sizeof(NO));
    aux->chave = 0;
    aux->esq = NULL;
    aux->dir = NULL;

    raiz->esq = (NO*) malloc(sizeof(NO));

    return 0;
}