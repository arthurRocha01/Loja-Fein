#include "model/manipulador_struct.h"

Produto *criar_produto(char *linha, int id);
float liberar_produto(Produto *produto);

TabelaProdutos *carregar_tabela_produtos(FILE *arquivo, int linhas, int colunas);

void inicializar_lista(ListaProdutos *lista);
void adcionar_produto(ListaProdutos *lista, Produto *produto);
void liberar_lista(ListaProdutos *lista);