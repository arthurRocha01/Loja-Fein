#include "view/interface_compra.h"

static void imprimir_detalhe(const char *descricao, const char *valor) {
    printf("%s%s:%s %s\n", BOLD, descricao, RESET, valor);
}

void mostrar_mensagem_opcoes(const char *mensagem) {
    printf("\n%s%s%s\n", BOLD, mensagem, RESET);
    printf("%s[1]%s Sim\n", GREEN, RESET);
    printf("%s[2]%s Não\n", RED, RESET);
    printf("\n%sEscolha sua opção: %s", CYAN, RESET);
}

void mostrar_confirmacao_compra_cartao(CartaoCredito *cartao_credito, int num_parcelas, float valor_parcela) {
    limpar_terminal();
    imprimir_cabecalho("  CONFIRMAR COMPRA  ");
    mostrar_mensagem("Revise os detalhes do produto antes de confirmar a compra.");
    
    imprimir_detalhe("\nNome do titular", cartao_credito->nome);
    imprimir_detalhe("Número do cartão", cartao_credito->numero);
    imprimir_detalhe("Validade do cartão", cartao_credito->data_validade);
    imprimir_detalhe("CVV", cartao_credito->cvv);

    printf("\n%sDetalhes do pagamento:%s\n", BOLD, RESET);
    printf("%sNúmero de parcelas:%s %d\n", BOLD, RESET, num_parcelas);
    if (num_parcelas > 1)
        printf("%sValor de cada parcela:%s R$ %.2f\n", BOLD, RESET, valor_parcela);
}


void mostrar_confirmacao_pagamento_dinheiro(float valor_compra, float troco) {
    limpar_terminal();
    imprimir_cabecalho("  PAGAMENTO EM DINHEIRO  ");
    mostrar_mensagem("Insira o valor recebido e confira o troco.");

    printf("\n%sValor da compra:%s R$ %.2f\n", BOLD, RESET, valor_compra);
    if (troco)
        printf("%sTroco a ser devolvido:%s R$ %.2f\n", BOLD, RESET, troco);
}

void mostrar_dinheiro_insuficiente(Produto *produto) {
    limpar_terminal();
    imprimir_cabecalho("  DINHEIRO INSUFICIENTE  ");
    printf("%s+--------------------------------------+%s\n", BG_RED, RESET);
    printf("| %sVocê não possui saldo suficiente para %s|\n", BOLD, RESET);
    printf("| %scomprar o produto abaixo:            %s|\n", BOLD, RESET);
    printf("%s+--------------------------------------+%s\n", BG_RED, RESET);
    printf("| %sMarca:%s %-28s |\n", BOLD, RESET, produto->marca);
    printf("| %sNome:%s %-29s |\n", BOLD, RESET, produto->nome);
    printf("| %sPreço:%s R$ %-26.2f |\n", BOLD, RESET, produto->valor);
    printf("%s+--------------------------------------+%s\n\n", BG_RED, RESET);
    printf("%sPor favor, verifique seu saldo e tente novamente.%s\n", CYAN, RESET);
    congelar_tela(3);
}