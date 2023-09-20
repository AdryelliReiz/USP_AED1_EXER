#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
} No;

typedef struct lista {
    No* inicio;
} lista_lig_din;//dinamica

void inicializar(lista_lig_din* l) {
    l->inicio = NULL;
}

void exibir(lista_lig_din* l) {
    No* p = l->inicio;
    while(p != NULL) {
        printf("%d", p->chave);
        p = p->prox;
    }
}

//código pensado em uma lista ordenada e sem repetição
No* busca(lista_lig_din*l, int ch, No* * ant) {
    * ant = NULL;
    No* p = l->inicio;
    while(p) {
        if(p->chave == ch) return p;
        if(p->chave > ch) return NULL;
        *ant = p;
        p = p->prox;
    }

    return NULL;
}

bool excluir(lista_lig_din*l, int ch) {
    No* ant;
    No* atual = busca(l, ch, &ant);

    if(!atual) return false;//chave não existe

    //se não existir anterior
    //se o atual for o primeiro elemento da lista
    if(ant) ant->prox = atual->prox;
    else l->inicio = atual->prox;

    free(atual);
    return true;
}

bool inserir(lista_lig_din*l, int ch) {
    No* ant;
    No* atual = busca(l, ch, &ant);

    if(atual) return false; //já existe

    No* novo = (No*) malloc(sizeof(No));
    novo->chave = ch;

    //adiciona no meio da lista
    if(ant) {
        novo->prox = ant->prox;
        ant->prox = novo;
    } else { //adicionar no inicio da lista
        novo->prox = l->inicio;
        l->inicio = novo;
    }
}

//falar com o professor depois !!!
bool moverParaFrente(lista_lig_din*l, int ch) {
    No* ant;
    if(l->inicio && l->inicio->chave == ch) return false;

    No* p = busca(l, ch, &ant);

    if(ant) ant->prox = p->prox;
    else l->inicio = p->prox;

    p->prox = l->inicio;
    l->inicio = p; 
}

void destruir(lista_lig_din*l) {
    No* p = l->inicio;

    while(p) {
        No* aux = p->prox;
        free(p);
        p = aux;
    }

    l->inicio = NULL;
}

//atividade
//ex1: seja uma lista que aceita chaves repetidas, sem ordem
//problema: eliminar todas ocorrências de uma chave ch
void eliminarRepeticao(lista_lig_din* l, int ch) {
    No* p = l->inicio;

    while(p) {
        No* ant;
        No* aux = p->prox;
        if(p->chave == ch) {
            if(l->inicio == p) {
                l->inicio = p->prox;
            } else {
                ant->prox = p->prox;
            }
            
            free(p);
        }
        ant = p;
        p = aux;
        
    }
}
//correção do exercicio acima
void excluirOcorrencias(lista_lig_din*l, int ch) {
    No* ant = NULL;
    No* p = l->inicio;

    while(p) {
        No* aux = p->prox;
        if(p->chave == ch) {
            if(ant)
                ant->prox = p->prox;
            else l->inicio = p->prox;

            free(p);
        }
        else ant = p;
        p = aux;
    }
}

//excluir o 1° elemento
void exluirPrimeiro(lista_lig_din* l) {
    //usar o Free para liberar esse espaço
}

int main() {
    /*No* inicio = NULL;
    inicio = (No*)malloc(sizeof(No));*/

    lista_lig_din l;
    inicializar(&l);

    int ch;
    scanf("%d", &ch);
    inserir(&l, ch);

    exibir(&l);

    return 0;
}