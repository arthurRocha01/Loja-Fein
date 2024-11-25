#include "view/interface_formas_pagamento.h"

void mostrar_menu_pagamento() {
    limpar_terminal();
    imprimir_cabecalho("  FORMAS DE PAGAMENTO  ");
    printf("%sEscolha uma forma de pagamento:%s\n\n", BOLD, RESET);
    printf("%s[1]%s Dinheiro\n", GREEN, RESET);
    printf("%s[2]%s Débito\n", GREEN, RESET);
    printf("%s[3]%s Crédito\n", GREEN, RESET);
    printf("%s[4]%s Voltar\n", YELLOW, RESET);
    printf("\n%sDigite sua escolha: %s", CYAN, RESET);
}

void mostrar_opcao_pagamento(int tipo) {
    limpar_terminal();
    imprimir_cabecalho("  OPÇÕES DE PAGAMENTO  ");
    if (tipo == 0) {
        printf("%s[1]%s Confirmar pagamento\n", GREEN, RESET);
    }
    printf("%s[2]%s Voltar\n", YELLOW, RESET);
    printf("\n%sEscolha a opção: %s", CYAN, RESET);
}

void mostrar_pagamento_confirmado(int tipo) {
    limpar_terminal();
    imprimir_cabecalho("  PAGAMENTO REALIZADO  ");
    if (tipo == 0) {
        mostrar_mensagem("Pagamento realizado com sucesso!");
    } else {
        mostrar_mensagem("Pagamento não confirmado. Tente novamente.");
    }
    mostrar_mensagem("Obrigado por escolher a FEIN Store!");
    congelar_tela(2);
}
