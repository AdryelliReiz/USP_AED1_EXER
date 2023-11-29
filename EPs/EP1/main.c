#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char* nroUSP() {
    return("14714019");
}


char* nome() {
    return("Adryelli Reis dos Santos");
}

// elemento da lista
typedef struct estr {
    int chave;
    struct estr* prox;
} NO;

//funções auxiliares
void exibirLista(NO* p) {
    NO* atual = p;
    NO* primeiroElemento = p;

    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->prox;

        if(atual == primeiroElemento) {
            break;
        }
    }

    printf("\n");
}
//OK
NO* acharSegmentoCompartilhado(NO* *p1, NO* *p2, NO* *ant1, NO* *ant2) {
    NO* atual1 = *p1;
    NO* atual2 = *p2;
    NO* segmentoCompartilhado = NULL;

    //procura o seguimento a partir da verificação de cada elemento da lista 1
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

    printf("seg: %d", segmentoCompartilhado->chave);

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

//função principal
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

    NO* atual1 = *p1;
    exibirLista(atual1);

    NO* atual2 = *p2;
    exibirLista(atual2);

	return;
}

//funções auxiliares para teste
NO* inicializar() {
    NO* p = (NO*)malloc(sizeof(NO));

	p = NULL;
    return p;
}

NO* busca(NO* p, int ch) {
    NO* atual = p;
    NO* ant = NULL;

    while (atual != NULL) {
        if (atual->chave == ch) {
            return atual;
        }
        ant = atual;
        atual = atual->prox;
    }

    return NULL;
}

void inserir(NO** p1, NO** p2, int ch) {
    NO* ant_p1 = NULL;
    NO* atual_p1 = *p1;
    NO* ant_p2 = NULL;
    NO* atual_p2 = *p2;
    NO* chave_igual = NULL;
	int interligadas = -1;

    // Percorre até o final da lista 1
    if(atual_p1 == NULL) {
        atual_p2 = *p2;

        while (atual_p2 != NULL) {
            if (interligadas == -1) {
				if(atual_p2->chave == ch) {
					chave_igual = atual_p2;
                    interligadas = 0;
				}
            }
            ant_p2 = atual_p2;
            atual_p2 = atual_p2->prox;
        }
    } else {
        while (atual_p1 != NULL) {
            atual_p2 = *p2;

            while (atual_p2 != NULL) {
                if (interligadas == -1) {
                    if(atual_p2->chave == ch) {
                        chave_igual = atual_p2;
                    }
                    if(atual_p1->chave == atual_p2->chave) {
                        interligadas = 0;
                    }
                }
                ant_p2 = atual_p2;
                atual_p2 = atual_p2->prox;
            }

            ant_p1 = atual_p1;
            atual_p1 = atual_p1->prox;
        }
    }

    // Primeiro caso: já existe uma ligação entre as duas listas
    // Só adiciona no final
    // Segundo caso: ainda não existe, mas vai adicionar

    if (chave_igual !=  NULL) {
        if (ant_p1 == NULL) {
            // Inserir no início da lista se ela for vazio
            *p1 = chave_igual;
        } else {
			//adiciona no fim da lista interligada com a segunda
			//se já forem interliagas
			if(interligadas == -1) {
				ant_p1->prox = chave_igual;
			} else {
				NO* novo = (NO*)malloc(sizeof(NO));
				novo->chave = ch;
				novo->prox = NULL; //define novo como o último nó da lista
				ant_p1->prox = novo;
			}
        }
    } else {
        // Caso simples, ainda não existe nó ligado entre as listas
        NO* novo = (NO*)malloc(sizeof(NO));
        novo->chave = ch;
        novo->prox = NULL; // Define novo como o último nó da lista

        if (ant_p1 == NULL) {
            // Inserir no início da lista.
            *p1 = novo;
        } else {
            // Inserir após o nó ant_p1.
            ant_p1->prox = novo;
        }
    }
}


// por favor nao inclua nenhum codigo a ser entregue abaixo deste ponto

//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

	//NO* p1 = NULL;
	//NO* p2 = NULL;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste nas listas p1 e p2

	NO* p1 = inicializar();
	NO* p2 = inicializar();

	
	for(int i = 0; i < 5; i++){
		int scanf_recebe;
		scanf("%d", &scanf_recebe);

		inserir(&p1, &p2, scanf_recebe);
	}

	for(int i = 0; i < 5; i++){
		int scanf_recebe;
		scanf("%d", &scanf_recebe);

		inserir(&p2, &p1, scanf_recebe);
		exibirLista(p2);
	}

    printf("LISTA 1!\n");
	exibirLista(p1);
    printf("LISTA 2!\n");
	exibirLista(p2);

	// o EP sera testado com chamadas deste tipo
	removerCompartilhados(&p1, &p2);

    printf("LISTA 1!\n");
	exibirLista(p1);
    printf("LISTA 2!\n");
	exibirLista(p2);

}

