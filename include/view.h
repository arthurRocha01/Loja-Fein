#ifndef VIEW_H
#define VIEW_H

#include "structs.h"

void mostrar_menu();
void mostrar_mensagem(const char* mensagem);
void mostrar_produto(Produto *produto);
void mostrar_produto_nao_encontrado();
void mostrar_compra(Produto *produto);
void mostrar_categoria(ListaProdutos *lista);
void mostrar_saida();

#endif