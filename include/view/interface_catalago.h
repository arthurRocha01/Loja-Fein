#ifndef INTERFACE_CATALAGO_H
#define INTERFACE_CATALAGO_H

#include "model/manipulador_struct.h"
#include "view/view_utils.h"
#include "view/cores.h"

void mostrar_categoria(ListaProdutos *lista);
void mostrar_produto(Produto *produto);
void mostrar_produto_nao_encontrado();

#endif