#ifndef VIEW_H
#define VIEW_H

#include "structs.h"

void imprimir_menu();
void imprimir_opcaos_produto();
void imprimir_produto(Produto *produto);
void imprimir_produtos(ListaProdutos *lista);
void imprimir_compra(const char *menssagem, Produto *produto);

#endif