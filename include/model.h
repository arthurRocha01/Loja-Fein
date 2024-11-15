#ifndef MODEL_H
#define MODEL_H

#include "structs.h"

void limpar_terminal();
ListaProdutos pegar_produtos_por_categoria(const char *categoria);
int pegar_entrada();
int pegar_opcao();
Produto *buscar_produto(int id, ListaProdutos *produtos);
void terminar();

#endif