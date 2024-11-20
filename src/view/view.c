#include "view/view.h"

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