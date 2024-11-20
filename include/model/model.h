#ifndef MODEL_H
#define MODEL_H

#include "model/structs.h"

void carregar_banco_dados();
int pegar_entrada();
ListaProdutos* pegar_produtos_por_categoria(const char *categoria);
Produto *pegar_produto(int id, ListaProdutos *produtos);
void comprar_produto(Produto *produto);
void terminar();

#endif