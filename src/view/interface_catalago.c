#include "view/interface_catalago.h"

void mostrar_categoria(ListaProdutos *lista) {
    limpar_terminal();
    imprimir_cabecalho("  PRODUTOS DISPONÍVEIS  ");
    printf("%sEscolha um produto pelo ID ou volte ao menu anterior.%s\n\n", BOLD, RESET);

    const int colunas = 2;
    for (size_t i = 0; i < lista->tamanho; i++) {
        Produto *produto = lista->produtos[i];
        if (i % colunas == 0) printf("\n");
        printf("%s+----------------------------+%s", LINHA_BORDA, RESET);
        printf("\n%sID:%s %-3d  %sNome:%s %-15s", BOLD, RESET, produto->id, BOLD, RESET, produto->nome);
        printf("\n%s+----------------------------+%s", LINHA_BORDA, RESET);
        if ((i + 1) % colunas != 0 && i != lista->tamanho - 1) {
            printf("%*s", ESPACO_COLUNA, "");
        }
    }
    mostrar_opcoes(0);
}

void mostrar_produto(Produto *produto) {
    limpar_terminal();
    imprimir_cabecalho("  DETALHES DO PRODUTO  ");
    printf("%sID:%s %d\n", BOLD, RESET, produto->id);
    printf("%sMarca:%s %s\n", BOLD, RESET, produto->marca);
    printf("%sNome:%s %s\n", BOLD, RESET, produto->nome);
    printf("%sCategoria:%s %s\n", BOLD, RESET, produto->categoria);
    printf("%sCor:%s %s\n", BOLD, RESET, produto->cor);
    printf("%sTamanho:%s %s\n", BOLD, RESET, produto->tamanhos);
    printf("%sPreço:%s R$ %.2f\n", BOLD, RESET, produto->valor);
    printf("%sQuantidade em estoque:%s %d\n", BOLD, RESET, produto->quantidade);
    congelar_tela(1.5);
    mostrar_opcoes(1);
}

void mostrar_produto_nao_encontrado() {
    limpar_terminal();
    imprimir_cabecalho("  PRODUTO NÃO ENCONTRADO  ");
    printf("%sNenhum produto encontrado com o ID informado.%s\n", RED, RESET);
    printf("%sPor favor, tente novamente ou escolha outro produto.%s\n", CYAN, RESET);
    congelar_tela(3);
}