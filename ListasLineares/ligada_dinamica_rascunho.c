#include <stdio.h>
#include <stdbool.h>
#include <stdbool.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
} No;

int main() {
    No* novo = (No*)malloc(sizeof(No));
    
    novo->chave = 10;
    novo->prox = NULL;
    No* aux = novo;

    novo->chave = 0;

    printf("%d", aux->chave);
    
    novo = NULL;

    novo->chave = 1; //Erro

    novo = (No*)malloc(sizeof(No));
    novo->chave = 1;
    novo->prox = NULL;

    No* inicio = aux; 

    free(inicio);

    inicio = novo;

    return 0;
}