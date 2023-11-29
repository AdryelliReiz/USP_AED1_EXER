#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct est {
    int chave;
    struct est * prox;
    struct est * ant;
} NO;

typedef struct list2 {
    NO * inicio1;
    NO * inicio2;
} deque;

//verifica se o deque é vazio
bool dequeVazio(deque* d) {
    if(!d->inicio1) return (true);
    else return (false); //tem elementos
}

NO* sairInicio2(deque* d) {
    //verifica se a lista for vazia
    if(d->inicio2 == NULL) return NULL;

    NO* resp = d->inicio2;
    d->inicio2 = d->inicio2->ant;
    if(d->inicio2) {
        d->inicio2->prox = NULL;
    } else d->inicio1 = NULL;

    return resp;
}

int main() {
    return 0;
}