#include "controller/controlador_formas_pagamento.h"

extern Produto *produto;
CartaoCredito *cartao;
float dinheiro_recebido;

static void preencher_infos_cartao() {
    const char *dados_cartao[] = {
        "Nome do titular: ",
        "Número do cartão: ",
        "Data Validade: ",
        "CVV: "
    };
    char *infos[] = {NULL, NULL, NULL, NULL};
    for (int i = 0; i < 4; i++) {
        infos[i] = obter_entrada(dados_cartao[i]);
    }
    cartao = criar_cartao_credito(infos[0], infos[1], infos[2], infos[3]);
}

static void pagar_com_cartao(const char *forma_pagamento) {
    preencher_infos_cartao();
    if (cartao) {
        iniciar_controlador_compra(forma_pagamento);
    }
}

static void pagar_com_dinheiro() {
    dinheiro_recebido = obter_entrada_float("Digite o valor a ser pago: ");
    iniciar_controlador_compra("dinheiro");
}

static void gerenciar_menu() {
    mostrar_menu_pagamento();
    int opcao = obter_opcao(4);
    switch (opcao) {
        case 1: pagar_com_dinheiro(); break;
        case 2: pagar_com_cartao("debito"); break;
        case 3: pagar_com_cartao("credito"); break;
        case 4: return;
    }
}

void iniciar_formas_pagamento() {
    gerenciar_menu();
}