#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int chave;
    // outros campos...
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;
// Inicialização da lista sequencial
void inicializarListaSequencial(LISTA *l) {
    l->nroElem = 0;
}
// Exibição da lista sequencial
void exibirLista(LISTA l) {
    int i;
    for (i=0; i < l.nroElem; i++)
        printf("%d ", l.A[i].chave);
    }
    // Retornar o tamanho da lista sequencial
    int tamanho(LISTA l) {
    return(l.nroElem);
}
// Retornar a chave do primeiro elemento da lista sequencial
int primeiroElem(LISTA l) {
    if(l.nroElem > 0) return(l.A[0].chave);
    else return(-1); // lista vazia
}
// Retornar a chave do ultimo elemento da lista sequencial
int ultimoElem(LISTA l) {
    if(l.nroElem > 0) return(l.A[l.nroElem-1].chave);
    else return(-1); // lista vazia
}
// Retornar a chave do n-ésimo elemento da lista sequencial
int enesimoElem(LISTA l, int n) {
    if(n <= l.nroElem) return(l.A[n-1].chave);
    else return(-1);
}
// Destruição da lista sequencial
void destruirLista(LISTA *l) {
    l->nroElem = 0;
}

// Inserção "direta" na posição i
bool inserirElemListaSeq(int ch, int i, LISTA* l) {
    int j;
    if((l->nroElem >= MAX) || (i < 0) || (i > (l->nroElem)))
        return(false); // lista cheia ou índice inválido
    if((l->nroElem > 0) && (i < l->nroElem))
        for (j = l->nroElem; j >= (i+1); j--)
            l->A[j] = l->A[j-1];
    l->A[i].chave=ch;
    l->nroElem++;
    return(true);
}
// Busca sequencial em lista (ordenada por chave ou não)
int buscaSeq(int ch, LISTA l) {
    int i = 0;
    while (i < l.nroElem) {
        if(ch == l.A[i].chave) return(i); // achou
        else i++;
    }
    return(-1); // não achou
}
// Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições)
int buscaSent(int ch, LISTA l) {
    int i = 0;
    l.A[l.nroElem].chave = ch; // sentinela
    while(l.A[i].chave < ch) i++;
    if((i > (l.nroElem - 1)) || (l.A[i].chave != ch)) return(-1); // não achou
    else return(i);
}
// Busca binária em lista ordenada
int buscaBin(int ch, LISTA l) {
    int inf, sup, meio;
    inf = 0;
    sup = l.nroElem - 1;
    while(inf <= sup) {
        meio = ((inf + sup) / 2);
        if(l.A[meio].chave == ch) return(meio); // achou
        else {
            if(l.A[meio].chave < ch) inf = meio + 1;
            else sup = meio - 1;
        }
    }
    return(-1);
}

// Inserção em lista ordenada COM SENTINELA sem duplicação
bool inserirElemListaOrd(int ch, LISTA* l) {
    int i = 0;
    if(l->nroElem >= MAX) return(false); // lista cheia
    l->A[l->nroElem].chave = ch; // sentinela
    while(l->A[i].chave < ch) i++;
    if((l->A[i].chave == ch) && (i < l->nroElem))
    return(false);
    else return(inserirElemListaSeq(ch, i, l));
}
// Exclusão
bool excluirElemLista(int ch, LISTA* l) {
    int pos, j;
    pos = buscaSeq(ch, *l);
    if(pos == -1) return(false); // não existe
    for(j = pos; j < l->nroElem - 1; j++)
        l->A[j] = l->A[j+1];
    l->nroElem--;
    return(true);
}