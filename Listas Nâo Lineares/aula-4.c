#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s {
    int chave;
    struct s * esq;
    struct s * dir;
} NO;

typedef struct f {
    int chave;
    struct f * prox;
} NOF;

typedef struct lista_fila {
    struct f * inicio;
    struct f * fim;
} FILA;


//ex1: espelhar uma árvore
void espelhar(NO* p) {
    if(p) {
        NO* aux = p->esq;
        p->esq = p->dir;
        p->dir = aux;
        espelhar(p->esq);
        espelhar(p->dir);
    }
}

//ex2: exibir N maiores chaves de uma ABB
void exibirNMaiores(NO* p, int * N) {
    if(p) {
        exibirNMaiores(p->dir, N);
        if(*N > 0) {
            printf("%d", p->chave);
            *N = N -1;
        }

        if(*N > 0) exibirNMaiores(p->esq, N);
    }
}

//ex3: exibir n chaves mais pŕomixas da raiz
void exibirNMaisPox(NO* raiz, int N) {
    if(N == 0) return;

    FILA F = iniciarlizarFila(&F);
    entrarFila(&F, raiz);
    while(F.inicio) {
        NO* p = saiuFila(&F);
        print("%d", p->chave);
        N--;

        if(N == 0) break;
        if(p->esq) entrarFila(&F, p->esq);
        if(p->dir) entrarFila(&F, p->dir);
    }
    while(F.inicio) sairFila(&F);
}

//ex4: criar lista ligada c/todos elementos cuja chave é maior do que a do pai em árvore não ordenada

//ex5: vrificar se uma árvore é ABB, retornando TRUE/FALSE

//ex6: verificar se árvore é assimétrica,retornando true/false

//ex7: verificar se árvore é cheia, retornando TRUE/FALSE

//(avançado) ex8: dada uma ABB e uma chave ch, encontre o antecessor de ch na sequência crescente de chaves


//ex 9: verifica se é ABB

/*ex 10: encontrar o pai de um elemento ch
 (i) em árvore comum
 (ii) em ABB/AVL*/

//ex 11: exibir chaves do nível n

//ex 12: em árvore não ordenada, mover a subárvore de raiz p1 para a esquerda do p2, que é vazio

//ex 13: excluir todo filho à esquerda que tenham no máximo 1 filho usando pós ordem

//ex: encontrar o 1° ancestral comum a ch1 e ch2 em ABB


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

NO* antecessorCh(NO* atual, int ch, NO* ant) {
    if(atual) {
        //se estiver no NO da chave certa
        if(atual->chave == ch) {
            //buscar no filho da esquerda
            if(atual->esq) return antecessorCh(atual->esq, ch, atual);
            //se tiver um NO anterior (pai) e ele for menor que a chave
            if(ant && ant->chave < ch) return ant;
            else return NULL
        }
        if(atual->chave > ch) {
            return NULL;
        }
        //está percorrendo à esquerda do NO
        if(atual->chave < ch) {
            //vai percorrer à direita do filho da esquerda do NO_CHAVE
            if(atual->dir) return antecessorCh(atual->dir, ch, atual);
            return atual->chave;
        }
    } return NULL;
}

NO* acharAntecessor(NO* atual, int ch, NO*ant) {
    while(atual) {
        if(atual->chave == ch) return antecessorCh(atual, ch, ant);

        if(atual->chave > ch) {
            atual = atual->esq;
        } else atual = atual->dir;
    }

    return NULL;
}