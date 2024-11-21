#include "model/structs/lista_produtos_struct.h"

void inicializar_lista(ListaProdutos *lista) {
    lista->produtos = malloc(10 * sizeof(Produto *));
    lista->tamanho = 0;
    lista->capacidade = 10;
}

void adcionar_produto(ListaProdutos *lista, Produto *produto) {
    if (lista->tamanho >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->produtos = realloc(lista->produtos, lista->capacidade * sizeof(Produto *));
    }
    lista->produtos[lista->tamanho] = produto;
    lista->tamanho++;
}

void liberar_lista(ListaProdutos *lista) {
    for (size_t i = 0; i < lista->tamanho; i++) {
        liberar_produto(lista->produtos[i]);
        free(lista->produtos[i]);
    }
    free(lista->produtos);
    lista->tamanho = 0;
    lista->capacidade = 0;
}