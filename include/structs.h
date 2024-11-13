#ifndef STRUCTS_H
#define STRUCTS_H

#include <stddef.h>

typedef struct {
    char **produtos;
    size_t tamanho;
    size_t capacidade;
} ListaProdutos;

void inicializar_lista(ListaProdutos *lista, size_t capacidade);
void adcionar_produto(ListaProdutos *lista, char *produto);
void liberar_lista(ListaProdutos *lista);

#endif