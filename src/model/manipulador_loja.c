#include "model/manipulador_loja.h"

extern TabelaProdutos *tabela_produtos;

ListaProdutos* pegar_produtos_por_categoria(const char *categoria) {
    return  classificar_produtos_por_categoria(categoria);
}

Produto* pegar_produto(int id, ListaProdutos *produtos) {
    for (size_t i = 0; i < produtos->tamanho; i++) {
        Produto *produto_atual = produtos->produtos[i];
        if (produto_atual->id == id) return produto_atual;
    }
    return NULL;
}

static int verificar_igualdade_produtos(Produto *produto1, Produto *produto2) {
    if (produto1) {
        if (produto1->id == produto2->id) {
            return 1;
        }
    }
    return 0;
}

void comprar_produto(Produto *produto) {
    for (int i = 0; i < tabela_produtos->linhas; i++) {
        for (int j = 0; j < tabela_produtos->colunas; j++) {
            if (verificar_igualdade_produtos(tabela_produtos->dados[i][j], produto)) {
                tabela_produtos->dados[i][j]->quantidade -= 1;
            }
        }
    }
}

void terminar() {
    exit(EXIT_SUCCESS);
}