#include "model/structs/cartao_credito_struct.h"

static void definir_atributos(CartaoCredito *cartao_credito, char *numero, char *nome, char *data_validade, char *cvv) {
    cartao_credito->numero = numero;
    cartao_credito->nome = nome;
    cartao_credito->data_validade = data_validade;
    cartao_credito->cvv = cvv;
}

CartaoCredito *criar_cartao_credito(char *numero, char *nome, char *data_validade, char *cvv) {
    CartaoCredito *cartao_credito = malloc(sizeof(CartaoCredito));
    definir_atributos(cartao_credito, numero, nome, data_validade, cvv);
    return cartao_credito;
}

void liberar_cartao_credito(CartaoCredito *cartao_credito) {
    free(cartao_credito->numero);
    free(cartao_credito->nome);
    free(cartao_credito->data_validade);
    free(cartao_credito->cvv);
    free(cartao_credito);
}