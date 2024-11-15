#ifndef VIEW_H
#define VIEW_H

#include "structs.h"

void mostrar_menu();
void mostrar_produto(Produto *produto);
void mostrar_categoria(ListaProdutos *lista);
void mostrar_mensagem(const char *mensagem);
void mostrar_compra(const char *menssagem, Produto *produto);

#endif