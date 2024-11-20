#include "view/interface_menu.h"

void mostrar_menu() {
    limpar_terminal();
    imprimir_cabecalho("  MENU PRINCIPAL  ");
    printf("%sEscolha uma opção:%s\n\n", BOLD, RESET);
    printf("%s[1]%s Camisas\n", GREEN, RESET);
    printf("%s[2]%s Bermudas\n", GREEN, RESET);
    printf("%s[3]%s Calçados\n", GREEN, RESET);
    printf("%s[4]%s Acessórios\n", GREEN, RESET);
    printf("%s[5]%s Sair\n", RED, RESET);
    printf("\n%sDigite sua escolha: %s", CYAN, RESET);
}