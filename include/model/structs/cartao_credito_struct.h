#ifndef CARTAO_CREDITO_STRUCT_H
#define CARTAO_CREDITO_STRUCT_H

#include <stdlib.h>

typedef struct {
    char *numero;
    char *nome;
    char *data_validade;
    char *cvv;
    char *endereco;
} CartaoCredito;

CartaoCredito *criar_cartao_credito(char *numero, char *nome, char *data_validade, char *cvv);
void liberar_cartao_credito(CartaoCredito *cartao_credito);

#endif