#include "controller/controlador_compra.h"

extern Produto *produto;
extern CartaoCredito *cartao;
extern float dinheiro_recebido;

static float calcular_troco() {
    float troco = dinheiro_recebido - produto->valor;
    return troco > 0 ? troco : 0;
}

static void processar_pagamento_dinheiro() {
    if (dinheiro_recebido < produto->valor) {
        mostrar_dinheiro_insuficiente(produto);
        iniciar_controlador_loja();
    }
    float troco = calcular_troco();
    mostrar_confirmacao_pagamento_dinheiro(produto->valor, troco);
    if (obter_opcao(2) == 1) return;
    else iniciar_controlador_loja();
}

static void confirmar_pagamento(const char *forma_pagamento) {
    if (strcmp(forma_pagamento, "dinheiro") == 0) {
        processar_pagamento_dinheiro();
    } else {
        mostrar_confirmacao_compra_cartao(cartao);
        if (obter_opcao(2) == 1) return;
        else iniciar_controlador_loja();
    }
}

void iniciar_controlador_compra(const char *forma_pagamento) {
    confirmar_pagamento(forma_pagamento);
}