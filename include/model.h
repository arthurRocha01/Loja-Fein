#ifndef MODEL_H
#define MODEL_H

#include "structs.h"

int pegar_entrada();
void inicializar_sgd();
ListaProdutos* pegar_produtos_por_categoria(const char *categoria);
Produto *buscar_produto(int id, ListaProdutos *produtos);
void comprar_produto(Produto *produto);
void terminar();

#endif