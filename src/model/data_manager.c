#include "model/data_manager.h"

FILE *arquivo;
TabelaProdutos *tabela_produtos;
ListaProdutos *lista_produtos;

static void carregar_arquivo(const char *caminho_arquivo) {
    arquivo = fopen(caminho_arquivo, "r");
}

void inicializar_sgd() {
    carregar_arquivo("data/database.csv");
    lista_produtos = malloc(sizeof(ListaProdutos));
    inicializar_lista(lista_produtos);
    tabela_produtos = carregar_tabela_produtos(arquivo, 10, 10);
    fclose(arquivo);
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

static void processar_produtos_banco_de_dados(TabelaProdutos *tabela_produtos, ListaProdutos *lista_produtos, const char *categoria) {
    for (int i = 0; i < tabela_produtos->linhas; i++) {
        for (int j = 0; j < tabela_produtos->colunas; j++) {
            if (tabela_produtos->dados[i][j]) {
                Produto *produto = tabela_produtos->dados[i][j];
                adcionar_produto_a_lista(lista_produtos, produto, categoria);
            }
        }
    }
}

ListaProdutos* classificar_produtos_por_categoria(const char *categoria) {
    processar_produtos_banco_de_dados(tabela_produtos, lista_produtos, categoria);
    return lista_produtos;
}