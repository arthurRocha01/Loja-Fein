#ifndef TABELA_PRODUTOS_STRUCT_H
#define TABELA_PRODUTOS_STRUCT_H

#include "model/produto_struct.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Produto ***dados;
    int linhas;
    int colunas;
    int tamanho;
} TabelaProdutos;

TabelaProdutos* carregar_tabela_produtos(FILE *arquivo, int linhas, int colunas);

#endif