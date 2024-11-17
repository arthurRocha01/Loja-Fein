#ifndef MODEL_H
#define MODEL_H

#include "structs.h"

ListaProdutos pegar_produtos_por_categoria(TabelaProdutos *tabela_produtos, const char *categoria);
int pegar_entrada();
int pegar_opcao();
Produto *buscar_produto(int id, ListaProdutos *produtos);
void terminar();

#endif