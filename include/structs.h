#ifndef STRUCTS_H
#define STRUCTS_H

#include <stddef.h>
#include <stdio.h>

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

typedef struct {
    Produto ***dados;
    int linhas;
    int colunas;
    int tamanho;
} TabelaProdutos;

typedef struct {
    Produto **produtos;
    size_t tamanho;
    size_t capacidade;
} ListaProdutos;

void inicializar_lista(ListaProdutos *lista);
void adcionar_produto(ListaProdutos *lista, Produto *produto);
void liberar_lista(ListaProdutos *lista);

Produto *criar_produto(char *info, int id);
TabelaProdutos* carregar_tabela_produtos(FILE *arquivo, int linhas, int colunas);

#endif