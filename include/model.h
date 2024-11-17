#ifndef MODEL_H
#define MODEL_H

#include "structs.h"

int pegar_entrada();
int pegar_opcao();
ListaProdutos* pegar_produtos_por_categoria(const char *categoria);
Produto *buscar_produto(int id, ListaProdutos *produtos);
void comprar_produto(Produto *produto);
void terminar();

#endif