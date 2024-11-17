#include "model.h"
#include "controller.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

FILE *arquivo;
TabelaProdutos *tabela_produtos;
ListaProdutos *lista_produtos;

void terminar() {
    printf("Obrigado por utilizar a Fein Store!\n");
    exit(EXIT_SUCCESS);
}

static FILE* carregar_arquivo(const char *caminho_arquivo) {
    arquivo = fopen(caminho_arquivo, "r");
}

static int verificar_categoria_correspondente(Produto *produto, const char *categoria) {
    if (strcmp(produto->categoria, categoria) == 0) return 1;
    else return 0;
}

static void adcionar_produto_a_lista(ListaProdutos *lista_produtos, Produto *produto, const char *categoria) {
    if (verificar_categoria_correspondente(produto, categoria)) {
        adcionar_produto(lista_produtos, produto);
    }
}

static void processar_produtos_banco_de_dados(TabelaProdutos *tabela_produtos, ListaProdutos *lista_produtos, FILE *arquivo, const char *categoria) {
    for (int i = 0; i < tabela_produtos->linhas; i++) {
        for (int j = 0; j < tabela_produtos->colunas; j++) {
            if (tabela_produtos->dados[i][j]) {
                Produto *produto = tabela_produtos->dados[i][j];
                adcionar_produto_a_lista(lista_produtos, produto, categoria);
            }
        }
    }
}

ListaProdutos* pegar_produtos_por_categoria(const char *categoria) {
    processar_produtos_banco_de_dados(tabela_produtos, lista_produtos, arquivo, categoria);
    return lista_produtos;
}

void inicializar_sgd() {
    carregar_arquivo("data/database.csv");
    lista_produtos = malloc(sizeof(lista_produtos));
    inicializar_lista(lista_produtos);
    tabela_produtos = carregar_tabela_produtos(arquivo, 10, 10);
    fclose(arquivo);
}

Produto* buscar_produto(int id, ListaProdutos *produtos) {
    for (size_t i = 0; i < produtos->tamanho; i++) {
        Produto *produto = produtos->produtos[i];
        if (produto->id == id) return produto;
    }
}

static int verificar_produto_correspondente(Produto *produto1, Produto *produto2) {
    if (produto1) {
        if (produto1->id == produto2->id) {
            return 1;
        }
    }
}

void comprar_produto(Produto *produto) {
    for (int i = 0; i < tabela_produtos->linhas; i++) {
        for (int j = 0; j < tabela_produtos->colunas; j++) {
            if (verificar_produto_correspondente(tabela_produtos->dados[i][j], produto)) {
                tabela_produtos->dados[i][j]->quantidade -= 1;
            }
        }
    }
}

int pegar_entrada() {
    int entrada;
    while (1) {
        if (scanf("%d", &entrada) == 1) return entrada;
        while (getchar() != '\n');
    }
}