#include "structs.h"
#include <stdlib.h>
#include <string.h>

void definir_atributo_produto(Produto *produto, char *valor, int atributo)
{
    switch (atributo)
    {
        case 0: produto->marca = strdup(valor); break;
        case 1: produto->nome = strdup(valor); break;
        case 2: produto->categoria = strdup(valor); break;
        case 3: produto->cor = strdup(valor); break;
        case 4: produto->tamanhos = strdup(valor); break;
        case 5: produto->valor = atof(valor); break;
        case 6: produto->quantidade = atoi(valor); break;
    }
}

Produto *criar_produto(char *info)
{
    Produto *produto = malloc(sizeof(Produto));
    char *campo = strtok(info, ",");
    int controle = 0;
    while (campo != NULL)
    {
        definir_atributo_produto(produto, campo, controle);
        controle++;
        campo = strtok(NULL, ",");
    }
    return produto;
}

float liberar_produto(Produto *produto)
{
    free(produto->marca);
    free(produto->nome);
    free(produto->categoria);
    free(produto->cor);
    free(produto->tamanhos);
    free(produto);
}

void inicializar_lista(ListaProdutos *lista)
{
    lista->produtos = malloc(10 * sizeof(Produto *));
    lista->tamanho = 0;
    lista->capacidade = 10;
}

void adcionar_produto(ListaProdutos *lista, Produto *produto)
{
    if (lista->tamanho >= lista->capacidade)
    {
        lista->capacidade *= 2;
        lista->produtos = realloc(lista->produtos, lista->capacidade * sizeof(Produto *));
    }
    lista->produtos[lista->tamanho] = produto;
    lista->tamanho++;
}

void liberar_lista(ListaProdutos *lista)
{
    for (size_t i = 0; i < lista->tamanho; i++)
    {
        liberar_produto(lista->produtos[i]);
        free(lista->produtos[i]);
    }
    free(lista->produtos);
    lista->tamanho = 0;
    lista->capacidade = 0;
}