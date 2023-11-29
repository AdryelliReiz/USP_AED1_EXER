#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct est {
    int info;
    int l;
    int c;
    struct est * prox;
} NO;

typedef struct {
    NO* inicio;
    int MAXlin;
    int MAXcol;
} Matriz;

//devolver a informação
int valor(Matriz* m, int i, int j) {
    int resp = 0;
    NO* p = m->inicio;

    while(p) {
        if(p->l == i & p->c == j) return p->info;
        
        //ultrapassando a linha
        if(p->l > i) return 0;
        //ultrapassando a coluna na linha certa
        if(p->l == i && p->c > j) return 0;

        p = p->prox;
    }

    return 0;
}

//buscar o elemento
int valor(Matriz* m, int i, int j, NO* *ant) {
    *ant = NULL;
    NO* p = m->inicio;

    while(p) {
        if(p->l == i & p->c == j) return p;
        
        //ultrapassando a linha
        if(p->l > i) return NULL;
        //ultrapassando a coluna na linha certa
        if(p->l == i && p->c > j) return NULL;

        *ant = p;
        p = p->prox;
    }

    return NULL;
}

/*
*LEGENDA:
* variavel 0, representa que o valor é vazio
* variavel >0, representa que o existe um valor != 0 (vazio) a ser adicionado
*/

void atribuir(Matriz* m, int i, int j, int valor) {
    NO* ant;
    NO* atual = busca(m, i, j, &ant);

    //caso1: valor 0 e busca 0
    if(!atual && valor == 0) return;

    //caso2: valor >0 e busca>0
    if(atual && valor > 0) {
        atual->info = valor;
        return;
    }

    //caso3: (exclusão) valor 0 busca >0
    if(valor == 0 && atual) {
        if(ant) ant->prox = atual->prox;
        else m->inicio = atual->prox;

        free(atual);
        return;
    }

    //caso4: (inserção) valor >0 e busca atual 0
    if(valor > 0 && !atual) {
        NO* novo = (NO*)malloc(sizeof(NO));
        novo->info = valor;
        novo->l = 1;
        novo->c = j;

        if(ant) {
            novo->prox = ant->prox;
            ant->prox = novo;
        } else {
            novo->prox = m->inicio;
            m->inicio = novo;
        }

        return;
    }
}

int main() {
    return 0;
}