#include "controller/controlador_compra.h"

extern Produto *produto;
extern CartaoCredito *cartao;
extern float dinheiro_recebido;

static float calcular_troco() {
    float troco = dinheiro_recebido - produto->valor;
    return troco > 0 ? troco : 0;
}

static int solicitar_confirmacao(const char *mensagem) {
    mostrar_mensagem_opcoes(mensagem);
    return obter_opcao(2);
}

static void processar_pagamento_dinheiro() {
    if (dinheiro_recebido < produto->valor) {
        mostrar_dinheiro_insuficiente(produto);
        iniciar_controlador_loja();
        return;
    }
    float troco = calcular_troco();
    mostrar_confirmacao_pagamento_dinheiro(produto->valor, troco);
    if (solicitar_confirmacao("Deseja finalizar o pagamento? ") == 1) {
        comprar_produto(produto);
        mostrar_compra(produto);
    }
    iniciar_controlador_loja();
}

static void parcelar_compra() {
    int num_parcelas = obter_entrada_int("Digite o número de parcelas (máx. 6): ");
    if (num_parcelas < 1 || num_parcelas > 6) {
        printf("\n%sNúmero de parcelas inválido.%s\n", RED, RESET);
        return parcelar_compra();
    }
    float valor_parcela = produto->valor / num_parcelas;
    mostrar_confirmacao_compra_cartao(cartao, num_parcelas, valor_parcela);
    if (solicitar_confirmacao("Deseja confirmar a compra parcelada?") == 1) {
        comprar_produto(produto);
        mostrar_compra(produto);
    }
    iniciar_controlador_loja();
}

static void confirmar_pagamento(const char *forma_pagamento) {
    if (strcmp(forma_pagamento, "dinheiro") == 0) {
        processar_pagamento_dinheiro();
    } else if (strcmp(forma_pagamento, "debito") == 0) {
        mostrar_confirmacao_compra_cartao(cartao, 1, produto->valor);
        if (solicitar_confirmacao("Deseja confirmar o pagamento no débito?") == 1) {
            comprar_produto(produto);
            mostrar_compra(produto);
        }
    } else {
        parcelar_compra();
    }
    iniciar_controlador_loja();
}

void iniciar_controlador_compra(const char *forma_pagamento) {
    confirmar_pagamento(forma_pagamento);
}
