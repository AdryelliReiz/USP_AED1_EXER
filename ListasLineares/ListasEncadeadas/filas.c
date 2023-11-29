#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct est {
    int chave;
    struct est * prox;
} NO;


typedef struct list {
    NO * inicio;
    NO * fim;
}fila;


//
void retornaChave(fila* f, int ch) {
    NO* ant= NULL;
    //algum codigo de busca padrão
    NO* p = busca(f->inicio, ch, &ant);

    if(!p) return;

    //atualiza o "prox" do anterior
    if(ant) ant->prox = p->prox;
    else f->inicio = p->prox;

    if(p == f->fim) {
        if(ant) f->fim = ant;
        else f->fim = NULL;
    }

    free(p);
}

void entrarNaFila(fila* f, int ch) {
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;

    if(f->fim) {
        f->fim->prox = novo;
    } else {
        f->inicio = novo;
    }

    f->fim = novo;

    return;
}

void exibir(NO* p) {
    if(p) {
        printf("%d ", p->chave);
        exibir(p->prox);
    }
}

int main() {
    return 0;
}