#ifndef PRODUTO_STRUCT_H
#define PRODUTO_STRUCT_H

#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *marca;
    char *nome;
    char *categoria;
    char *cor;
    char *tamanhos;
    float valor;
    int quantidade;
} Produto;

Produto *criar_produto(char *linha, int id);
float liberar_produto(Produto *produto);

#endif