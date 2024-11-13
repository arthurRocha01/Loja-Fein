#include "structs.h"
#include <stdlib.h>
#include <string.h>

void inicializar_lista(ListaProdutos *lista, size_t capacidade)
{
    lista->produtos = malloc(capacidade * sizeof(char *));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

void adcionar_produto(ListaProdutos *lista, char *produto)
{
    if (lista->tamanho >= lista->capacidade)
    {
        lista->capacidade *= 2;
        lista->produtos = realloc(lista->produtos, lista->capacidade * sizeof(char *));
    }

    lista->produtos[lista->tamanho] = strdup(produto);
    lista->tamanho++;
}

void liberar_lista(ListaProdutos *lista)
{
    for (size_t i = 0; i < lista->tamanho; i++)
    {
        free(lista->produtos[i]);
    }
    free(lista->produtos);
    lista->tamanho = 0;
    lista->capacidade = 0;
}