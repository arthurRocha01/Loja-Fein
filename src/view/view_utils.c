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

void mostrar_mensagem(const char* mensagem) {
    printf("%s", CYAN);
    printf("%s", mensagem);
    printf("%s", RESET);
}

void mostrar_saida() {
    limpar_terminal();
    imprimir_cabecalho("  SAÍDA  ");
    printf("%s+--------------------------------------+%s\n", BG_BLUE, RESET);
    printf("| %sObrigado por usar a FEIN Store!    %s|\n", BOLD, RESET);
    printf("| %sAté logo!                         %s|\n", BOLD, RESET);
    printf("%s+--------------------------------------+%s\n\n", BG_BLUE, RESET);
    congelar_tela(1);
}
