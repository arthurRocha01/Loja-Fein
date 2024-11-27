#include "view/interface_formas_pagamento.h"

static void exibir_menu(const char *titulo, const char *opcoes[], int num_opcoes) {
    limpar_terminal();
    imprimir_cabecalho(titulo);
    for (int i = 0; i < num_opcoes; i++) {
        printf("%s[%d]%s %s\n", GREEN, i + 1, RESET, opcoes[i]);
    }
    printf("\n%sDigite sua escolha: %s", CYAN, RESET);
}

void mostrar_menu_pagamento() {
    const char *opcoes[] = {
        "Dinheiro",
        "Débito",
        "Crédito",
        "Voltar"
    };
    exibir_menu("  FORMAS DE PAGAMENTO  ", opcoes, 4);
}

void mostrar_opcao_pagamento(int tipo) {
    const char *opcoes[] = {
        "Confirmar pagamento",
        "Voltar"
    };
    const char *titulo = tipo == 0 ? "  CONFIRMAÇÃO DE PAGAMENTO  " : "  OPÇÕES DE PAGAMENTO  ";
    exibir_menu(titulo, opcoes, 2);
}

void mostrar_pagamento_confirmado(int sucesso) {
    limpar_terminal();
    imprimir_cabecalho("  PAGAMENTO REALIZADO  ");
    if (sucesso) {
        mostrar_mensagem("Pagamento realizado com sucesso!");
    } else {
        mostrar_mensagem("Pagamento não confirmado. Tente novamente.");
    }
    mostrar_mensagem("Obrigado por escolher a FEIN Store!");
    congelar_tela(2);
}