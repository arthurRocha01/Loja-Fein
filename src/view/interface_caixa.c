#include "view/interface_caixa.h"

void mostrar_compra(Produto *produto) {
    limpar_terminal();
    imprimir_cabecalho("  COMPRA REALIZADA  ");
    printf("%s+--------------------------------------+%s\n", BG_GREEN, RESET);
    printf("| %sMarca:%s %-28s |\n", BOLD, RESET, produto->marca);
    printf("| %sNome:%s %-29s |\n", BOLD, RESET, produto->nome);
    printf("| %sCategoria:%s %-24s |\n", BOLD, RESET, produto->categoria);
    printf("| %sCor:%s %-30s |\n", BOLD, RESET, produto->cor);
    printf("| %sTamanho:%s %-26s |\n", BOLD, RESET, produto->tamanhos);
    printf("| %sPreço:%s R$ %-26.2f |\n", BOLD, RESET, produto->valor);
    printf("%s+--------------------------------------+%s\n\n", BG_GREEN, RESET);
    printf("%sObrigado por comprar com a FEIN!%s\n", CYAN, RESET);
    congelar_tela(2);
}