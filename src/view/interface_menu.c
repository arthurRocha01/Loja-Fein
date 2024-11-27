#include "view/interface_menu.h"

static void exibir_opcao(const char *descricao, const char *cor) {
    printf("%s%s%s\n", cor, descricao, RESET);
}

static void exibir_opcoes_menu() {
    exibir_opcao("[1] Camisas", GREEN);
    exibir_opcao("[2] Bermudas", GREEN);
    exibir_opcao("[3] Calçados", GREEN);
    exibir_opcao("[4] Acessórios", GREEN);
    exibir_opcao("[5] Sair", RED);
}

static void exibir_cabecalho_menu() {
    limpar_terminal();
    imprimir_cabecalho("  MENU PRINCIPAL  ");
    printf("%sEscolha uma opção:%s\n\n", BOLD, RESET);
}

void mostrar_menu() {
    exibir_cabecalho_menu();
    exibir_opcoes_menu();
    printf("\n%sDigite sua escolha: %s", CYAN, RESET);
}
