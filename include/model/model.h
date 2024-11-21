#ifndef MODEL_H
#define MODEL_H

#include "model/manipulador_struct.h"
#include "model/data_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int pegar_entrada();
ListaProdutos* pegar_produtos_por_categoria(const char *categoria);
Produto *pegar_produto(int id, ListaProdutos *produtos);
void comprar_produto(Produto *produto);
void terminar();

#endif