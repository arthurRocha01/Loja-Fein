#include "model/manipulador_formas_pagamento.h"

CartaoCredito *cartao_credito;

static void mostrar_infos_cartao(CartaoCredito *cartao_credito) {
    printf("\nNome do titular: %s\n", cartao_credito->nome);
    printf("Número do cartão: %s\n", cartao_credito->numero);
    printf("Validade do cartão: %s\n", cartao_credito->data_validade);
    printf("CVV: %s\n", cartao_credito->cvv);
}

static void preencher_infos_cartao(char **infos) {
    cartao_credito = criar_cartao_credito(
        infos[0], infos[1], infos[2], infos[3]
    );
}

static void preencher_cartao(int tipo_info, char **infos) {
    switch (tipo_info) {
        case 0: infos[0] = obter_entrada("Nome do titular: "); break;
        case 1: infos[1] = obter_entrada("Número do cartão: "); break;
        case 2: infos[2] = obter_entrada("Validade do cartão: "); break;
        case 3: infos[3] = obter_entrada("CVV: "); break;
    }
    preencher_infos_cartao(infos);
}

static void pagar_com_credito() {
    char *infos[4] = {NULL, NULL, NULL, NULL};
    for (int i = 0; i < 4; i++) {
        preencher_cartao(i, infos);
    }
    preencher_infos_cartao(infos);
    mostrar_infos_cartao(cartao_credito);
}

static void gerenciar_menu() {
    mostrar_menu_pagamento();
    int opcao = obter_opcao(4);
    switch (opcao) {
        case 1: pagar_com_credito(); break;
    }
}

void iniciar_formas_pagamento() {
    gerenciar_menu();
}