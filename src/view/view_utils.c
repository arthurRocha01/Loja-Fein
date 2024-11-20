#include "view/view_utils.h"

void limpar_terminal() {
    printf("\033[H\033[J");
}

void congelar_tela(float tempo) {
    sleep(tempo);
}

void imprimir_cabecalho(const char *titulo) {
    printf("\n%s%s+--------------------------------------+%s\n", LINHA_BORDA, BOLD, RESET);
    printf("%s%s|%s%-38s%s|%s\n", LINHA_BORDA, BOLD, RESET, titulo, BOLD, RESET);
    printf("%s%s+--------------------------------------+%s\n\n", LINHA_BORDA, BOLD, RESET);
}

void mostrar_opcoes(int tipo) {
    imprimir_cabecalho("  OPÇÕES  ");
    if (tipo == 0) printf("%s[1]%s Ver produto\n", GREEN, RESET);
    if (tipo == 1) printf("%s[1]%s Comprar\n", GREEN, RESET);
    printf("%s[2]%s Voltar\n", YELLOW, RESET);
    printf("\n%sEsolha a opção: %s", CYAN, RESET);
}