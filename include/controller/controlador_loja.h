#ifndef CONTROLADOR_LOJA_H
#define CONTROLADOR_LOJA_H

#include "controller/controlador_formas_pagamento.h"

typedef enum {
    MENU,
    PRODUTO,
    CAIXA
} Sessao;

void iniciar_controlador_loja();

#endif