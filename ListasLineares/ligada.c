#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int chave;
    int prox;
} registro;

typedef struct {
    int inicio;
    int dispo;
    registro A[MAX];
} lista_ligada_estatica;

void inicializar(lista_ligada_estatica* l) {
    l->inicio = -1;
    int i;

    for (i = 0; l < MAX-1; i++) {
        l->A[i].prox = i + 1;
        l->A[MAX-1].prox = i - 1;
        l->dispo = 0;
    }

    return;
}

int tamanho(lista_ligada_estatica* l) {
    int i = l->inicio;
    int count = 0;

    while(i!=-1) {
        count ++;
        i = l-> A[i].prox;
    }

    return count;
}

int ultimaChave(lista_ligada_estatica* l) {
    int i = l->inicio;

    while(i!=-1) {
        if(l->A[i].prox == -1) return i;
        i = l->A[i].prox;
    }

    return -1;
}

int busca(lista_ligada_estatica*l, int ch, int ant) {
    int i = l->inicio;

    while(i!=-1) {
        if(l->A[i].chave == ch) return i;
        ant = i;
        i = l->A[i].prox;
    }

    return -1;
}

//bool verificafica se a lista é igual
//fazer o msm no arquivo sequencial

void devolver(lista_ligada_estatica* l, int atual) {
    l->A[atual].prox = l->dispo;
    l->dispo = atual;

    return;
}

bool exlcuir(lista_ligada_estatica*l, int ch) {
    int ant;
    int atual = busca(l, ch, &ant);

    if (atual ==-1) return false;
    if(ant > -1)
        l->A[ant].prox = l->A[atual].prox;
    else
        l->inicio = l->A[atual].prox;

    //incompleto
    return true;
}

int obterEndereço(lista_ligada_estatica* l) {
    if(l->dispo == -1) return -1;
    
    int resp = l->dispo;
    l->dispo = l->A[l->dispo].prox;

    return resp;
}

bool inserir(lista_ligada_estatica*l, int ch) {
    int ant;
    int atual = busca(l, ch, &ant);
    if(atual != -1) return false; //em caso de já existir

    int novo = obterEndereço(l);
    if(novo == -1) return false; //vetor cheio

    l->A[novo].chave = ch;
    //caso 1: lista vazia
    if(l->inicio == -1) {
        l->inicio = novo;
        l->A[novo].prox = -1;
        
        return true;
    }
    //caso2: inserção "no meio"
    if(ant > -1) {
        l->A[novo].prox = l->A[ant].prox;
        l->A[ant].prox = novo;

        return true;
    } else {
        l->A[novo].prox = l->inicio;
        l->inicio = novo;
    }

    return true;
}

bool moverParaFrente(lista_ligada_estatica*l, int i, int ant) {
    if(l->inicio == i) return false; //se já estiver na frente

    //passa o proximo do atual para o proximo do anterior
    l->A[ant].prox = l->A[i].prox;

    l->A[i].prox = l->inicio;
    l->inicio = i;

    return true;
}

bool moverParaTras(lista_ligada_estatica* l, int i) {
    //I - achar o ultimo elemento da lista
    //II - achar o atual e o seu anterior

    int ultimo, atual = l->inicio, anterior;

    if(l->A[i].prox == -1) return false; //se já estiver no final

    while(atual != -1) {
        if(l->A[atual].prox == i) {
            anterior = atual;
        }
        
        ultimo = atual;
        atual = l->A[atual].prox;
    }

    l->A[anterior].prox = l->A[i].prox;
    l->A[ultimo].prox = i;
    l->A[i].prox = -1;

    return true;
}

int main() {
    return 0;
}