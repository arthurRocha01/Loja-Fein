#ifndef VIEW_H
#define VIEW_H

#include "model/manipulador_struct.h"
#include "view/view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void mostrar_menu();
void mostrar_mensagem(const char* mensagem);
void mostrar_produto(Produto *produto);
void mostrar_produto_nao_encontrado();
void mostrar_compra(Produto *produto);
void mostrar_categoria(ListaProdutos *lista);
void mostrar_saida();

#endif