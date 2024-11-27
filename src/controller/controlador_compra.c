#include "controller/controlador_compra.h"

extern Produto *produto;
extern CartaoCredito *cartao;
extern float dinheiro_recebido;

static float calcular_troco(float recebido, float preco) {
    return recebido > preco ? recebido - preco : 0;
}

static void exibir_mensagem_confirmacao(const char *mensagem) {
    mostrar_mensagem_opcoes(mensagem);
}

static void exibir_erro_dinheiro_insuficiente(Produto *produto) {
    mostrar_dinheiro_insuficiente(produto);
}

static int solicitar_confirmacao(const char *mensagem) {
    exibir_mensagem_confirmacao(mensagem);
    return obter_opcao(2);
}

static int validar_dinheiro_suficiente(float recebido, float preco) {
    return recebido >= preco;
}

static void finalizar_pagamento_dinheiro(float recebido, Produto *produto) {
    float troco = calcular_troco(recebido, produto->valor);
    mostrar_confirmacao_pagamento_dinheiro(produto->valor, troco);
    if (solicitar_confirmacao("Deseja finalizar o pagamento?") == 1) {
        comprar_produto(produto);
        mostrar_compra(produto);
    }
}

static void processar_pagamento_dinheiro() {
    if (!validar_dinheiro_suficiente(dinheiro_recebido, produto->valor)) {
        exibir_erro_dinheiro_insuficiente(produto);
        iniciar_controlador_loja();
        return;
    }
    finalizar_pagamento_dinheiro(dinheiro_recebido, produto);
    iniciar_controlador_loja();
}

static int obter_num_parcelas() {
    int parcelas = obter_entrada_int("Digite o número de parcelas (máx. 6): ");
    if (parcelas < 1 || parcelas > 6) {
        printf("\n%sNúmero de parcelas inválido.%s\n", RED, RESET);
        return obter_num_parcelas();
    }
    return parcelas;
}

static void finalizar_pagamento_parcelado(int parcelas, Produto *produto, CartaoCredito *cartao) {
    float valor_parcela = produto->valor / parcelas;
    mostrar_confirmacao_compra_cartao(cartao, parcelas, valor_parcela);
    if (solicitar_confirmacao("Deseja confirmar a compra parcelada?") == 1) {
        comprar_produto(produto);
        mostrar_compra(produto);
    }
}

static void processar_pagamento_cartao(const char *tipo_pagamento) {
    int parcelas = strcmp(tipo_pagamento, "debito") == 0 ? 1 : obter_num_parcelas();
    finalizar_pagamento_parcelado(parcelas, produto, cartao);
    iniciar_controlador_loja();
}

static void confirmar_pagamento(const char *forma_pagamento) {
    if (strcmp(forma_pagamento, "dinheiro") == 0) {
        processar_pagamento_dinheiro();
    } else {
        processar_pagamento_cartao(forma_pagamento);
    }
}

void iniciar_controlador_compra(const char *forma_pagamento) {
    confirmar_pagamento(forma_pagamento);
}
