# Resumo sobre as estruturas de dados

## FILAS
As filas são estruturas (inicio e fim) que possuem NOs com propriedades: chave e prox
Sempre remove os elementos a partir do início e adiciona no fim da lista

## SENTINELA:
- O nó sentinela, criado ao final de uma lista, é usado para armazenar a chave de busca e assim acelerar o
respectivo algoritmo, uma vez que reduz o número de comparações necessárias pela metade.

## CABEÇA:
- O nó cabeça, criado no início de uma lista, é usado para simplificar o projeto dos algoritmos de inserção e
exclusão. Pode também armazenar a chave de busca (funcionando como nó sentinela) quando a lista for
circular.

## Pilhas
Os elementos são armazenados empilhados um encima do outro.
A lista possui uma própriedade `topo`que aponta para o último elemento da lista.
Sempre remove ou adiciona elementos a partir do topo da lista
Elementos com propriedade principais: `ch` e `prox`

## Deques
Deques são filas que permitem tanto entrada quanto retirada em ambas extremidades.Neste caso não faz mais
sentido falar em início e fim de fila, mas simplesmente início1 e início2.
Elementos com propriedade principais: `ch`, `prox` e `ant`


## Matrizes esparsas
Matrizes esparsas são matrizes nas quais a maioria das posições é preenchida por `zeros`. Para essas matrizes, podemos economizar um espaço significativo de memória se apenas os termos diferentes de zero forem armazenados. As operações usais sobre essas matrizes (somar, multiplicar, inverter, pivotar) também podem ser feitas em tempo muito menor se não armazenarmos as posições que contêm zeros.
Uma maneira eficiente de presentar estruturas com tamanho variável e/ou desconhecido é com o emprego de alocação encadeada, utilizando listas. Vamos usar essa representação para armazenar as matrizes esparsas. Cad `coluna` da matriz será representada por uma `lista linear circular` com uma `célula cabeça`. Da mesma maneira, cada `linha` da matriz também será representada por uma `lista linear circular` com uma `célula cabeça`.