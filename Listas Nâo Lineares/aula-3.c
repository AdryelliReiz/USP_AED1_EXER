#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITO 0.00

typedef struct s {
    int chave;
    struct s * esq;
    struct s * dir;
} NO;

typedef struct l {
    int chave;
    struct pl * prox;
} NOL;

typedef struct f {
    int chave;
    struct f * prox;
} NOF;

typedef struct lista_ligada {
    struct l * inicio;
} LIGADA;

typedef struct lista_fila {
    struct f * inicio;
    struct f * fim;
} FILA;

bool iguais(NO* p1, NO* p2) {
    if(!p1 && !p2) return true; //chegou no fim da estrutura e elas são iguais
    if(!p1 || !p2) return false; //chegou no fim da estrutura e elas não são iguais
    if(p1->chave != p2->chave) return false; //chaves diferentes, já restorna false

    bool ok = iguais(p1->esq, p2->dir); //recursão para a esquerda
    if(ok) return iguais(p1->dir, p2->dir); //se continuar sendo iguais, recursão para a direita
    else return false; //já não é verdadeiro, só retornar falso
}

void destruir(NO* *p) {
    if(*p) {
        destruir(&(p)->esq);
        destruir(&(p)->dir);
        free(*p);
    }
    *p = NULL;
}

void emNivel(NO* p) {
    FILA* F;
    iniciarlizarFila(&F);
    entrarFila(&F, p); {
        while(F->inicio) {
            p = sairFila(&F);
            visitar(p);
            //colocar um if de verifiicação
            entrarFila(&F, p->esq);
            entrarFila(&F, p->dir);
        }
    }
}

//ex: fazer uma função recursiva de busca binária

/* EXCLUIR P DADO SEU PAI
(1) excluir folha: ajustar pai + free(p)
(2) excluir p com apenas 1 filho: pai concta com filho de p + free(p)
(3) excluir p com 2 filhos: maiorir da subárvore esquerda (um passo à esquerda, e direita até NULL)
ou
menor elemento da subárvore direita (um passo à direita, e esquerda até NULL)
*/

//ex: dada uma árvore ordenada, retorne sua menor chave, ou inifinito
int acharMenor(NO* p) {
   while(p) {
        if(p->esq == NULL) return p->chave;
        p = p->esq;
   } 

   return INFINITO;
}

//ex: menor chave em árvore não ordenada (resp = INFINITO)
void menor(NO* p, int* resp) {
    if(p) {
        if(p->chave < *resp) *resp = p->chave;

        menor(p->esq, &resp);
        menor(p->dir, &resp);
    }
}

//listas NOs pais
void listarNOsInteriores(NO* p, NOL* *inicio) {
    if(p) {
        if(p->esq || p->dir) {
            NOL* novo = (NOL*) malloc(sizeof(NOL));
            novo->chave = p->chave;
            novo->prox = *inicio;
            *inicio = novo;
        }

        listarNOsInteriores(p->esq, &inicio);
        listarNOsInteriores(p->dir, &inicio);
    }
}

int main() {
    NO* raiz = (NO*) malloc(sizeof(NO));
    raiz->chave = 0;
    raiz->esq = NULL;
    raiz->dir = NULL;

    return 0;
}