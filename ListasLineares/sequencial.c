#include <stdio.h>

#define MAX 100

typedef struct {
    int chave;
} registro;

typedef struct {
    registro a[MAX];
    int nElem
} lista_seq;


int inicializar(lista_seq* l) {
    l -> nElem = 0;
}

int anexar(lista_seq* l, int ch) {
    if (l->nElem == MAX) return 0;
    l->a[l->nElem].chave = ch;
    l->nElem++;
    return 1;
}

void exibir(lista_seq* l) {
    int i;

    for(i = 0; i < l->nElem; i++) {
        printf("%d", l->a[i].chave);
    }
}

//retorna indice ou -1
int buscaSeq(lista_seq*l, int ch) {
    int i;

    for(i = 0; i< l->nElem; i++) {
        if(l->a[i].chave == ch) {
            return i;
        }
    }

    return -1; //não encontrou
}

int buscaBin(lista_seq* l, int ch) {
    int fim = l->nElem;
    int inicio = 0;

    while (inicio < fim) {
        int meio = fim / 2;

        if(l->a[meio].chave < ch) inicio = meio +1;

        else {
            if(l->a[meio].chave > ch) 
                fim = meio -1;
            else return meio;
        }
    }
    
    return -1;   
}

int excluir(lista_seq* l, int ch) {
    int atual = buscaSeq(l, ch);

    if(atual == -1) return 0;

    for(int i = atual; i < l->nElem; i ++) {
        l->a[i] = l->a[i + 1];
    }

    l->nElem--;
}

int main() {
    lista_seq l;

    inicializar(&l);

    return 0;
}