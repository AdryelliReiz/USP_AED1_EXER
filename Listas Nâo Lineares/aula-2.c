#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s {
    int chave;
    struct s * esq;
    struct s * dir;
} NO;

typedef struct p {
    int chave;
    struct p * prox;
} NOP;

typedef struct lista_pilha {
    struct p * inicio;
} PILHA;

void preOrdem(NO* raiz) {
    PILHA pi;

    iniciarlizarPilha(&pi);

    NO* p = raiz;
    while(true) {
        while(p) {
            visitar(p);
            if(p->dir) push(&pi, p->dir);
        }
        p = p->esq;
        p = pop(&p);
        if(!p) break;
    }

}

void preOrdem2(NO* p) {
    if(p) {
        visitar(p);
        preOrdem2(p->esq);
        preOrdem2(p->dir);
    }
}

void contar(NO* p, int* resp) {
    if(p) {
        *resp = *resp + 1;
        contar(p->esq, &resp);
        contar(p->dir, &resp);
    }
}

int contarDireto(NO* p) {
    if(!p) return 0;
    else return (1 + contarDireto(p->esq) + contarDireto(p->dir));
}

//função auxiliar
int mac(int a, int b) {
    if(a > b) return a;
    else return b;
}

int altura(NO* p) {
    if(!p) return 0;
    if(!p->esq && !p->dir) return 1;    //tlvz seja desnecessário

    return (1 + max(altura(p->esq), altura(p->dir)));
}

void buscaDesordenada(NO* p, int ch, NO* *resp) {
    if(p) {
        if(p->chave == ch) {
            *resp = p;
        }
        if(*resp == NULL) buscaDesordenada(p->esq, ch, resp);
        if(*resp == NULL) buscaDesordenada(p->dir, ch, resp);
    }
}

NO* copia(NO* p) {
    if(!p) return NULL;
    
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->chave = p->chave;
    novo->esq= copia(p->esq);
    novo->dir = copia(p->dir);

    return novo;
}


int main() {
    NO* raiz = (NO*) malloc(sizeof(NO));
    raiz->chave = 0;
    raiz->esq = NULL;
    raiz->dir = NULL;

    return 0;
}