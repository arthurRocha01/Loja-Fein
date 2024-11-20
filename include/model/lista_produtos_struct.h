#ifndef LISTA_PRODUTOS_STRUCT_H
#define LISTA_PRODUTOS_STRUCT_H

#include "model/produto_struct.h"
#include <stdlib.h>

typedef struct {
    Produto **produtos;
    size_t tamanho;
    size_t capacidade;
} ListaProdutos;

void inicializar_lista(ListaProdutos *lista);
void adcionar_produto(ListaProdutos *lista, Produto *produto);
void liberar_lista(ListaProdutos *lista);

#endif