#include "model/structs/tabela_produtos_struct.h"

static void preencher_tabela_produtos(TabelaProdutos *tabela, FILE *arquivo) {
    char buffer[100];
    int id = 0;

    for (int i = 0; i < tabela->linhas; i++) {
        for (int j = 0; j < tabela->colunas; j++) {
            if (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
                Produto *produto = criar_produto(buffer, id++);
                tabela->dados[i][j] = produto;
                tabela->tamanho++;
            }
        }
    }
}

static TabelaProdutos* montar_tabela_produtos(int linhas, int colunas) {
    TabelaProdutos *tabela = malloc(sizeof(TabelaProdutos));
    tabela->dados = malloc(linhas * sizeof(Produto**));
    tabela->linhas = linhas;
    tabela->colunas = colunas;
    tabela->tamanho = 0;

    for (int i = 0; i < linhas; i++) {
        tabela->dados[i] = malloc(colunas *sizeof(Produto*));
        for (int j = 0; j < colunas; j++) {
            tabela->dados[i][j] = NULL;
        }
    }
    return tabela;
}

TabelaProdutos* carregar_tabela_produtos(FILE *arquivo, int linhas, int colunas) {
    TabelaProdutos *tabela = montar_tabela_produtos(linhas, colunas);
    preencher_tabela_produtos(tabela, arquivo);
    return tabela;
}