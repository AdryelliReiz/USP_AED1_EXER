#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

//fila
typedef struct est {
    int chave;
    struct est * prox;
} NO;


typedef struct list {
    NO * inicio;
    NO * fim;
} fila;

//pilha
typedef struct est2 {
    int chave;
    struct est2 * prox;
} NO2;


typedef struct list2 {
    NO2 * topo;
} pilha;

//lista circular
typedef struct list_ {
    NO * inicio;
} lista;

//deque
typedef struct est3 {
    int chave;
    struct est3 * prox;
    struct est3 * ant;
} NO3;

typedef struct list3 {
    NO3 * inicio1;
    NO3 * inicio2;
} deque;

//matrizes esparsas
typedef struct est4 {
    int info;
    int l;
    int c;
    struct est4 * prox;
} NO4;

typedef struct list4 {
    NO4* inicio;
    int MAXlin;
    int MAXcol;
} Matriz;


//2. Transformar uma lista circular sem cabeça em não circular com cabeça.
void tornarNaoCircular(lista* l) {
    NO* ultimo = l->inicio;

    if(ultimo == NULL) return;
    
    do {
        ultimo = ultimo->prox;
    } while(ultimo->prox != l->inicio);

    ultimo->prox = NULL;
}

NO* adicionarCab(lista* l) {
    NO* cab = (NO*)malloc(sizeof(NO));
    cab->prox = l->inicio;

    //FINALIZAR
}

//3. Verificar se uma pilha e uma fila possuem os mesmos elementos, retornando true/false.
bool verificaPilha_Fila(fila* f, pilha* p ) {
    NO2* p1 = p->topo;
    NO* p2 = f->inicio;

    //percorrer as listas simultaneamente até o final de uma ou das duas
    while(p1 && p2) {
        if(p1->chave == p2->chave) {
            p1 = p1->prox;
            p2 = p2->prox;
        } else return false;
    }

    //uma lista terminou e a outra não, então não são iguais
    if(p1 != NULL || p2 != NULL) return false;
}

//4. Destruir um deque
void destruirDeque(deque* d) {
    NO3* atual = d->inicio1;

    while(atual) {
        NO3* prox = atual->prox;
        free(atual);
        atual = prox;
    }

    d->inicio1 = NULL;
    d->inicio2 = NULL;
}

//5. Contar zeros de uma matriz esparsa
int contarMatrizEsparsa(Matriz* mtrz) {
    int maxElementos = mtrz->MAXcol * mtrz->MAXlin;
    int contador = 0;
    int contadorZeros = maxElementos;
    
    NO4* atual = mtrz->inicio;

    while(atual) {
        contador +=1;

        atual = atual->prox;
    }

    contadorZeros -= contador;

    return contadorZeros;
}


int main() {
    NO* algum = (NO*)malloc(sizeof(NO));

    printf("Print01: %p\n", algum);
    printf("Print02: %p\n", &algum);

    return 0;
}