#include "model.h"
#include "controller.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void terminar() {
    printf("Obrigado por utilizar a Fein Store!\n");
    exit(EXIT_SUCCESS);
}

static FILE* carregar_arquivo(const char *caminho_arquivo) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    return arquivo;
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
            Produto *produto = tabela_produtos->dados[i][j];
            adcionar_produto_a_lista(lista_produtos, produto, categoria);
        }
    }
}

ListaProdutos pegar_produtos_por_categoria(TabelaProdutos *tabela_produtos, const char *categoria) {
    FILE *arquivo = carregar_arquivo("data/database.csv");
    ListaProdutos lista_produtos;
    inicializar_lista(&lista_produtos);

    TabelaProdutos *tabela_produtos = carregar_tabela_produtos(arquivo, 10, 10);
    processar_produtos_banco_de_dados(tabela_produtos, &lista_produtos, arquivo, categoria);

    fclose(arquivo);

    return lista_produtos;
}

static int pegar_entrada_personalizada(int entradas_validas[], int num_entradas) {
    int entrada;
    while (1) {
        if (scanf("%d", &entrada) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n');
            continue;
        }

        for (int i = 0; i < num_entradas; i++) {
            if (entrada == entradas_validas[i]) {
                return entrada;
            }
        }
        printf("Opção inválida. Tente novamente.\n");
    }
}

int pegar_opcao() {
    int opcoes[] = {1, 2};
    return pegar_entrada_personalizada(opcoes, sizeof(opcoes) / sizeof(opcoes[0]));
}

int pegar_entrada() {
    int entrada;
    while (1) {
        if (scanf("%d", &entrada) == 1) return entrada;
        printf("Entrada inválida. Por favor, insira um número.\n");
        while (getchar() != '\n');
    }
}

Produto *buscar_produto(int id, ListaProdutos *produtos) {
    for (size_t i = 0; i < produtos->tamanho; i++) {
        Produto *produto = produtos->produtos[i];
        if (produto->id == id) return produto;
    }
}