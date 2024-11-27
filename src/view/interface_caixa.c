#include "view/interface_caixa.h"

static void exibir_linha_produto(const char *nome_atributo, const char *valor_atributo) {
    printf("| %s%s:%s %-28s |\n", BOLD, nome_atributo, RESET, valor_atributo);
}

static void exibir_detalhes_produto(Produto *produto) {
    exibir_linha_produto("Marca", produto->marca);
    exibir_linha_produto("Nome", produto->nome);
    exibir_linha_produto("Categoria", produto->categoria);
    exibir_linha_produto("Cor", produto->cor);
    exibir_linha_produto("Tamanho", produto->tamanhos);
    printf("| %sPreço:%s R$ %-26.2f |\n", BOLD, RESET, produto->valor);
}

static void exibir_cabecalho_compra() {
    printf("%s+--------------------------------------+%s\n", BG_GREEN, RESET);
    printf("| %sCOMPRA REALIZADA%s |\n", BOLD, RESET);
    printf("%s+--------------------------------------+%s\n", BG_GREEN, RESET);
}

void mostrar_compra(Produto *produto) {
    limpar_terminal();
    exibir_cabecalho_compra();
    exibir_detalhes_produto(produto);
    printf("%s+--------------------------------------+%s\n\n", BG_GREEN, RESET);
    printf("%sObrigado por comprar com a FEIN!%s\n", CYAN, RESET);
    congelar_tela(2);
}
