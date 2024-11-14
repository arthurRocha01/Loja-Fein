#ifndef MODEL_H
#define MODEL_H

#include "structs.h"

void limpar_terminal();
ListaProdutos pegar_produtos_por_categoria(const char *categoria);
int pegar_entrada_personalizada(const char *mensagem, int entradas_validas[], int num_entradas);
int pegar_entrada(const char *mensagem);
Produto *buscar_produto(int id, ListaProdutos *produtos);
void terminar();

#endif