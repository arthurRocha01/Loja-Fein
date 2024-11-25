#ifndef INTERFACE_COMPRA_H
#define INTERFACE_COMPRA_H

#include "view/view_utils.h"

void mostrar_confirmacao_compra_cartao(CartaoCredito *cartao_credito);
void mostrar_confirmacao_pagamento_dinheiro(float valor_compra, float troco);
void mostrar_dinheiro_insuficiente(Produto *produto);

#endif