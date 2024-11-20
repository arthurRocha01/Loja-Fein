#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "model/manipulador_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaProdutos* classificar_produtos_por_categoria(const char *categoria);
void inicializar_sgd();

#endif