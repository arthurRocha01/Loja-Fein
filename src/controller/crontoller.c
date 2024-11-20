#include "controller/controller.h"

typedef enum {
    MENU,
    PRODUTO,
    CAIXA
} Sessao;

Sessao sessao_atual = MENU;
ListaProdutos *produtos;

static void gerenciar_menu();
static void gerenciar_caixa(Produto *produto);
static void escolher_produto();

static void alternar_sessao(Sessao nova_sessao, Produto *produto) {
    sessao_atual = nova_sessao;
    if (nova_sessao == MENU) gerenciar_menu();
    if (nova_sessao == PRODUTO) escolher_produto();
    if (nova_sessao == CAIXA) gerenciar_caixa(produto);
}

static int obter_opcao(const char *mensagem_aviso, int num_opcoes) {
    int opcao;
    while (1) {
        opcao = pegar_entrada();
        if (opcao > 0 && opcao <= num_opcoes) {
            return opcao;
        }
        mostrar_mensagem(mensagem_aviso);
    }
}

static void efetuar_compra(Produto *produto) {
    comprar_produto(produto);
    printf("Produto comprado com sucesso!\n");
    mostrar_compra(produto);
    alternar_sessao(MENU, NULL);
}

static void gerenciar_caixa(Produto *produto) {
    if (produto) {
    int opc = obter_opcao("\nOpção inválida. Tentenovamente.\nEscolha a opção: ", 2);
        if (opc == 1) efetuar_compra(produto);
        if (opc == 2) alternar_sessao(MENU, NULL);
    }
}

static void exibir_produto(Produto *produto) {
    if (produto == NULL) {
        mostrar_produto_nao_encontrado();
        alternar_sessao(MENU, NULL);
    }
    mostrar_produto(produto);
}

static void selecionar_produto() {
    mostrar_mensagem("Digite o ID do produto escolhido: ");
    int id = pegar_entrada();
    Produto *produto = pegar_produto(id, produtos);
    exibir_produto(produto);
    alternar_sessao(CAIXA, produto);
}

static void escolher_produto() {
    int opcao = obter_opcao("\nOpção inválida. Tentenovamente.\nEscolha a opção: ", 2);
    if (opcao == 1) selecionar_produto();
    else alternar_sessao(MENU, NULL);
}

static void selecionar_categoria(const char *categoria) {
    produtos = pegar_produtos_por_categoria(categoria);
    mostrar_categoria(produtos);
    alternar_sessao(PRODUTO, NULL);
}

static void sair() {
    mostrar_saida();
    terminar();
}

static void gerenciar_menu() {
    mostrar_menu();
    int opcao = obter_opcao("\nOpção inválida. Tentenovamente.\nEscolha a opção desejada: ", 5);
    switch (opcao) {
        case 1: selecionar_categoria("Camisa"); break;
        case 2: selecionar_categoria("Bermuda"); break;
        case 3: selecionar_categoria("Calçado"); break;
        case 4: selecionar_categoria("Acessório"); break;
        case 5: sair(); break;
    }
}

void iniciar() {
    carregar_banco_dados();
    alternar_sessao(MENU, NULL);
}