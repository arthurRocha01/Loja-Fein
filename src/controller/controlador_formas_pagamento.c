#include "controller/controlador_formas_pagamento.h"

extern Produto *produto;
CartaoCredito *cartao;
float dinheiro_recebido;

static char *obter_info_cartao(const char *mensagem) {
    return obter_entrada(mensagem);
}

static float solicitar_valor_pagamento() {
    return obter_entrada_float("Digite o valor do pagamento: ");
}

static void preencher_dados_cartao(char *infos[]) {
    const char *dados_cartao[] = {
        "Nome do titular: ",
        "Número do cartão: ",
        "Data Validade: ",
        "CVV: "
    };
    for (int i = 0; i < 4; i++) {
        infos[i] = obter_info_cartao(dados_cartao[i]);
    }
}

static int criar_e_validar_cartao() {
    char *infos[4] = {NULL, NULL, NULL, NULL};
    preencher_dados_cartao(infos);
    cartao = criar_cartao_credito(infos[0], infos[1], infos[2], infos[3]);
    return cartao != NULL;
}

static void processar_pagamento_dinheiro() {
    dinheiro_recebido = solicitar_valor_pagamento("Digite o valor a ser pago: ");
    iniciar_controlador_compra("dinheiro");
}

static void processar_pagamento_cartao(const char *forma_pagamento) {
    if (criar_e_validar_cartao()) {
        iniciar_controlador_compra(forma_pagamento);
    } else {
        printf("\n%sErro ao processar o cartão. Tente novamente.%s\n", RED, RESET);
    }
}

static void executar_opcao_pagamento(int opcao) {
    switch (opcao) {
        case 1: processar_pagamento_dinheiro(); break;
        case 2: processar_pagamento_cartao("debito"); break;
        case 3: processar_pagamento_cartao("credito"); break;
        case 4: return;
    }
}

static void exibir_menu_pagamento() {
    mostrar_menu_pagamento();
    int opcao = obter_opcao(4);
    executar_opcao_pagamento(opcao);
}

void iniciar_formas_pagamento() {
    exibir_menu_pagamento();
}