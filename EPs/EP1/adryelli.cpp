#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char* nroUSP() {
    return("14714019, 14747191");
}

char* nome() {
    return("Adryelli Reis dos Santos, João Paulo Fernandes Fontanezi");
}

// elemento da lista
typedef struct estr {
    int chave;
    struct estr* prox;
} NO;

//FUNÇÕES AUXILIARES

NO* acharSegmentoCompartilhado(NO* *p1, NO* *p2, NO* *ant1, NO* *ant2) {
    NO* atual1 = *p1;
    NO* atual2 = *p2;
    NO* segmentoCompartilhado = NULL;

    //procura o seguimento a partiacharSegmentoCompartilhador da verificação de cada elemento da lista 1
    //para cada elemento na lista 2
    while(atual1 != NULL) {
        atual2 = *p2;
        *ant2 = NULL;
            
        while (atual2 != NULL) {
            if(atual1 == atual2) {
                segmentoCompartilhado = atual1;
                break;
            }

            *ant2 = atual2;
            atual2 = atual2->prox;
        }
        if(segmentoCompartilhado != NULL) {
            break;
        }
        *ant1 = atual1;
        atual1 = atual1->prox;
    }

    return segmentoCompartilhado;
}

void excluirSegmento(NO* elemento) {
    NO* aux = elemento;

    while(aux != NULL) {
        NO* prox = aux->prox;

        free(aux);
        aux = prox;
    }

    return;
}

//FIM DAS AUXILIARES

//FUNÇÃO PRINCIPAL
void removerCompartilhados(NO* *p1, NO* *p2) {
	NO* ant_p1 = NULL;
    NO* ant_p2 = NULL;

    //acha o elemento compartilhado entre as listas
    NO* seg = acharSegmentoCompartilhado(p1, p2, &ant_p1, &ant_p2);

    //se não existir o elemento compartilhado, nem precisa terminar a função
    if(seg == NULL) return;

    //fazer a remoção do elemento e seus sucessores
    excluirSegmento(seg);

    //faz as listas serem circulares
    if(ant_p1!=NULL) ant_p1->prox = *p1;
    else *p1 = NULL;
    
    if(ant_p2!=NULL) ant_p2->prox = *p2;
    else *p2 = NULL;

	return;
}