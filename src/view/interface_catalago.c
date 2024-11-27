#include "view/interface_catalago.h"

static void exibir_produto(Produto *produto) {
    printf("%s+----------------------------+%s", LINHA_BORDA, RESET);
    printf("\n%sID:%s %-3d  %sNome:%s %-15s", BOLD, RESET, produto->id, BOLD, RESET, produto->nome);
    printf("\n%s+----------------------------+%s", LINHA_BORDA, RESET);
}

static void exibir_linha_produtos(ListaProdutos *lista, const int colunas) {
    for (size_t i = 0; i < lista->tamanho; i++) {
        if (i % colunas == 0) printf("\n"); // Quebra de linha
        exibir_produto(lista->produtos[i]); // Exibe o produto
        if ((i + 1) % colunas != 0 && i != lista->tamanho - 1) {
            printf("%*s", ESPACO_COLUNA, ""); // Espaçamento entre colunas
        }
    }
}

void mostrar_categoria(ListaProdutos *lista) {
    limpar_terminal();
    imprimir_cabecalho("  PRODUTOS DISPONÍVEIS  ");
    printf("%sEscolha um produto pelo ID ou volte ao menu anterior.%s\n\n", BOLD, RESET);
    exibir_linha_produtos(lista, 2);
    mostrar_opcoes(0);
}

static void exibir_atributo(const char *nome, const char *valor) {
    printf("%s%s:%s %s\n", BOLD, nome, RESET, valor);
}

void mostrar_produto(Produto *produto) {
    limpar_terminal();
    imprimir_cabecalho("  DETALHES DO PRODUTO  ");
    printf("%sID:%s %d\n", BOLD, RESET, produto->id);
    exibir_atributo("Marca", produto->marca);
    exibir_atributo("Nome", produto->nome);
    exibir_atributo("Categoria", produto->categoria);
    exibir_atributo("Cor", produto->cor);
    exibir_atributo("Tamanho", produto->tamanhos);
    printf("%sPreço:%s R$ %.2f\n", BOLD, RESET, produto->valor);
    printf("%sQuantidade em estoque:%s %d\n", BOLD, RESET, produto->quantidade);
    congelar_tela(1.5);
    mostrar_opcoes(1);
}

static void exibir_mensagem(const char *mensagem, const char *cor) {
    printf("%s%s%s\n", cor, mensagem, RESET);
}

void mostrar_produto_nao_encontrado() {
    limpar_terminal();
    imprimir_cabecalho("  PRODUTO NÃO ENCONTRADO  ");
    exibir_mensagem("Nenhum produto encontrado com o ID informado.", RED);
    exibir_mensagem("Por favor, tente novamente ou escolha outro produto.", CYAN);
    congelar_tela(3);
}