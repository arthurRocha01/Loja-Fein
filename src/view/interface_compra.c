#include "view/interface_compra.h"

void mostrar_confirmacao_compra_cartao(CartaoCredito *cartao_credito, int num_parcelas, float valor_parcela) {
    limpar_terminal();
    imprimir_cabecalho("  CONFIRMAR COMPRA  ");
    mostrar_mensagem("Revise os detalhes do produto antes de confirmar a compra.");
    
    // Informações do cartão
    printf("\n\n%sNome do titular:%s %s\n", BOLD, RESET, cartao_credito->nome);
    printf("%sNúmero do cartão:%s %s\n", BOLD, RESET, cartao_credito->numero);
    printf("%sValidade do cartão:%s %s\n", BOLD, RESET, cartao_credito->data_validade);
    printf("%sCVV:%s %s\n", BOLD, RESET, cartao_credito->cvv);

    // Informações sobre o pagamento
    printf("\n%sDetalhes do pagamento:%s\n", BOLD, RESET);
    printf("%sNúmero de parcelas:%s %d\n", BOLD, RESET, num_parcelas);
    printf("%sValor de cada parcela:%s R$%.2f\n", BOLD, RESET, valor_parcela);

    // Confirmação da compra
    printf("\n%sDeseja confirmar a compra deste produto?%s\n", BOLD, RESET);
    printf("%s[1]%s Sim\n", GREEN, RESET);
    printf("%s[2]%s Não\n", RED, RESET);
    printf("\n%sEscolha sua opção: %s", CYAN, RESET);
}


void mostrar_confirmacao_pagamento_dinheiro(float valor_compra, float troco) {
    limpar_terminal();
    imprimir_cabecalho("  PAGAMENTO EM DINHEIRO  ");
    mostrar_mensagem("Insira o valor recebido e confira o troco.");
    
    printf("\n\n%sValor da compra:%s R$ %.2f\n", BOLD, RESET, valor_compra);
    if (troco) printf("%sTroco a ser devolvido:%s R$ %.2f\n", BOLD, RESET, troco);

    printf("\n%sDeseja finalizar o pagamento?%s\n", BOLD, RESET);
    printf("%s[1]%s Sim\n", GREEN, RESET);
    printf("%s[2]%s Não\n", RED, RESET);
    printf("\n%sEscolha sua opção: %s", CYAN, RESET);
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