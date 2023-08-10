#include <stdio.h>

int verificarLista(int lista[], int tamanho) {
    int crescente = 0, decrescente = 0;
    
    for (int i = 0; i < tamanho - 1; i++) {
        if (lista[i] > lista[i + 1]) {
            decrescente = 1;
        } else if (lista[i] < lista[i + 1]) {
            crescente = 1;
        }
        if(crescente && decrescente) {
            return 0;
        }
    }
    
    if (crescente) {
        return 1;
    } else if (decrescente) {
        return -1;
    }
    
    return 9;
}

int main() {
    int resultado;
    int listaCrescente[] = {1, 2, 3, 4, 5, 7, 9};
    int tamanhoCrescente = sizeof(listaCrescente) / sizeof(listaCrescente[0]);
    resultado = verificarLista(listaCrescente, tamanhoCrescente);
    printf("Tipo: %d\n", resultado);

    int listaDecrescente[] = {5, 4, 3, 2, 1, 0, 0};
    int tamanhoDecrescente = sizeof(listaDecrescente) / sizeof(listaDecrescente[0]);
    resultado = verificarLista(listaDecrescente, tamanhoDecrescente);
    printf("Tipo: %d\n", resultado);

    int listaConstante[] = {2, 2, 2, 2, 2, 2};
    int tamanhoconstante = sizeof(listaConstante) / sizeof(listaConstante[0]);
    resultado = verificarLista(listaConstante, tamanhoconstante);
    printf("Tipo: %d\n", resultado);

    int listaDesordenada[] = {3, 1, 4, 2, 5};
    int tamanhoDesordenada = sizeof(listaDesordenada) / sizeof(listaDesordenada[0]);
    resultado = verificarLista(listaDesordenada, tamanhoDesordenada);
    printf("Tipo: %d\n", resultado);

    return 0;
}
