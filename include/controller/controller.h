#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/model.h"
#include "view/view.h"
#include "model/manipulador_struct.h"
#include <stdlib.h>

typedef enum {
    MENU,
    PRODUTO,
    CAIXA
} Sessao;

void iniciar();

#endif